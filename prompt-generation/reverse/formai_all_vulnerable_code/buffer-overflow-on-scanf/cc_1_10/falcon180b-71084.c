//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 200

// Struct to hold key-value pairs
typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} KeyValuePair;

// Function to extract metadata from a string and return a KeyValuePair struct
KeyValuePair extractMetadata(char* metadata) {
    KeyValuePair kvp;
    char* key = strtok(metadata, ":");
    char* value = strtok(NULL, ":");

    // Check for errors
    if (key == NULL || value == NULL) {
        kvp.key[0] = '\0';
        kvp.value[0] = '\0';
        return kvp;
    }

    // Copy key and value into struct
    strncpy(kvp.key, key, MAX_KEY_LEN);
    strncpy(kvp.value, value, MAX_VALUE_LEN);

    return kvp;
}

// Function to print a KeyValuePair struct
void printKVP(KeyValuePair kvp) {
    printf("Key: %s\nValue: %s\n", kvp.key, kvp.value);
}

// Function to extract metadata from a file and print it
void extractMetadataFromFile(FILE* file) {
    char metadata[MAX_LINE_LEN];
    while (fgets(metadata, MAX_LINE_LEN, file)!= NULL) {
        KeyValuePair kvp = extractMetadata(metadata);
        printKVP(kvp);
    }
}

int main() {
    char filename[MAX_LINE_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    extractMetadataFromFile(file);

    fclose(file);
    return 0;
}