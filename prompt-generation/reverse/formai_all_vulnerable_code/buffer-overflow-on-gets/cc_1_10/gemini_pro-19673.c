//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains a substring
int contains(char *str, char *substr) {
    int len_str = strlen(str);
    int len_substr = strlen(substr);
    for (int i = 0; i <= len_str - len_substr; i++) {
        if (strncmp(str + i, substr, len_substr) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is a spam message
int isSpam(char *str) {
    // Check for common spam keywords
    char *keywords[] = {"free", "offer", "win", "click", "subscribe"};
    int num_keywords = sizeof(keywords) / sizeof(char *);
    for (int i = 0; i < num_keywords; i++) {
        if (contains(str, keywords[i])) {
            return 1;
        }
    }

    // Check for excessive punctuation and capitalization
    int num_punct = 0;
    int num_caps = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (ispunct(str[i])) {
            num_punct++;
        }
        if (isupper(str[i])) {
            num_caps++;
        }
    }
    if (num_punct > strlen(str) / 10 || num_caps > strlen(str) / 2) {
        return 1;
    }

    // Check for suspicious links
    char *links[] = {"http://", "https://", "www."};
    int num_links = sizeof(links) / sizeof(char *);
    for (int i = 0; i < num_links; i++) {
        if (contains(str, links[i])) {
            return 1;
        }
    }

    // Check for multiple exclamation marks
    int num_exclamations = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '!') {
            num_exclamations++;
        }
    }
    if (num_exclamations > 2) {
        return 1;
    }

    // Otherwise, return false
    return 0;
}

// Main function
int main() {
    // Get the input message
    char message[1024];
    printf("Enter the message: ");
    gets(message);

    // Check if the message is spam
    int is_spam = isSpam(message);

    // Print the result
    if (is_spam) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}