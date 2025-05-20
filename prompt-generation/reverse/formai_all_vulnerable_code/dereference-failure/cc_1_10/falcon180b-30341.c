//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count words
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count characters
int countCharacters(char* str) {
    int count = 0;
    char c;
    while ((c = *str++)!= '\0') {
        if (isalnum(c)) {
            count++;
        }
    }
    return count;
}

// Function to count lines
int countLines(char* str) {
    int count = 0;
    char* line = strtok(str, "\n");
    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }
    return count;
}

int main() {
    FILE* file;
    char* buffer = NULL;
    size_t size = 0;
    int words = 0, characters = 0, lines = 0;

    // Open file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read file into buffer
    if (fseek(file, 0, SEEK_END)!= 0) {
        printf("Error seeking end of file\n");
        return 1;
    }
    size = ftell(file);
    if (size == -1) {
        printf("Error getting file size\n");
        return 1;
    }
    rewind(file);
    buffer = malloc(size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    if (fread(buffer, size, 1, file)!= 1) {
        printf("Error reading file\n");
        return 1;
    }
    buffer[size] = '\0';

    // Count words, characters, and lines
    words = countWords(buffer);
    characters = countCharacters(buffer);
    lines = countLines(buffer);

    // Print results
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    printf("Lines: %d\n", lines);

    // Free memory and close file
    free(buffer);
    fclose(file);

    return 0;
}