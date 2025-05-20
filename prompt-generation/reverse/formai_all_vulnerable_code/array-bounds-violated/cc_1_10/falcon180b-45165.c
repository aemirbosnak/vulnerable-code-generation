//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB
#define VIRUS_SIGNATURE "EvilVirus"

int is_virus(char* buffer) {
    int i;
    for (i = 0; i < strlen(buffer); i++) {
        if (tolower(buffer[i]) == VIRUS_SIGNATURE[i]) {
            return 1;
        }
    }
    return 0;
}

void scan_file(FILE* file, char* filename) {
    char buffer[1024];
    int bytes_read;
    int total_bytes_read = 0;
    int virus_found = 0;

    while ((bytes_read = fread(buffer, 1, 1024, file)) > 0) {
        total_bytes_read += bytes_read;
        if (total_bytes_read > MAX_FILE_SIZE) {
            printf("File %s is too large to scan.\n", filename);
            exit(1);
        }

        if (is_virus(buffer)) {
            virus_found = 1;
            break;
        }
    }

    if (virus_found) {
        printf("Virus found in file %s!\n", filename);
    } else {
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
        printf("Error opening file %s.\n", argv[1]);
        return 1;
    }

    scan_file(file, argv[1]);

    fclose(file);
    return 0;
}