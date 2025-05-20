//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }
    strcpy(emails[num_emails].email, email);
    emails[num_emails].subscribed = 1;
    num_emails++;
    printf("Email added: %s\n", email);
}

void remove_email(char* email) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].subscribed = 0;
            printf("Email removed: %s\n", email);
            return;
        }
    }
    printf("Email not found.\n");
}

void send_message(char* message) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (emails[i].subscribed) {
            printf("Sending message to %s: %s\n", emails[i].email, message);
        }
    }
}

int main() {
    char input[MAX_EMAIL_LENGTH];
    while (1) {
        printf("Enter command (add/remove/send/exit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char email[MAX_EMAIL_LENGTH];
            printf("Enter email address: ");
            scanf("%s", email);
            add_email(email);
        } else if (strcmp(input, "remove") == 0) {
            char email[MAX_EMAIL_LENGTH];
            printf("Enter email address: ");
            scanf("%s", email);
            remove_email(email);
        } else if (strcmp(input, "send") == 0) {
            char message[MAX_EMAIL_LENGTH];
            printf("Enter message: ");
            scanf("%s", message);
            send_message(message);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}