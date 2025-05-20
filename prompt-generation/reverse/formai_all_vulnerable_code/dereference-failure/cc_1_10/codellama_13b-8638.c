//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
// C Spam Detection System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the message
#define MAX_LENGTH 100

// Define the minimum number of spam words
#define MIN_SPAM 3

// Define the spam words
char *spam_words[] = {"viagra", "cialis", "xanax", "levitra"};

// Function to check if a word is a spam word
int is_spam_word(char *word) {
    for (int i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to count the number of spam words in a message
int count_spam_words(char *message) {
    int count = 0;
    char *word;
    while ((word = strsep(&message, " ")) != NULL) {
        if (is_spam_word(word)) {
            count++;
        }
    }
    return count;
}

// Function to check if a message is spam
int is_spam(char *message) {
    int count = count_spam_words(message);
    return count >= MIN_SPAM;
}

int main() {
    char message[MAX_LENGTH];
    printf("Enter a message: ");
    fgets(message, MAX_LENGTH, stdin);
    if (is_spam(message)) {
        printf("Spam detected\n");
    } else {
        printf("Ham detected\n");
    }
    return 0;
}