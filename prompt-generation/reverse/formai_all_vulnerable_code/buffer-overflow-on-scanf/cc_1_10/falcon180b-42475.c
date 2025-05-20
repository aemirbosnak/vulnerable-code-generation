//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Function to extract metadata from a file
void extract_metadata(FILE* file, char* filename) {
    char line[1000];
    char* key = NULL;
    char* value = NULL;
    bool in_metadata = false;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "metadata")!= NULL) {
            in_metadata = true;
            continue;
        }
        if (strstr(line, "ENDCONTEXT")!= NULL || strstr(line, "ENDINPUT")!= NULL) {
            in_metadata = false;
            continue;
        }
        if (!in_metadata) {
            continue;
        }
        if (line[0] == '\t') {
            key = line;
            key[strcspn(key, "\t")] = '\0';
        } else if (line[0]!= '\t') {
            value = line;
            value[strcspn(value, "\t")] = '\0';
        } else {
            printf("Invalid metadata line: %s\n", line);
        }
        if (key!= NULL && value!= NULL) {
            printf("File: %s\n", filename);
            printf("Key: %s\n", key);
            printf("Value: %s\n\n", value);
            key = NULL;
            value = NULL;
        }
    }
}

int main() {
    FILE* file;
    char filename[1000];
    printf("Enter file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    extract_metadata(file, filename);
    fclose(file);
    return 0;
}