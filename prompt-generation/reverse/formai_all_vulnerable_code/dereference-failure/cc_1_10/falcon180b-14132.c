//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define VIRUS_SIGNATURE "Happy Virus"
#define VIRUS_LENGTH 11

// Function to scan for virus
void scan_file(FILE *file, char *filename) {
    char buffer[MAX_FILE_SIZE];
    int file_size = 0;
    int virus_count = 0;

    while (fread(buffer, sizeof(char), MAX_FILE_SIZE, file) > 0) {
        file_size += strlen(buffer);

        if (strstr(buffer, VIRUS_SIGNATURE)!= NULL) {
            virus_count++;
        }
    }

    if (virus_count > 0) {
        printf("Virus detected in file %s\n", filename);
    } else {
        printf("File %s is clean\n", filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char filename[strlen(argv[1])];
    strcpy(filename, argv[1]);

    scan_file(file, filename);

    fclose(file);

    return 0;
}