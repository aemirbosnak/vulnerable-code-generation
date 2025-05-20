//Falcon-180B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to read a file and store its contents in a string
char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char* buffer = (char*) malloc(MAX_LINE_SIZE);
    char* result = (char*) malloc(MAX_LINE_SIZE);
    int length = 0;

    // Read the file line by line
    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        strcat(result, buffer);
        length += strlen(buffer);
    }

    fclose(file);
    result = (char*) realloc(result, length + 1);
    result[length] = '\0';

    return result;
}

// Function to write a string to a file
void writeFile(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(content, strlen(content), 1, file);
    fclose(file);
}

// Function to count the number of words in a string
int countWords(const char* str) {
    int count = 0;

    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char* content = readFile("input.txt");
    int numWords = countWords(content);

    printf("The input file contains %d words.\n", numWords);

    // Perform some operations on the content...

    writeFile("output.txt", content);

    printf("Done.\n");
    return 0;
}