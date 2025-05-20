//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

// Function to count characters in a sentence
int countCharacters(char *sentence) {
    int count = 0;
    while (*sentence!= '\0') {
        if (isalpha(*sentence)) {
            count++;
        }
        sentence++;
    }
    return count;
}

// Function to count sentences in a paragraph
int countSentences(char *paragraph) {
    int count = 0;
    char *sentence = strtok(paragraph, ".");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to count paragraphs in a text file
int countParagraphs(FILE *file) {
    char ch;
    int count = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    return count;
}

int main() {
    FILE *file;
    char filename[100];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Count words, characters, sentences, and paragraphs
    int wordCount = 0;
    int charCount = 0;
    int sentenceCount = 0;
    int paraCount = 0;

    while ((read = getline(&line, &len, file))!= -1) {
        char *sentence = strtok(line, ".");
        while (sentence!= NULL) {
            wordCount += countWords(sentence);
            charCount += countCharacters(sentence);
            sentenceCount++;
            sentence = strtok(NULL, ".");
        }
        paraCount++;
    }

    // Print the results
    printf("Total words: %d\n", wordCount);
    printf("Total characters: %d\n", charCount);
    printf("Total sentences: %d\n", sentenceCount);
    printf("Total paragraphs: %d\n", paraCount);

    // Close the file
    fclose(file);

    return 0;
}