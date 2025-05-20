//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

// Function to remove punctuation from a string
void removePunctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to split a string into words
int splitString(char* str, char words[][MAX_WORD_LENGTH]) {
    char* token = strtok(str, ",.?!;:");
    int count = 0;
    while (token!= NULL && count < MAX_WORDS) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to count the frequency of words
void countWords(char words[][MAX_WORD_LENGTH], int freq[][MAX_SENTENCES], int numWords, int numSentences) {
    int i, j;
    for (i = 0; i < numWords; i++) {
        for (j = 0; j < numSentences; j++) {
            if (strcmp(words[i], freq[j][0]) == 0) {
                freq[j][1]++;
                break;
            }
        }
        if (j == numSentences) {
            strcpy(freq[numSentences][0], words[i]);
            freq[numSentences][1] = 1;
            numSentences++;
        }
    }
}

// Function to print the word count
void printWordCount(char words[][MAX_WORD_LENGTH], int freq[][MAX_SENTENCES], int numWords, int numSentences) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], freq[i][1]);
    }
}

int main() {
    FILE* fp;
    char filename[50];
    char ch;
    int i = 0;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file into string
    char str[10000];
    while ((ch = fgetc(fp))!= EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';

    // Remove punctuation and convert to lowercase
    removePunctuation(str);

    // Split string into words
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = splitString(str, words);

    // Count frequency of words
    int freq[MAX_SENTENCES][2];
    int numSentences = 1;
    countWords(words, freq, numWords, numSentences);

    // Print word count
    printf("\nWord count:\n");
    printWordCount(words, freq, numWords, numSentences);

    // Close file
    fclose(fp);

    return 0;
}