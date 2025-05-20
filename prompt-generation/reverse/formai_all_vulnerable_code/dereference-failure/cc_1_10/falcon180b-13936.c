//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

// Function to check if a character is a valid letter
int isValidLetter(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to count the number of words in a string
int countWords(char* str) {
    int numWords = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        numWords++;
        word = strtok(NULL, " ");
    }
    return numWords;
}

// Function to count the number of characters in a string
int countCharacters(char* str) {
    int numChars = 0;
    while (*str!= '\0') {
        numChars++;
        str++;
    }
    return numChars;
}

// Function to count the number of sentences in a string
int countSentences(char* str) {
    int numSentences = 0;
    char* sentence = strtok(str, ".");
    while (sentence!= NULL) {
        numSentences++;
        sentence = strtok(NULL, ".");
    }
    return numSentences;
}

int main() {
    FILE* file;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int numWords = 0, numChars = 0, numSentences = 0;

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    // Read the file line by line
    while ((read = getline(&line, &len, file))!= -1) {
        // Count the number of words, characters, and sentences in the line
        numWords += countWords(line);
        numChars += countCharacters(line);
        numSentences += countSentences(line);

        // Free the memory allocated for the line
        free(line);
        line = NULL;
        len = 0;
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
    printf("Number of sentences: %d\n", numSentences);

    return 0;
}