//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_VIRUS_SIZE 1024
#define VIRUS_SIGNATURE "I am a virus!"

// Function to read file into memory
void read_file(FILE *file, char *buffer) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        exit(1);
    }

    fread(buffer, file_size, 1, file);
}

// Function to scan for viruses
int scan_virus(char *buffer, int buffer_size) {
    int i;
    for (i = 0; i < buffer_size - MAX_VIRUS_SIZE; i++) {
        if (memcmp(buffer + i, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
            printf("Virus found at offset %d.\n", i);
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    read_file(file, buffer);
    int virus_found = scan_virus(buffer, strlen(buffer));

    fclose(file);
    return virus_found;
}