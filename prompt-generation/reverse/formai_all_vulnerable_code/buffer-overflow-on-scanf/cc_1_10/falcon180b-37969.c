//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_WORD_LENGTH 100

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    char *word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count the number of characters in a string
int countChars(char *str) {
    int count = 0;
    while (*str!= '\0') {
        count++;
        str++;
    }
    return count;
}

// Function to count the number of sentences in a string
int countSentences(char *str) {
    int count = 0;
    char *sentence = strtok(str, ".");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to count the number of paragraphs in a string
int countParagraphs(char *str) {
    int count = 0;
    char *paragraph = strtok(str, "\n");
    while (paragraph!= NULL) {
        count++;
        paragraph = strtok(NULL, "\n");
    }
    return count;
}

int main() {
    FILE *file;
    char fileName[MAX_WORD_LENGTH];
    char ch;
    char *str = NULL;
    size_t len = 0;

    // Read file name from user
    printf("Enter the file name: ");
    scanf("%s", fileName);

    // Open the file in read mode
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read the file into a string
    while ((ch = fgetc(file))!= EOF) {
        str = realloc(str, len + 2);
        str[len++] = ch;
        str[len] = '\0';
    }
    fclose(file);

    // Count the number of words, characters, sentences, and paragraphs
    int numWords = countWords(str);
    int numChars = countChars(str);
    int numSentences = countSentences(str);
    int numParagraphs = countParagraphs(str);

    // Print the results
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
    printf("Number of sentences: %d\n", numSentences);
    printf("Number of paragraphs: %d\n", numParagraphs);

    // Free the memory allocated for the string
    free(str);

    return 0;
}