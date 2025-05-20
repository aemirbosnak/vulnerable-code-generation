//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_LENGTH 1000
#define MAX_FILE_LENGTH 1000000

char* viruses[] = {"virus1", "virus2", "virus3", "virus4", "virus5"};
int num_viruses = sizeof(viruses) / sizeof(viruses[0]);

void scan_file(FILE* file, char* filename) {
    char buffer[MAX_FILE_LENGTH];
    int buffer_length = 0;
    int virus_found = 0;

    while (fread(buffer + buffer_length, 1, MAX_FILE_LENGTH - buffer_length, file) > 0) {
        buffer_length += fread(buffer + buffer_length, 1, MAX_FILE_LENGTH - buffer_length, file);
    }

    for (int i = 0; i < num_viruses; i++) {
        if (strstr(buffer, viruses[i])) {
            printf("Virus found in file %s: %s\n", filename, viruses[i]);
            virus_found = 1;
            break;
        }
    }

    if (!virus_found) {
        printf("File %s is clean.\n", filename);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: could not open file %s.\n", argv[1]);
        return 1;
    }

    char filename[MAX_FILE_LENGTH];
    strcpy(filename, argv[1]);
    scan_file(file, filename);

    fclose(file);
    return 0;
}