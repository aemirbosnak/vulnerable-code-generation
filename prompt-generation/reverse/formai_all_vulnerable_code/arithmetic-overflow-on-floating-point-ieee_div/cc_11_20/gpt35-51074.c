//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 1000
#define SPAM_THRESHOLD 0.7

int main() {
    char message[MAX_MSG_LEN];
    int num_lowercase = 0;
    int num_uppercase = 0;
    int num_numbers = 0;
    int num_spaces = 0;
    int num_symbols = 0;
    int num_spam_words = 0;

    printf("Enter message:\n");
    fgets(message, MAX_MSG_LEN, stdin);

    // Count the number of lowercase letters, uppercase letters, numbers, spaces, and symbols in the message
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            num_lowercase++;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            num_uppercase++;
        } else if (message[i] >= '0' && message[i] <= '9') {
            num_numbers++;
        } else if (message[i] == ' ') {
            num_spaces++;
        } else {
            num_symbols++;
        }
    }

    // Check for spam words
    if (strstr(message, "make money fast") != NULL || strstr(message, "earn money quick") != NULL || strstr(message, "get rich quick") != NULL) {
        num_spam_words++;
    }

    // Calculate the ratio of uppercase letters to lowercase letters and the ratio of spam words
    float uppercase_ratio = (float) num_uppercase / num_lowercase;
    float spam_ratio = (float) num_spam_words / strlen(message);

    // Determine if the message is spam or not
    if (uppercase_ratio > 2 && num_symbols > 5 && spam_ratio > SPAM_THRESHOLD) {
        printf("SPAM ALERT!!!\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}