//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void extract_metadata(FILE *file, char *filename, char *metadata_type) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int found = 0;

    do {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
        if (bytes_read == 0) {
            break;
        }
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                if (found) {
                    break;
                }
            } else if (buffer[i] == ':') {
                found = 1;
            }
        }
    } while (!found);

    if (found) {
        char *value;
        int value_size;
        char *line = strtok(buffer, "\n");
        char *token = strtok(line, ":");
        while (token!= NULL) {
            if (strcmp(token, metadata_type) == 0) {
                value = strtok(NULL, "\n");
                value_size = strlen(value);
                printf("%s: %.*s\n", metadata_type, value_size, value);
                break;
            }
            token = strtok(NULL, ":");
        }
    } else {
        printf("%s not found\n", metadata_type);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <metadata_type> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char *metadata_type = argv[2];
    FILE *output_file = fopen(argv[3], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file %s\n", argv[3]);
        fclose(file);
        return 1;
    }

    extract_metadata(file, argv[1], metadata_type);

    fclose(file);
    fclose(output_file);

    return 0;
}