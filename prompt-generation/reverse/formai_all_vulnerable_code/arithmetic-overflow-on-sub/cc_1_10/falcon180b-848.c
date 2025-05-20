//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000
#define MAX_VIRUS_COUNT 100
#define MAX_VIRUS_NAME_LENGTH 50

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_NAME_LENGTH];
} Virus;

Virus viruses[MAX_VIRUS_COUNT];
int virus_count = 0;

void add_virus(char* name, char* signature) {
    strcpy(viruses[virus_count].name, name);
    strcpy(viruses[virus_count].signature, signature);
    virus_count++;
}

int scan_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    int file_size = 0;
    char buffer[MAX_FILE_SIZE];
    while (fread(buffer, 1, MAX_FILE_SIZE, file) > 0) {
        file_size += fread(buffer, 1, MAX_FILE_SIZE, file);
    }

    fclose(file);

    for (int i = 0; i < virus_count; i++) {
        int signature_size = strlen(viruses[i].signature);
        int buffer_size = file_size - signature_size;
        int buffer_offset = 0;

        while (buffer_offset < buffer_size) {
            int j = 0;
            while (j < signature_size && buffer[buffer_offset + j] == viruses[i].signature[j]) {
                j++;
            }

            if (j == signature_size) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }

            buffer_offset++;
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    time_t start_time = time(NULL);
    int result = scan_file(argv[1]);
    time_t end_time = time(NULL);

    if (result == 0) {
        printf("File is clean.\n");
    }

    printf("Scan finished in %ld seconds.\n", end_time - start_time);

    return result;
}