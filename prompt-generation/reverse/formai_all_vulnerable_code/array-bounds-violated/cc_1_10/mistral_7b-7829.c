//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 256
#define NUM_KEYWORDS 5

// List of keywords to check for in a message
const char* keywords[NUM_KEYWORDS] = {
    "viagra",
    "credit",
    "free",
    "money",
    "prize"
};

int is_spam(const char* message) {
    int num_keywords_found = 0;
    int message_length = strlen(message);

    for (int i = 0; i < NUM_KEYWORDS && num_keywords_found < 3; ++i) {
        size_t keyword_length = strlen(keywords[i]);
        if (message_length < keyword_length + 1) {
            continue;
        }

        int j;
        for (j = 0; j < keyword_length && message[j] != keywords[i][j] && isalpha(message[j]); ++j) {
            if (toupper(message[j]) != toupper(keywords[i][j])) {
                break;
            }
        }

        if (j == keyword_length) {
            ++num_keywords_found;
        }
    }

    return num_keywords_found >= 3;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strlen(message) - 1] = '\0'; // Remove newline character

    if (is_spam(message)) {
        printf("SPAM DETECTED!\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}