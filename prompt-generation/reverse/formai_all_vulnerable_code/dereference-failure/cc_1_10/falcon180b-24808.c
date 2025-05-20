//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Function to remove leading and trailing whitespace from a string
char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        *end-- = '\0';
    }
    while (*str && isspace(*str)) {
        str++;
    }
    return str;
}

// Function to find the first non-whitespace character in a string
char* skip_whitespace(char* str) {
    while (*str && isspace(*str)) {
        str++;
    }
    return str;
}

// Function to extract metadata from a C source file
void extract_metadata(FILE* fp) {
    char line[MAX_LINE_SIZE];
    char* filename = NULL;
    char* author = NULL;
    char* date = NULL;
    char* description = NULL;

    // Read the first line of the file, which should contain the filename
    fgets(line, MAX_LINE_SIZE, fp);
    filename = trim(line);

    // Read the second line of the file, which should contain the author
    fgets(line, MAX_LINE_SIZE, fp);
    author = trim(line);

    // Read the third line of the file, which should contain the date
    fgets(line, MAX_LINE_SIZE, fp);
    date = trim(line);

    // Read the fourth line of the file, which should contain the description
    fgets(line, MAX_LINE_SIZE, fp);
    description = trim(line);

    // Print the metadata
    printf("Filename: %s\n", filename);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Description: %s\n", description);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Extract metadata from the file
    extract_metadata(fp);

    // Close the file
    fclose(fp);

    return 0;
}