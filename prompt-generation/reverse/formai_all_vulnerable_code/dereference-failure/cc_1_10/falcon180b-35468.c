//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 2048
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 1024

// Function to trim whitespace from the beginning and end of a string
void trim(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (isspace(*start)) {
        start++;
    }

    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
}

// Function to extract key-value pairs from a line of text
int extract_key_value(char* line, char* key, char* value) {
    char* eq_pos = strchr(line, '=');
    if (eq_pos == NULL) {
        return 0;
    }

    *eq_pos = '\0';
    trim(line);
    trim(eq_pos + 1);

    strcpy(key, line);
    strcpy(value, eq_pos + 1);

    return 1;
}

// Function to print metadata in a formatted manner
void print_metadata(const char* filename, char* key, char* value) {
    printf("%-40s : %s\n", filename, value);
}

// Main function to read metadata from a file and print it
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (extract_key_value(line, key, value)) {
            print_metadata(argv[1], key, value);
        }
    }

    fclose(fp);

    return 0;
}