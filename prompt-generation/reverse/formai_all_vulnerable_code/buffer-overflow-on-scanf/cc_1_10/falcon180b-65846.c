//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 50

// Function to split a string into words
void split_string(char* str, char** words, int* num_words) {
    char* token = strtok(str, ",.?!;:");
    int i = 0;

    // Loop through each word and store it in the array
    while (token!= NULL && i < MAX_WORDS) {
        if (strlen(token) >= MIN_WORD_LEN && strlen(token) <= MAX_WORD_LEN) {
            words[i] = token;
            i++;
        }
        token = strtok(NULL, ",.?!;:");
    }

    *num_words = i;
}

// Function to check if a word is spam
int is_spam(char* word) {
    if (strcmp(word, "free") == 0 || strcmp(word, "cheap") == 0 || strcmp(word, "discount") == 0) {
        return 1; // Word is spam
    } else {
        return 0; // Word is not spam
    }
}

// Function to check if a message is spam
int is_spam_message(char* message, int num_words) {
    int spam_count = 0;

    // Loop through each word in the message
    for (int i = 0; i < num_words; i++) {
        if (is_spam(message + strlen(message - i))) {
            spam_count++;
        }
    }

    // If more than half of the words are spam, the message is spam
    if (spam_count > num_words / 2) {
        return 1; // Message is spam
    } else {
        return 0; // Message is not spam
    }
}

int main() {
    char message[1000];
    char* words[MAX_WORDS];
    int num_words;

    // Get input message from user
    printf("Enter a message: ");
    scanf("%s", message);

    // Split message into words
    split_string(message, words, &num_words);

    // Check if message is spam
    if (is_spam_message(message, num_words)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}