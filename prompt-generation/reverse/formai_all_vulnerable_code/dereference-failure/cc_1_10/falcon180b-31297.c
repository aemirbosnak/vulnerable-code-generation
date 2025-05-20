//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_KEY_SIZE 50

typedef struct {
    char *key;
    char *value;
} KeyValue;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_SIZE];
    char delimiter = ',';
    int numKeys = 0;
    KeyValue *keys = NULL;

    if (argc < 2) {
        printf("Please provide a resume file as input.\n");
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read in the header line to determine the keys
    fgets(line, MAX_LINE_SIZE, inputFile);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        numKeys++;
        token = strtok(NULL, ",");
    }
    keys = (KeyValue *) malloc(numKeys * sizeof(KeyValue));

    // Read in the rest of the lines and store in key-value pairs
    rewind(inputFile);
    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        char *token = strtok(line, delimiter);
        int i = 0;
        while (token!= NULL) {
            if (i >= numKeys) {
                printf("Error: Too many columns in line.\n");
                fclose(inputFile);
                free(keys);
                return 1;
            }
            keys[i].key = token;
            token = strtok(NULL, delimiter);
            i++;
        }
    }

    fclose(inputFile);

    // Print out the key-value pairs
    printf("Name: %s\n", keys[0].value);
    printf("Education: %s\n", keys[1].value);
    printf("Experience: %s\n", keys[2].value);

    free(keys);
    return 0;
}