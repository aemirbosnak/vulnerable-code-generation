//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to remove punctuations from a string
void removePunctuations(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i])) {
            continue;
        }
        str[j++] = tolower(str[i]);
    }
    str[j] = '\0';
}

// Function to split a string into words
void splitString(char* str, char** words) {
    char* token = strtok(str, ",.!?;:");
    int count = 0;
    while (token!= NULL) {
        words[count++] = token;
        token = strtok(NULL, ",.!?;:");
    }
}

// Function to calculate the frequency of each word
void countWords(char** words, int* frequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        frequencies[i] = 0;
    }
    for (int i = 0; i < numWords; i++) {
        char* word = words[i];
        for (int j = 0; j < numWords; j++) {
            if (strcmp(word, words[j]) == 0) {
                frequencies[j]++;
            }
        }
    }
}

// Function to classify a new text into categories based on the frequency of words
void classifyText(int* frequencies, int numWords, char** categories, int numCategories) {
    int maxFrequency = 0;
    int maxCategoryIndex = -1;
    for (int i = 0; i < numWords; i++) {
        if (frequencies[i] > maxFrequency) {
            maxFrequency = frequencies[i];
            maxCategoryIndex = i;
        }
    }
    printf("Classified as: %s\n", categories[maxCategoryIndex]);
}

int main() {
    // Read the input text
    char inputText[1000];
    printf("Enter the input text: ");
    fgets(inputText, sizeof(inputText), stdin);

    // Remove punctuations and split the input text into words
    char* words[MAX_WORDS];
    int numWords = 0;
    removePunctuations(inputText);
    splitString(inputText, words);
    numWords = strlen(inputText);

    // Calculate the frequency of each word
    int frequencies[MAX_WORDS];
    countWords(words, frequencies, numWords);

    // Classify the input text
    char* categories[] = {"Sports", "Politics", "Technology", "Entertainment"};
    int numCategories = sizeof(categories) / sizeof(char*);
    classifyText(frequencies, numWords, categories, numCategories);

    return 0;
}