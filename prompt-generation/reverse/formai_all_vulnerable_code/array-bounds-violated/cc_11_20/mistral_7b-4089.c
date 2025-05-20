//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define NUM_KEYWORDS 5

// Keywords for spam detection
char *keywords[NUM_KEYWORDS] = {
    "viagra",
    "free",
    "money",
    "prize",
    "offer"
};

int main() {
    char input[MAX_INPUT_SIZE];
    int i, j;
    int is_spam = 0;

    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Convert input to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Check for spam keywords
    for (i = 0; i < NUM_KEYWORDS && !is_spam; i++) {
        int keyword_length = strlen(keywords[i]);
        for (j = 0; j < strlen(input) - keyword_length + 1 && !is_spam; j++) {
            int match = 1;
            for (int k = 0; k < keyword_length; k++) {
                if (input[j + k] != keywords[i][k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                is_spam = 1;
                break;
            }
        }
    }

    // Output message based on result
    if (is_spam) {
        printf("WARNING: Possible spam detected!\n");
    } else {
        printf("Your message is safe to send.\n");
    }

    return 0;
}