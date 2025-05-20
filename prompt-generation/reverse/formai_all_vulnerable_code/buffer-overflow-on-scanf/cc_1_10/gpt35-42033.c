//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>

// Define the maximum number of messages that can be stored in the client
#define MAX_MESSAGES 100

// Define the maximum length of a message subject and body
#define MAX_SUBJECT_LENGTH 1000
#define MAX_BODY_LENGTH 10000

// Define a message struct that contains a subject and body
struct message {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    // Create an array to hold messages
    struct message messages[MAX_MESSAGES];

    // Initialize the number of messages to zero
    int num_messages = 0;

    // Loop until the user quits the client
    while (1) {
        // Print the menu
        printf("Email Client Menu\n");
        printf("==================\n");
        printf("1. Compose message\n");
        printf("2. View messages\n");
        printf("3. Quit\n");

        // Get the user's choice
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Check if the maximum number of messages has been reached
                if (num_messages >= MAX_MESSAGES) {
                    printf("You have reached the maximum number of messages.\n");
                    break;
                }

                // Get the subject and body of the message from the user
                printf("Enter the subject of the message: ");
                char subject[MAX_SUBJECT_LENGTH];
                scanf("%s", subject);

                printf("Enter the body of the message: ");
                char body[MAX_BODY_LENGTH];
                scanf("%s", body);

                // Create the message and add it to the array
                struct message new_message;
                strcpy(new_message.subject, subject);
                strcpy(new_message.body, body);
                messages[num_messages++] = new_message;

                printf("Message sent!\n");
                break;

            case 2:
                // Check if there are any messages to view
                if (num_messages == 0) {
                    printf("There are no messages to view.\n");
                    break;
                }

                // Print out each message
                for (int i = 0; i < num_messages; i++) {
                    printf("Subject: %s\n", messages[i].subject);
                    printf("Body: %s\n", messages[i].body);
                }

                break;

            case 3:
                // Quit the program
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}