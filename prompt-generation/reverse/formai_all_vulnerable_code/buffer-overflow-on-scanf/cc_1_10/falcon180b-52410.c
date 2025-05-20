//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPIENTS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 5000

struct recipient {
    char name[50];
    char email[100];
};

struct message {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

void add_recipient(struct recipient* recipients, int count, char* name, char* email) {
    if (count >= MAX_RECIPIENTS) {
        printf("Error: Maximum number of recipients reached.\n");
        return;
    }

    strcpy(recipients[count].name, name);
    strcpy(recipients[count].email, email);
    count++;
}

void send_message(struct recipient* recipients, int count, struct message* message) {
    for (int i = 0; i < count; i++) {
        printf("Sending message to %s (%s)\n", recipients[i].name, recipients[i].email);
        printf("Subject: %s\n", message->subject);
        printf("Body:\n%s\n", message->body);
        printf("\n");
    }
}

int main() {
    int recipient_count = 0;
    struct recipient recipients[MAX_RECIPIENTS];
    struct message message;

    printf("Enter recipient name: ");
    scanf("%s", message.subject);
    printf("Enter recipient email: ");
    scanf("%s", message.body);

    add_recipient(recipients, recipient_count, message.subject, message.body);

    printf("Enter recipient name: ");
    scanf("%s", message.subject);
    printf("Enter recipient email: ");
    scanf("%s", message.body);

    add_recipient(recipients, recipient_count, message.subject, message.body);

    send_message(recipients, recipient_count, &message);

    return 0;
}