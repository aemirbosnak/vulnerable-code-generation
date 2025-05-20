//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to read a file and store its contents in a string
void readFile(FILE* file, char* str) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    fread(str, sizeof(char), size, file);
    str[size] = '\0';
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file contents into a string
    char* str = malloc(MAX_WORDS * MAX_WORD_LENGTH);
    readFile(file, str);

    // Count the number of words in the string
    int numWords = countWords(str);

    // Print the number of words
    printf("Number of words: %d\n", numWords);

    // Close the file
    fclose(file);

    // Free the memory allocated for the string
    free(str);

    return 0;
}