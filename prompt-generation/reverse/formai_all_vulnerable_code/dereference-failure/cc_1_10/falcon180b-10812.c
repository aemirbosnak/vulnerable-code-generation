//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define VIRUS_SIGNATURE "ThisIsAVirus"

void scan_file(FILE *file, char *filename) {
    char buffer[1024];
    int file_size = 0;
    int virus_found = 0;

    while (fread(buffer, sizeof(char), sizeof(buffer), file) > 0) {
        file_size += sizeof(buffer);

        if (strstr(buffer, VIRUS_SIGNATURE)!= NULL) {
            virus_found = 1;
            break;
        }
    }

    if (virus_found) {
        printf("Virus found in file %s\n", filename);
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
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char filename[256];
    strcpy(filename, argv[1]);

    scan_file(file, filename);

    fclose(file);

    return 0;
}