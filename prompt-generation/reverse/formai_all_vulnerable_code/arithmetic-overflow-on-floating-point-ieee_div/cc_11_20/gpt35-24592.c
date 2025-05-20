//FormAI DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000
#define SPAM_THRESHOLD 0.5

int main() {
    char msg[MAX_MSG_LENGTH];
    printf("Please enter your message:\n");
    fgets(msg, MAX_MSG_LENGTH, stdin); // User input

    int msg_len = strlen(msg);
    int num_chars = 0;
    int num_digits = 0;
    int num_spaces = 0;
    int num_puncts = 0;
    int num_upper = 0;

    // Loop to check each character in the message
    for (int i = 0; i < msg_len; i++) {
        // Check if character is a letter
        if ((msg[i] >= 'a' && msg[i] <= 'z') || (msg[i] >= 'A' && msg[i] <= 'Z')) {
            num_chars++;
            // Check if letter is uppercase
            if (msg[i] >= 'A' && msg[i] <= 'Z') {
                num_upper++;
            }
        }
        // Check if character is a digit
        else if (msg[i] >= '0' && msg[i] <= '9') {
            num_digits++;
        }
        // Check if character is a space
        else if (msg[i] == ' ') {
            num_spaces++;
        }
        // Check if character is a punctuation mark
        else if (msg[i] == '.' || msg[i] == ',' || msg[i] == '?' || msg[i] == '!' || msg[i] == ';') {
            num_puncts++;
        }
    }

    // Calculate ratios
    float char_space_ratio = (float) num_chars / (float) num_spaces;
    float char_upper_ratio = (float) num_upper / (float) num_chars;
    float digit_char_ratio = (float) num_digits / (float) num_chars;
    float punct_char_ratio = (float) num_puncts / (float) num_chars;

    // Spam detection logic
    if (char_space_ratio < SPAM_THRESHOLD || char_upper_ratio > SPAM_THRESHOLD || digit_char_ratio > SPAM_THRESHOLD || punct_char_ratio > SPAM_THRESHOLD) {
        printf("This message is flagged as spam.\n");
    }
    else {
        printf("This message is not spam.\n");
    }

    return 0;
}