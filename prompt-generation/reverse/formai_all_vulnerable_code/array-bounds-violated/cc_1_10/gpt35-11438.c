//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_MSG_LENGTH 100
#define THRESHOLD 3

// Struct for a single message and its spam count
struct message {
    char content[MAX_MSG_LENGTH];
    int spam_count;
};

// Struct for the overall chat room, containing all messages and the current number of messages
struct chat_room {
    struct message messages[MAX_MESSAGES];
    int num_messages;
};

// Function to check if a message contains spam keywords
int is_spam(char message[MAX_MSG_LENGTH]) {
    char spam_words[][10] = {"viagra", "lottery", "money", "inheritance", "prince"};
    int num_spam_words = 5;

    int i;
    for (i = 0; i < num_spam_words; i++) {
        if(strstr(message, spam_words[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

// Function to add a message to the chat room
void add_message(struct chat_room *room, char message[MAX_MSG_LENGTH]) {
    // Check if message is spam
    int spam = is_spam(message);

    // Add message and spam count to room
    strcpy(room->messages[room->num_messages].content, message);
    room->messages[room->num_messages].spam_count = spam;
    room->num_messages++;

    // Check if new message makes previous messages above the threshold
    int i;
    int thresh_count = 0;
    for (i = room->num_messages-1; i >= 0; i--) {
        if (room->messages[i].spam_count == 1) {
            thresh_count++;
        } else {
            break;
        }
    }

    // Kick out spammer if necessary
    if (thresh_count >= THRESHOLD) {
        printf("\nSpammer detected! Kicking out...\n");
        exit(0);
    }
}

int main() {
    // Initialize chat room
    struct chat_room room;
    room.num_messages = 0;

    // Start chat
    printf("Welcome to the chat room!\n\n");
    while (1) {
        printf("Enter your message: ");
        char msg[MAX_MSG_LENGTH];
        fgets(msg, MAX_MSG_LENGTH, stdin);

        // Remove newline character from message
        msg[strlen(msg)-1] = '\0';

        add_message(&room, msg);
    }

    return 0;
}