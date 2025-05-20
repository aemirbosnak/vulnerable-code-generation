//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Message;

Contact contacts[100];
int num_contacts = 0;

void add_contact(char* name, char* email) {
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

int find_contact(char* email) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

void send_message(char* subject, char* body, int recipient_index) {
    Message message;
    strcpy(message.subject, subject);
    strcpy(message.body, body);

    printf("Sending message to %s...\n", contacts[recipient_index].name);
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "add_contact") == 0) {
            char* name;
            char* email;
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(name, email);
        } else if (strcmp(input, "send_message") == 0) {
            char* subject;
            char* body;
            int recipient_index;
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter body: ");
            scanf("%s", body);
            printf("Enter recipient index: ");
            scanf("%d", &recipient_index);
            send_message(subject, body, recipient_index);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}