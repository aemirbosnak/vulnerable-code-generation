//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX_MESSAGE_LENGTH 256
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 32

// Function to check if the message is spam
int is_spam(const char *message, const char spam_keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH], int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return 1; // Spam detected
        }
    }
    return 0; // No spam detected
}

// Function to read spam keywords from file
int load_spam_keywords(const char *filename, char spam_keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open spam keywords file.\n");
        return 0;
    }

    int count = 0;
    while (count < MAX_KEYWORDS && fscanf(file, "%s", spam_keywords[count]) == 1) {
        count++;
    }
    fclose(file);
    return count; // Return number of loaded keywords
}

// Function to take user input message
void get_user_message(char *message) {
    printf("Enter your message (max %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character if present
}

int main() {
    char spam_keywords[MAX_KEYWORDS][MAX_KEYWORD_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int num_keywords;

    // Load spam keywords
    num_keywords = load_spam_keywords("spam_keywords.txt", spam_keywords);
    if (num_keywords == 0) {
        printf("No keywords loaded. Exiting...\n");
        return 1;
    }

    // Get message from user
    get_user_message(message);

    // Check if the message is spam
    if (is_spam(message, spam_keywords, num_keywords)) {
        printf("Warning: Your message is flagged as spam!\n");
    } else {
        printf("Your message is clean.\n");
    }

    return 0;
}