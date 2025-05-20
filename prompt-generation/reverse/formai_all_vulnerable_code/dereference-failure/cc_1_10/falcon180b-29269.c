//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FILES 100

typedef struct {
    char filename[MAX_LINE_LENGTH];
    unsigned char checksum[16];
} file_t;

void calculate_checksum(char* filename, unsigned char checksum[16]) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char buffer[file_size];
    fread(buffer, file_size, 1, file);
    fclose(file);

    int i;
    for (i = 0; i < file_size; i++) {
        checksum[i % 16] ^= buffer[i];
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file_t files[MAX_NUM_FILES];
    int num_files = 0;

    while (num_files < MAX_NUM_FILES && argc > 1) {
        strcpy(files[num_files].filename, argv[1]);
        calculate_checksum(files[num_files].filename, files[num_files].checksum);
        num_files++;
        argv++;
        argc--;
    }

    printf("Filename\tChecksum\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t", files[i].filename);
        for (int j = 0; j < 16; j++) {
            printf("%02X ", files[i].checksum[j]);
        }
        printf("\n");
    }

    return 0;
}