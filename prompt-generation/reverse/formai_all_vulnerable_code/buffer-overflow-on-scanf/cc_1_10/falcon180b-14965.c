//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

struct mailing_list {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct message {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

void add_contact(struct mailing_list *list, int count, char *name, char *email) {
    strcpy(list[count].name, name);
    strcpy(list[count].email, email);
}

void send_message(struct mailing_list *list, int count, char *subject, char *message) {
    struct message msg;
    strcpy(msg.subject, subject);
    strcpy(msg.message, message);

    for (int i = 0; i < count; i++) {
        printf("Sending message to %s (%s)\n", list[i].name, list[i].email);
        printf("Subject: %s\n", msg.subject);
        printf("Message:\n%s\n", msg.message);
    }
}

int main() {
    int count = 0;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    struct mailing_list list[100];

    while (1) {
        printf("\n1. Add contact\n2. Send message\n3. Exit\n");
        scanf("%d", &count);

        switch (count) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(list, count, name, email);
            break;

        case 2:
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter message: ");
            scanf("%s", message);
            send_message(list, count, subject, message);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid option\n");
        }
    }

    return 0;
}