//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_SIZE 256
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    char file_name[MAX_FILE_NAME_SIZE];
    strcpy(file_name, argv[1]);

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    metadata_t metadata[100];
    int num_metadata = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (key == NULL || value == NULL) {
            continue;
        }

        strncpy(metadata[num_metadata].key, key, MAX_KEY_SIZE);
        strncpy(metadata[num_metadata].value, value, MAX_VALUE_SIZE);
        num_metadata++;

        if (num_metadata >= 100) {
            break;
        }
    }

    fclose(fp);

    printf("Number of metadata: %d\n", num_metadata);

    for (int i = 0; i < num_metadata; i++) {
        printf("Key: %s\nValue: %s\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}