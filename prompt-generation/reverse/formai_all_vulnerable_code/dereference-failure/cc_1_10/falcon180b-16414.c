//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Function to split a string into words
void split(char* str, char* words[], int max_words) {
    int i = 0;
    char* word = strtok(str, ",.?!:;\"'");
    while (word!= NULL && i < max_words) {
        words[i] = word;
        i++;
        word = strtok(NULL, ",.?!:;\"'");
    }
}

// Function to count the frequency of each word
void count_words(char* words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s -> %d\n", words[i], count_occurrences(words[i], words, num_words));
    }
}

// Function to count the occurrences of a word in an array of words
int count_occurrences(char* word, char* words[], int num_words) {
    int i, count = 0;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            count++;
        }
    }
    return count;
}

// Function to remove punctuation from a string
void remove_punctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int main() {
    // Read in the text file
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    char text[MAX_WORD_LENGTH];
    while (fgets(text, MAX_WORD_LENGTH, file)!= NULL) {
        // Remove newline character
        text[strcspn(text, "\n")] = '\0';
        // Remove punctuation and convert to lowercase
        remove_punctuation(text);
        // Split into words
        char words[MAX_WORDS][MAX_WORD_LENGTH];
        int num_words = 0;
        split(text, words, MAX_WORDS);
        num_words = strlen(words[0]) > 0? 1 : 0;
        // Count occurrences of each word
        count_words(words, num_words);
    }
    fclose(file);
    return 0;
}