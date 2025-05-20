//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void fatal(const char* msg) {
    fprintf(stderr, "Fatal: %s\n", msg);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file> <operation>\n", argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    char* destination_file = argv[2];
    char* operation = argv[3];

    FILE* source = fopen(source_file, "rb");
    if (source == NULL) {
        fatal("Could not open source file");
    }

    FILE* destination = fopen(destination_file, "wb");
    if (destination == NULL) {
        fatal("Could not open destination file");
    }

    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;

    if (strcmp(operation, "copy") == 0) {
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
            fwrite(buffer, 1, bytes_read, destination);
        }
    } else if (strcmp(operation, "move") == 0) {
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
            fwrite(buffer, 1, bytes_read, destination);
            fseek(source, -bytes_read, SEEK_CUR);
        }
        fclose(source);
        rename(destination_file, source_file);
    } else {
        fatal("Invalid operation");
    }

    fclose(destination);
    return 0;
}