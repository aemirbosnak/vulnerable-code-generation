//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

int is_virus(char *file_content, int file_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    int i, j;

    for (i = 0; i < file_size - VIRUS_SIGNATURE_LENGTH; i++) {
        for (j = 0; j < VIRUS_SIGNATURE_LENGTH; j++) {
            if (tolower(file_content[i + j])!= tolower(virus_signature[j])) {
                break;
            }
        }
        if (j == VIRUS_SIGNATURE_LENGTH) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char file_path[256];
    strcpy(file_path, argv[1]);

    int file_size;
    char *file_content = NULL;

    FILE *fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds limit.\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);
    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(fp);
        return 1;
    }

    fread(file_content, file_size, 1, fp);
    fclose(fp);

    int is_infected = is_virus(file_content, file_size);

    if (is_infected) {
        printf("Virus found!\n");
    } else {
        printf("No virus found.\n");
    }

    free(file_content);
    return 0;
}