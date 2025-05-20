//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 100

void print_metadata(char *metadata) {
    printf("Metadata: %s\n", metadata);
}

void extract_metadata(char *filename) {
    char *metadata = malloc(MAX_METADATA_SIZE);
    if (metadata == NULL) {
        exit(0);
    }
    memset(metadata, 0, MAX_METADATA_SIZE);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        exit(0);
    }

    char buffer[MAX_METADATA_SIZE];
    memset(buffer, 0, MAX_METADATA_SIZE);
    while (fgets(buffer, MAX_METADATA_SIZE, fp)) {
        if (strstr(buffer, "metadata")) {
            strcat(metadata, buffer);
        }
    }

    print_metadata(metadata);

    fclose(fp);
    free(metadata);
}

void paranoid_mode() {
    char *filename = malloc(100);
    if (filename == NULL) {
        exit(0);
    }

    printf("Enter filename: ");
    scanf("%s", filename);

    size_t len = strlen(filename);
    for (size_t i = 0; i < len; i++) {
        if (filename[i] == ';' || filename[i] == '&' || filename[i] == '|') {
            printf("Invalid character in filename!\n\n");
            return;
        }
    }

    extract_metadata(filename);
}

int main() {
    paranoid_mode();
    
    return 0;
}