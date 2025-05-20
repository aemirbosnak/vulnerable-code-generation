//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t line_size = 0;
    metadata_t metadata;
    int in_metadata = 0;
    int key_index = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &line_size, file))!= -1) {
        if (in_metadata) {
            if (key_index >= MAX_KEY_LENGTH - 1) {
                fprintf(stderr, "Error: metadata key too long.\n");
                fclose(file);
                return 1;
            }

            char *token = strtok(line, "=");
            if (token == NULL) {
                fprintf(stderr, "Error: missing metadata value.\n");
                fclose(file);
                return 1;
            }

            strcpy(metadata.key + key_index, token);
            strcpy(metadata.value, strtok(NULL, " \t\r\n"));
            in_metadata = 0;
        } else {
            if (strncmp(line, "<!-- metadata -->", 15) == 0) {
                in_metadata = 1;
                key_index = 0;
            } else if (strncmp(line, "<!-- end metadata -->", 18) == 0) {
                in_metadata = 0;
                printf("Metadata:\n");
                printf("  Key: %s\n", metadata.key);
                printf("  Value: %s\n", metadata.value);
                metadata.key[0] = '\0';
                metadata.value[0] = '\0';
            }
        }
    }

    fclose(file);

    return 0;
}