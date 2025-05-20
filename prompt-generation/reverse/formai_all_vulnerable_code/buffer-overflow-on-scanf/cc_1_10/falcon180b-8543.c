//Falcon-180B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;
    char input[1024];

    // Initialize the email client
    printf("Welcome to the Apocalypse Email Client!\n");
    printf("In this post-apocalyptic world, communication is key.\n");
    printf("Please enter your name:\n");
    scanf("%s", input);
    printf("Hello, %s! Let's get started.\n\n", input);

    // Main loop for handling user input
    while (1) {
        printf("Please enter a command:\n");
        scanf("%s", input);

        // Check for quit command
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye, %s!\n", input);
            break;
        }

        // Check for send command
        else if (strcmp(input, "send") == 0) {
            printf("Please enter the recipient's name:\n");
            scanf("%s", input);
            printf("Please enter the subject (max %d characters):\n", MAX_SUBJECT_LENGTH);
            scanf("%s", emails[num_emails].subject);
            printf("Please enter the body (max %d characters):\n", MAX_BODY_LENGTH);
            scanf("%s", emails[num_emails].body);
            num_emails++;
            printf("Email sent to %s!\n", input);
        }

        // Check for read command
        else if (strcmp(input, "read") == 0) {
            if (num_emails == 0) {
                printf("No emails to read.\n");
            } else {
                printf("Please enter the email number to read (1-%d):\n", num_emails);
                int email_num;
                scanf("%d", &email_num);
                printf("Subject: %s\n", emails[email_num-1].subject);
                printf("Body:\n%s\n", emails[email_num-1].body);
            }
        }

        // Invalid command
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}