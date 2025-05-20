//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "VIRUS"
#define INFECTED_FILE "INFECTED"
#define CLEAN_FILE "CLEAN"
#define FILE_SIZE 1024

void scan_file(char *filename, char *signature) {
    FILE *file;
    char buffer[FILE_SIZE];
    int matches = 0;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    while (fread(buffer, 1, FILE_SIZE, file) > 0) {
        int i;
        for (i = 0; i < strlen(signature); i++) {
            if (strstr(buffer, signature + i)!= NULL) {
                matches++;
                break;
            }
        }
        if (matches > 0) {
            break;
        }
    }

    if (matches > 0) {
        printf("File %s is infected with the %s virus.\n", filename, signature);
        rename(filename, INFECTED_FILE);
    } else {
        printf("File %s is clean.\n", filename);
        rename(filename, CLEAN_FILE);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[256] = {0};
    strcpy(filename, argv[1]);

    char *ext = strrchr(filename, '.');
    if (ext == NULL) {
        printf("Error: invalid file extension.\n");
        return 1;
    }

    if (strcmp(ext, ".exe") == 0 || strcmp(ext, ".dll") == 0) {
        scan_file(filename, VIRUS_SIGNATURE);
    } else {
        printf("File %s is not executable and cannot be infected with viruses.\n", filename);
    }

    return 0;
}