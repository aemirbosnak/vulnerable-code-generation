//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} Metadata;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: %s file_path\n", argv[0]);
        exit(1);
    }

    char* file_path = argv[1];
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("%s: No such file or directory\n", file_path);
        exit(1);
    }

    Metadata metadata[100];
    int metadata_index = 0;

    int ch;
    char current_key[100];
    char current_value[100];
    int current_key_index = 0;
    int current_value_index = 0;
    int reading_key = 1;
    int inside_quotes = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (reading_key) {
            if (ch == ':') {
                current_key[current_key_index] = '\0';
                reading_key = 0;
            } else {
                current_key[current_key_index] = ch;
                current_key_index++;
            }
        } else {
            if (ch == ',') {
                current_value[current_value_index] = '\0';
                metadata[metadata_index].key = strdup(current_key);
                metadata[metadata_index].value = strdup(current_value);
                metadata_index++;
                current_key_index = 0;
                current_value_index = 0;
                reading_key = 1;
            } else {
                if (ch == '"') {
                    inside_quotes = !inside_quotes;
                } else if (ch == ' ' && !inside_quotes) {
                    continue;
                }
                current_value[current_value_index] = ch;
                current_value_index++;
            }
        }
    }

    if (!reading_key) {
        metadata[metadata_index].key = strdup(current_key);
        metadata[metadata_index].value = strdup(current_value);
        metadata_index++;
    }

    printf("Metadata:\n");
    for (int i = 0; i < metadata_index; i++) {
        printf("\t%s: %s\n", metadata[i].key, metadata[i].value);
    }

    fclose(file);
    return 0;   
}