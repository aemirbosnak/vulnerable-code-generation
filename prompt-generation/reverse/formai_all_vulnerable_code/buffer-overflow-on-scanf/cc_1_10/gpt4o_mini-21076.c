//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
bool isSpamMessage(const char *message);
void toLowerCase(char *str);

int main() {
    char messages[10][256]; // Array to hold messages
    int messageCount;
    
    // Get the number of messages from the user
    printf("Enter the number of messages (max 10): ");
    scanf("%d", &messageCount);
    
    // Ensure message count does not exceed array size
    if (messageCount > 10) {
        printf("Limit exceeded. Setting message count to 10.\n");
        messageCount = 10;
    }

    // Input messages
    printf("Please enter the messages:\n");
    getchar(); // To consume the newline character after scanf
    for (int i = 0; i < messageCount; i++) {
        printf("Message %d: ", i + 1);
        fgets(messages[i], 256, stdin);
        messages[i][strcspn(messages[i], "\n")] = 0; // Remove newline character
    }

    // Analyze each message
    for (int i = 0; i < messageCount; i++) {
        printf("Analyzing Message %d: \"%s\"\n", i + 1, messages[i]);
        if (isSpamMessage(messages[i])) {
            printf("=> This message is classified as SPAM.\n");
        } else {
            printf("=> This message is classified as NOT SPAM.\n");
        }
    }

    return 0;
}

// Function to check if a message is spam
bool isSpamMessage(const char *message) {
    // Array of spam keywords
    const char *spamKeywords[] = {
        "win", "free", "money", "click here", "urgent", "limited time", "winner", 
        "prize", "call now", "exclusive", "risk-free", "100% free"
    };
    int keywordCount = sizeof(spamKeywords) / sizeof(spamKeywords[0]);

    // Create a mutable copy of the message to analyze case insensitively
    char lowerMessage[256];
    strcpy(lowerMessage, message);
    toLowerCase(lowerMessage);

    // Search for keywords
    for (int i = 0; i < keywordCount; i++) {
        if (strstr(lowerMessage, spamKeywords[i]) != NULL) {
            return true; // Spam detected
        }
    }

    return false; // No spam detected
}

// Function to convert a string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; // Convert to lowercase
        }
    }
}