//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char *) malloc(filesize + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    char *metadata = strstr(buffer, "metadata");
    if (metadata == NULL) {
        printf("No metadata found\n");
        free(buffer);
        return 0;
    }

    metadata += 8; // skip "metadata"

    char *key = metadata;
    char *value = strchr(metadata, ':');
    if (value == NULL) {
        printf("Invalid metadata\n");
        free(buffer);
        return 1;
    }

    *value = '\0';
    value++;

    printf("Key: %s\nValue: %s\n", key, value);

    free(buffer);
    return 0;
}