//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <string.h>

// Maximum size of a message
#define MAX_MSG_SIZE 100

// Maximum number of messages
#define MAX_MSG_NUM 10

// Minimum number of characters to consider as spam
#define MIN_SPAM_CHARS 3

// Maximum number of consecutive characters that can be repeated
#define MAX_CONSEC_CHARS 3

// Return true if the message is spam
int is_spam(char* msg, int num_msgs, char msgs[][MAX_MSG_SIZE]) {
    // Check if the message contains too many consecutive characters
    int len = strlen(msg);
    char last_char = 0;
    int consec_chars = 0;
    for (int i = 0; i < len; i++) {
        char c = msg[i];
        if (c == last_char) {
            consec_chars++;
            if (consec_chars > MAX_CONSEC_CHARS) {
                return 1;
            }
        } else {
            consec_chars = 1;
            last_char = c;
        }
    }

    // Check if the message is already in the list of messages
    for (int i = 0; i < num_msgs; i++) {
        if (strcmp(msg, msgs[i]) == 0) {
            return 1;
        }
    }

    // Check if the message contains too few unique characters
    int num_unique_chars = 0;
    int char_set[26] = {0};
    for (int i = 0; i < len; i++) {
        char c = msg[i];
        if (char_set[c - 'a'] == 0) {
            num_unique_chars++;
            char_set[c - 'a'] = 1;
        }
    }
    if (num_unique_chars < MIN_SPAM_CHARS) {
        return 1;
    }

    return 0;
}

int main() {
    // Initialize the list of messages
    char msgs[MAX_MSG_NUM][MAX_MSG_SIZE];
    int num_msgs = 0;

    // Read messages and detect spam
    while (1) {
        printf("Enter a message: ");
        char msg[MAX_MSG_SIZE];
        fgets(msg, MAX_MSG_SIZE, stdin);
        msg[strcspn(msg, "\n")] = 0;  // Remove newline character

        // Check if the message is spam
        if (is_spam(msg, num_msgs, msgs)) {
            printf("SPAM detected!\n");
        } else {
            printf("OK\n");

            // Add the message to the list of messages
            if (num_msgs < MAX_MSG_NUM) {
                strcpy(msgs[num_msgs], msg);
                num_msgs++;
            }
        }
    }

    return 0;
}