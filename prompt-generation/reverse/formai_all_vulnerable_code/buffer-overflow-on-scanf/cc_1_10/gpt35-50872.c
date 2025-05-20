//FormAI DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function to remove punctuation and convert to lowercase
void cleanup_word(char* word) {
    char* p = word;
    while (*p) {
        if (ispunct(*p)) {
            memmove(p, p + 1, strlen(p + 1) + 1);
        }
        else {
            *p = tolower(*p);
            p++;
        }
    }
}

// Function to compare two words, return 0 if they match, 1 otherwise
int compare_words(char* word1, char* word2) {
    return strcmp(word1, word2);
}

int main() {
    char word[MAX_WORD_LENGTH];
    char* dictionary[] = {"apple", "banana", "cherry", "dog", "elephant",
                          "frank", "giraffe", "horse", "igloo", "jungle"};
    int num_words = sizeof(dictionary) / sizeof(dictionary[0]);
    int spelled_correctly = 1;
    while (scanf("%s", word) != EOF) {
        // Remove punctuation and convert to lowercase
        cleanup_word(word);
        // Check if the word is in the dictionary
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (compare_words(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("ERROR: %s is spelled incorrectly\n", word);
            spelled_correctly = 0;
        }
    }
    if (spelled_correctly) {
        printf("All words spelled correctly\n");
    }
    return 0;
}