//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count words in a sentence
int countWords(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count lines in a file
int countLines(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    return count;
}

// Function to count characters in a file
int countCharacters(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        count++;
    }
    return count;
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Count words, lines, and characters
    int wordCount = countWords(filename);
    int lineCount = countLines(file);
    int charCount = countCharacters(file);

    // Close the file
    fclose(file);

    // Print the results
    printf("Word count: %d\n", wordCount);
    printf("Line count: %d\n", lineCount);
    printf("Character count: %d\n", charCount);

    return 0;
}