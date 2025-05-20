//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

// Function to trim leading/trailing whitespace from a string
void trim(char* str) {
    int len = strlen(str);
    while (isspace(str[len-1])) {
        str[--len] = '\0';
    }
    while (isspace(*str)) {
        memmove(str, str+1, len);
        len--;
    }
}

// Function to parse a key-value pair from a line of text
void parse_line(char* line, char** key, char** value) {
    char* equals_pos = strchr(line, '=');
    if (equals_pos == NULL) {
        *key = strdup("");
        *value = strdup("");
    } else {
        *equals_pos = '\0';
        trim(line);
        *key = strdup(line);
        trim(equals_pos+1);
        *value = strdup(equals_pos+1);
    }
}

// Function to free memory allocated for a key-value pair
void free_pair(char* key, char* value) {
    free(key);
    free(value);
}

// Function to print a key-value pair
void print_pair(char* key, char* value) {
    printf("%s: %s\n", key, value);
}

// Function to extract metadata from a file
void extract_metadata(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char* key = NULL;
    char* value = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_line(line, &key, &value);
        if (key!= NULL && value!= NULL) {
            printf("Metadata:\n");
            print_pair(key, value);
        }
        free_pair(key, value);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    extract_metadata(file);

    fclose(file);
    return 0;
}