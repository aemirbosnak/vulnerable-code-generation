//Falcon-180B DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count the number of sentences in a string
int countSentences(char* str) {
    int count = 0;
    char* sentence = strtok(str, ".");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to count the number of characters in a string
int countChars(char* str) {
    int count = 0;
    while (*str!= '\0') {
        count++;
        str++;
    }
    return count;
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    char vowels[] = "aeiouAEIOU";
    while (*str!= '\0') {
        if (strchr(vowels, *str)!= NULL) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char* input = "This is a test. It contains multiple sentences. And some numbers: 1234567890";
    printf("Number of words: %d\n", countWords(input));
    printf("Number of sentences: %d\n", countSentences(input));
    printf("Number of characters: %d\n", countChars(input));
    printf("Number of vowels: %d\n", countVowels(input));

    return 0;
}