//Gemma-7B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Recipients 5

typedef struct Email {
    char sender[50];
    char recipient[MAX_Recipients][50];
    char subject[50];
    char message[1000];
} Email;

Email emails[100];

void readEmail(Email *email) {
    printf("From: %s\n", email->sender);
    printf("To: ");
    for (int i = 0; email->recipient[i][0] != '\0'; i++) {
        printf("%s, ", email->recipient[i]);
    }
    printf("\nSubject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
}

void writeEmail(Email *email) {
    printf("Enter sender: ");
    scanf("%s", email->sender);

    printf("Enter recipients (separate with commas): ");
    char recipient[MAX_Recipients][50];
    for (int i = 0; recipient[i][0] != '\0'; i++) {
        scanf("%s", recipient[i]);
        strcpy(email->recipient[i], recipient[i]);
    }

    printf("Enter subject: ");
    scanf("%s", email->subject);

    printf("Enter message: ");
    scanf("%[^\n]%*c", email->message);

    email->message[strcspn(email->message, "\n")] = '\0';
}

int main() {
    int email_index = 0;

    while (1) {
        char command[20];

        printf("Enter command (add, read, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            writeEmail(&emails[email_index]);
            email_index++;
        } else if (strcmp(command, "read") == 0) {
            readEmail(&emails[email_index - 1]);
        } else if (strcmp(command, "quit") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}