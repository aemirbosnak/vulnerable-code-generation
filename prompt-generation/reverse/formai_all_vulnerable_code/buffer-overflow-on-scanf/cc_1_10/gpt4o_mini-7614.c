//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGES 100
#define MIN_WORD_LENGTH 5

typedef struct {
    int id;
    char sender[50];
    char message[256];
} Message;

void loveMessage(int id, const char *sender, const char *message) {
    printf("\nDear %s,\n", sender);
    printf("Your message with ID [%d] is like a sweet melody in my heart.\n", id);
    printf("Here's what you've sent:\n");
    printf("\"%s\"\n", message);
    printf("Such beauty in words, keep this passion flowing!\n");
}

void heartBreaker(Message msg) {
    printf("\nOh no, %s! Your message with ID [%d] seems like spam...\n", msg.sender, msg.id);
    printf("Your words were too overwhelming, let us trim the excess:\n");
    printf("\"%s\"\n", msg.message);
    printf("Love should be gentle, not brimming with mere words.\n");
}

bool isSpam(char *message) {
    int wordCount = 0;
    char *token = strtok(message, " ");
    while (token != NULL) {
        if (strlen(token) >= MIN_WORD_LENGTH) {
            wordCount++;
        }
        token = strtok(NULL, " ");
    }
    return wordCount > 10; // A message is considered spam if it has more than 10 long words
}

int main() {
    Message messages[MAX_MESSAGES];
    int messageCount = 0;

    printf("Welcome to the Romantic Spam Detection System!\n");

    // Input messages for detection
    while (messageCount < MAX_MESSAGES) {
        printf("Enter the ID of your message (negative number to quit): ");
        int id;
        scanf("%d", &id);
        if (id < 0) break;
        
        printf("Enter your name (sender): ");
        scanf("%s", messages[messageCount].sender);
        
        printf("Enter your message: ");
        getchar(); // To consume the newline character
        fgets(messages[messageCount].message, sizeof(messages[messageCount].message), stdin);
        messages[messageCount].message[strcspn(messages[messageCount].message, "\n")] = 0; // Remove trailing newline

        if (isSpam(messages[messageCount].message)) {
            heartBreaker(messages[messageCount]);
        } else {
            loveMessage(messages[messageCount].id, messages[messageCount].sender, messages[messageCount].message);
        }

        messageCount++;
    }

    printf("\nThank you for sharing your heartfelt words with us!\n");
    printf("Remember, love is not about the number of words, but the essence they carry.\n");
    return 0;
}