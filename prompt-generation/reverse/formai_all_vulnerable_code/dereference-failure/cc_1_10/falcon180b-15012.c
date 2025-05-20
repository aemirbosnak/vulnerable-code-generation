//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define VIRUS_SIGNATURE "This is a virus"
#define VIRUS_SIGNATURE_LEN strlen(VIRUS_SIGNATURE)

bool is_virus(FILE* file) {
    char buffer[MAX_LINE_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_LINE_SIZE, file))!= 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (tolower(buffer[i]) == VIRUS_SIGNATURE[i % VIRUS_SIGNATURE_LEN]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char file_name[MAX_LINE_SIZE];
    printf("Enter file name: ");
    fgets(file_name, MAX_LINE_SIZE, stdin);
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }
    struct stat file_stat;
    if (fstat(fileno(file), &file_stat)!= 0) {
        printf("Error getting file size: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }
    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File is too large\n");
        fclose(file);
        return 1;
    }
    if (is_virus(file)) {
        printf("Virus found\n");
    } else {
        printf("No virus found\n");
    }
    fclose(file);
    return 0;
}