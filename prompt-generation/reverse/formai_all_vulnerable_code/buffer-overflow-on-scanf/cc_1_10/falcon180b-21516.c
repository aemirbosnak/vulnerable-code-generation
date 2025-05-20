//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1048576 // 1 MB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

int is_file_infected(FILE *file) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    int i = 0;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            if (tolower(buffer[i]) == VIRUS_SIGNATURE[i % VIRUS_SIGNATURE_LENGTH]) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char file_path[100];
    char mode;
    FILE *file;

    printf("Enter file path: ");
    scanf("%s", file_path);

    printf("Enter mode (r for read, w for write): ");
    scanf(" %c", &mode);

    file = fopen(file_path, mode);

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (mode == 'r') {
        if (is_file_infected(file)) {
            printf("File is infected with a virus.\n");
        } else {
            printf("File is clean.\n");
        }
    } else if (mode == 'w') {
        printf("Cannot write to file.\n");
    } else {
        printf("Invalid mode.\n");
    }

    fclose(file);

    return 0;
}