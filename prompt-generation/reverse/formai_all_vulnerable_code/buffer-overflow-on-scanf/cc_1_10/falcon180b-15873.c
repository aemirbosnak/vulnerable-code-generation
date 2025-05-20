//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to count words in a sentence
int countWords(char* sentence) {
    int count = 0;
    char* word = strtok(sentence, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to count characters in a string
int countCharacters(char* string) {
    int count = 0;

    while (*string!= '\0') {
        count++;
        string++;
    }

    return count;
}

// Function to count lines in a file
int countLines(FILE* file) {
    char line[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        count++;
    }

    return count;
}

// Function to count words and characters in a file
void countFile(FILE* file) {
    char line[MAX_WORD_LENGTH];
    int wordCount = 0;
    int charCount = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        charCount += strlen(line);
        wordCount += countWords(line);
    }

    printf("Number of words: %d\n", wordCount);
    printf("Number of characters: %d\n", charCount);
}

int main() {
    char filename[MAX_WORD_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    countFile(file);

    fclose(file);

    return 0;
}