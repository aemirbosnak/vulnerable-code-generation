//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

// A funny characteristic of spam messages 
char *spamKeywords[] = {
    "Congratulations!", 
    "You have won a prize!", 
    "Free gift!",
    "Click here now!",
    "Act fast!",
    "This is not a scam!",
    "Money back guaranteed!",
    "Dear friend,"
};

int spamKeywordCount = sizeof(spamKeywords) / sizeof(spamKeywords[0]);

bool isSpam(char *message) {
    for (int i = 0; i < spamKeywordCount; i++) {
        if (strstr(message, spamKeywords[i])) {
            printf("🚨 Spam alert: Found keyword \"%s\" in the message!\n", spamKeywords[i]);
            return true;
        }
    }
    return false;
}

void feedMeSpamMessages(char messages[MAX_MESSAGES][MAX_LENGTH], int *messageCount) {
    printf("🍕 Feeding spam messages into the system...\n");
    for (int i = 0; i < *messageCount; i++) {
        printf("Enter spam message #%d: ", i + 1);
        fgets(messages[i], MAX_LENGTH, stdin);
        messages[i][strcspn(messages[i], "\n")] = 0;  // Remove newline character
    }
}

void detectSpamMessages(char messages[MAX_MESSAGES][MAX_LENGTH], int messageCount) {
    printf("\n🤖 Analyzing the messages for spam...\n");

    for (int i = 0; i < messageCount; i++) {
        if (isSpam(messages[i])) {
            printf("🛑 Message #%d is SPAM: \"%s\"\n", i + 1, messages[i]);
        } else {
            printf("✅ Message #%d is clean: \"%s\"\n", i + 1, messages[i]);
        }
    }
}

int main() {
    char messages[MAX_MESSAGES][MAX_LENGTH];
    int messageCount;

    printf("🎩 Welcome to the Fishy Spam Detection System 🎩\n");
    printf("How many spam messages do you have? (max %d): ", MAX_MESSAGES);
    scanf("%d", &messageCount);
    getchar();  // Clear newline

    if (messageCount > MAX_MESSAGES) {
        printf("🚫 Too many messages! Reducing it to %d right now.\n", MAX_MESSAGES);
        messageCount = MAX_MESSAGES;
    }
    
    feedMeSpamMessages(messages, &messageCount);
    detectSpamMessages(messages, messageCount);

    printf("\n🐟 Thank you for using Fishy Spam Detection System! 🐟\n");
    printf("Remember: Not all fish in the sea are spam! 🌊\n");
    return 0;
}