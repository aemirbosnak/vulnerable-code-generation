//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

// Function to trim leading/trailing whitespaces from a string
char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
        *end = '\0';
    }
    return str;
}

// Function to split a string into key-value pairs
void split_string(char* input, char** key, char** value) {
    char* delimiter = "=";
    char* token = strtok(input, delimiter);
    *key = token;
    token = strtok(NULL, delimiter);
    *value = token;
}

// Function to print metadata in a readable format
void print_metadata(char* key, char* value) {
    printf("%s: %s\n", key, value);
}

// Function to extract metadata from a file
void extract_metadata(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* comment_start = strchr(line, '#');
        if (comment_start!= NULL) {
            *comment_start = '\0';
        }
        char* trimmed_line = trim(line);
        if (strlen(trimmed_line) == 0) {
            continue;
        }
        split_string(trimmed_line, &key, &value);
        print_metadata(key, value);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }
    extract_metadata(input_file);
    fclose(input_file);
    fclose(output_file);
    return 0;
}