//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 5
#define MAX_NAME_LEN 20

typedef struct {
    char sender[MAX_NAME_LEN];
    char message[100];
} Message;

typedef struct {
    char name[MAX_NAME_LEN];
    Message messages[MAX_MESSAGES];
    int message_count;
} Character;

void sendMessage(Character *sender, Character *receiver) {
    if (receiver->message_count < MAX_MESSAGES) {
        printf("Enter your message, %s: ", sender->name);
        getchar(); // To consume the newline character
        fgets(receiver->messages[receiver->message_count].message, sizeof(receiver->messages[receiver->message_count].message), stdin);
        strncpy(receiver->messages[receiver->message_count].sender, sender->name, MAX_NAME_LEN);
        receiver->message_count++;
        printf("Message sent from %s to %s!\n", sender->name, receiver->name);
    } else {
        printf("%s cannot send more messages to %s as the message limit has been reached!\n", sender->name, receiver->name);
    }
}

void viewMessages(Character *character) {
    printf("Messages for %s:\n", character->name);
    for (int i = 0; i < character->message_count; i++) {
        printf("%s: %s", character->messages[i].sender, character->messages[i].message);
    }
    if (character->message_count == 0) {
        printf("No messages to display.\n");
    }
}

int main() {
    Character romeo = {"Romeo", {}, 0};
    Character juliet = {"Juliet", {}, 0};
    int choice;

    printf("Welcome to the Romeo & Juliet Interaction Program!\n");
    printf("Each character can send messages to one another.\n");

    do {
        printf("\nChoose an action:\n");
        printf("1. Romeo sends a message to Juliet\n");
        printf("2. Juliet sends a message to Romeo\n");
        printf("3. View messages for Romeo\n");
        printf("4. View messages for Juliet\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sendMessage(&romeo, &juliet);
                break;
            case 2:
                sendMessage(&juliet, &romeo);
                break;
            case 3:
                viewMessages(&romeo);
                break;
            case 4:
                viewMessages(&juliet);
                break;
            case 5:
                printf("Thank you for using the program! Until next we meet...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}