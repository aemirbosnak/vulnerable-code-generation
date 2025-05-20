//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char type[20];
    int line_number;
} Metadata;

void extract_metadata(char *file_path, Metadata *metadata, int *num_metadata) {
    FILE *file = fopen(file_path, "r");
    char line[1024];
    char token[100];
    int in_function = 0;
    int num_lines = 1;

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_path);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%s", token, token + strlen(token));

        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0) {
            if (in_function) {
                strcpy(metadata[*num_metadata].type, token);
                metadata[*num_metadata].line_number = num_lines;
                (*num_metadata)++;
            }
        }

        if (strcmp(token, "void") != 0 && strcmp(token, "int") != 0 && strcmp(token, "float") != 0 && strcmp(token, "char") != 0) {
            if (strcmp(token, "{") == 0) {
                in_function = 1;
            } else if (strcmp(token, "}") == 0) {
                in_function = 0;
            }
        }

        num_lines++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Metadata metadata[100];
    int num_metadata = 0;

    extract_metadata(argv[1], metadata, &num_metadata);

    for (int i = 0; i < num_metadata; i++) {
        printf("Variable name: %s\n", metadata[i].name);
        printf("Type: %s\n", metadata[i].type);
        printf("Line number: %d\n", metadata[i].line_number);
        printf("\n");
    }

    return 0;
}