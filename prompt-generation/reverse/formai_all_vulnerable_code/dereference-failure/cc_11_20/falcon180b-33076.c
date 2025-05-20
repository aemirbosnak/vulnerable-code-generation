//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define VIRUS_SIGNATURE "This is a virus"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(1);
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }

    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (bytes_read == 0) {
        printf("Error: Could not read file %s\n", argv[1]);
        exit(1);
    }

    int virus_found = 0;
    for (int i = 0; i < bytes_read; i++) {
        if (buffer[i] == VIRUS_SIGNATURE[0]) {
            int j;
            for (j = 0; j < strlen(VIRUS_SIGNATURE) && i + j < bytes_read; j++) {
                if (buffer[i + j]!= VIRUS_SIGNATURE[j]) {
                    break;
                }
            }
            if (j == strlen(VIRUS_SIGNATURE)) {
                virus_found = 1;
                break;
            }
        }
    }

    if (virus_found) {
        printf("Virus found in file %s\n", argv[1]);
    } else {
        printf("File %s is clean\n", argv[1]);
    }

    free(buffer);
    fclose(file);

    return 0;
}