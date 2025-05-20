//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_SIZE 1000
#define NUM_KEYWORDS 5

// Keywords to detect spam messages
const char *keywords[NUM_KEYWORDS] = {
    "viagra",
    "cialis",
    "levitra",
    "priapism",
    "viagraonline"
};

void detect_spam(const char *message) {
    int num_keywords_found = 0;
    for (int i = 0; i < NUM_KEYWORDS; ++i) {
        size_t keyword_len = strlen(keywords[i]);
        for (size_t j = 0; j <= strlen(message) - keyword_len; ++j) {
            if (strncmp(message + j, keywords[i], keyword_len) == 0) {
                // Match found, increment counter and break inner loop
                num_keywords_found++;
                break;
            }
        }
    }

    // If more than NUM_KEYWORDS are found, mark as spam
    if (num_keywords_found > NUM_KEYWORDS / 2) {
        printf("SPAM DETECTED: %s\n", message);
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];

    // Read message from user input
    fgets(message, sizeof(message), stdin);

    // Remove newline character from user input
    size_t newline_pos = strlen(message) - 1;
    if (newline_pos > 0 && message[newline_pos] == '\n') {
        message[newline_pos] = '\0';
    }

    // Detect spam and print result
    detect_spam(message);

    return 0;
}