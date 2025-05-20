//FormAI DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum message length
#define MAX_MESSAGE_LENGTH 100

// Define maximum number of messages to be stored
#define MAX_NUM_MESSAGES 1000

// Define maximum length of each word in the message
#define MAX_WORD_LENGTH 20

// Define maximum length of blacklisted words
#define MAX_BLACKLIST_LENGTH 30

// Struct to store message and its status
typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    int status; // 1 for clean messages, 0 for spam messages
} Message;

// Function to check if a word is in the blacklist
int is_blacklisted(char *word, char blacklist[][MAX_BLACKLIST_LENGTH], int num_blacklisted_words) {
    for(int i=0; i<num_blacklisted_words; i++) {
        if(strcmp(word, blacklist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a message is spam
int is_spam(char *message, char blacklist[][MAX_BLACKLIST_LENGTH], int num_blacklisted_words) {
    char words[MAX_MESSAGE_LENGTH][MAX_WORD_LENGTH];
    int count_words = 0;

    // Break message into words
    char *token = strtok(message, " ");
    while(token != NULL) {
        strcpy(words[count_words], token);
        count_words++;
        token = strtok(NULL, " ");
    }

    // Check if any word is blacklisted
    for(int i=0; i<count_words; i++) {
        if(is_blacklisted(words[i], blacklist, num_blacklisted_words)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Message messages[MAX_NUM_MESSAGES];
    int num_messages = 0;

    // Define list of blacklisted words
    char blacklist[][MAX_BLACKLIST_LENGTH] = {"buy", "money", "free", "offer", "discount"};

    // Get messages from user input
    char input[MAX_MESSAGE_LENGTH];
    while(num_messages < MAX_NUM_MESSAGES) {
        printf("Enter message: ");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        sscanf(input, "%[^\n]", messages[num_messages].message); // Remove newline character from input

        // Check if message is spam
        messages[num_messages].status = is_spam(messages[num_messages].message, blacklist, 5);

        num_messages++;

        // Check if user wants to add more messages
        printf("Enter another message? (y/n): ");
        fgets(input, sizeof(input), stdin);

        if(input[0] == 'n') {
            break;
        }
    }

    // Print all messages and their status
    for(int i=0; i<num_messages; i++) {
        printf("Message %d: %s\n", i+1, messages[i].message);
        if(messages[i].status == 1) {
            printf("Status: Clean message.\n");
        } else {
            printf("Status: Spam message.\n");
        }
    }

    return 0;
}