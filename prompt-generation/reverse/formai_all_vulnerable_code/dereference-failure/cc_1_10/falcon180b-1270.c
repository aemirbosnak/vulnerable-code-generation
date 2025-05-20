//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

// Function to remove leading and trailing spaces from a string
void trim(char* str) {
    int i = 0;
    while(isspace(str[i])) {
        i++;
    }
    int j = strlen(str) - 1;
    while(isspace(str[j])) {
        str[j] = '\0';
        j--;
    }
}

// Function to split a string into words
void split(char* str, char** words) {
    int i = 0;
    char* token = strtok(str, " ");
    while(token!= NULL) {
        words[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    words[i] = NULL;
}

// Function to count the frequency of each word
void countWords(char** words, int* freq) {
    for(int i = 0; words[i]!= NULL; i++) {
        freq[i] = 1;
    }
}

// Function to sort the words in alphabetical order
void sortWords(char** words) {
    for(int i = 0; i < strlen(words[0]) - 1; i++) {
        for(int j = i + 1; j < strlen(words[0]); j++) {
            char temp = words[0][i];
            words[0][i] = words[0][j];
            words[0][j] = temp;
        }
    }
}

// Function to print the word frequency
void printFreq(char** words, int* freq) {
    for(int i = 0; words[i]!= NULL; i++) {
        printf("%s %d\n", words[i], freq[i]);
    }
}

int main() {
    char input[MAX_LINE_SIZE];
    char* words[MAX_WORD_SIZE];
    int freq[MAX_WORD_SIZE];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, MAX_LINE_SIZE, stdin);

    // Remove leading and trailing spaces from the string
    trim(input);

    // Split the string into words
    split(input, words);

    // Count the frequency of each word
    countWords(words, freq);

    // Sort the words in alphabetical order
    sortWords(words);

    // Print the word frequency
    printf("Word Frequency:\n");
    printFreq(words, freq);

    return 0;
}