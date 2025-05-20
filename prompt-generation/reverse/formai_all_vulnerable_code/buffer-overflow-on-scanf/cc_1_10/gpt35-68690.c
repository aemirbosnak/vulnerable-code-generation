//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000
#define MAX_EMAIL_LENGTH 50

struct message {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char body[MAX_MESSAGE_LENGTH];
};

int main() {
    struct message messages[MAX_MESSAGES];

    int message_count = 0;

    int choice;

    do {
        printf("\n1. Compose message");
        printf("\n2. View inbox");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if (message_count < MAX_MESSAGES) {
                    struct message new_message;

                    printf("\nEnter subject: ");
                    scanf(" %[^\n]", new_message.subject);
                    printf("Enter sender email: ");
                    scanf(" %[^\n]", new_message.sender);
                    printf("Enter recipient email: ");
                    scanf(" %[^\n]", new_message.to);
                    printf("Enter message body: ");
                    scanf(" %[^\n]", new_message.body);

                    messages[message_count] = new_message;
                    message_count++;
                } else {
                    printf("\nInbox full!");
                }

                break;
            }

            case 2: {
                if (message_count == 0) {
                    printf("\nInbox empty!");
                } else {
                    printf("\nMessages:\n");

                    for (int i=0; i<message_count; i++) {
                        printf("\n%d. Subject: %s", i+1, messages[i].subject);
                        printf("\n   From: %s", messages[i].sender);
                        printf("\n   To: %s", messages[i].to);
                        printf("\n   Body: %s", messages[i].body);
                    }
                }

                break;
            }

            case 3: {
                printf("\nExiting...");
                break;
            }

            default: {
                printf("\nInvalid choice!");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}