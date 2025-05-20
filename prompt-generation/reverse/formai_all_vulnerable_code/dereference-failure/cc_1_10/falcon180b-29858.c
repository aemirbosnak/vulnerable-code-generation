//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " \t\n\r\f\v,.?!;:");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
    return count;
}

// Function to count characters in a string
int countChars(char* str) {
    int count = 0;
    while (*str!= '\0') {
        count++;
        str++;
    }
    return count;
}

// Function to count sentences in a string
int countSentences(char* str) {
    int count = 0;
    char* sentence = strtok(str, ".?!");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".?!");
    }
    return count;
}

// Function to count paragraphs in a string
int countParagraphs(char* str) {
    int count = 0;
    char* paragraph = strtok(str, "\n\r");
    while (paragraph!= NULL) {
        count++;
        paragraph = strtok(NULL, "\n\r");
    }
    return count;
}

int main() {
    char* input = NULL;
    size_t len = 0;
    ssize_t read;

    // Read input from user
    printf("Enter some text: ");
    read = getline(&input, &len, stdin);
    if (read == -1) {
        fprintf(stderr, "Error reading input\n");
        exit(1);
    }

    // Count words, characters, sentences, and paragraphs
    int numWords = countWords(input);
    int numChars = countChars(input);
    int numSentences = countSentences(input);
    int numParagraphs = countParagraphs(input);

    // Print results
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
    printf("Number of sentences: %d\n", numSentences);
    printf("Number of paragraphs: %d\n", numParagraphs);

    free(input);
    return 0;
}