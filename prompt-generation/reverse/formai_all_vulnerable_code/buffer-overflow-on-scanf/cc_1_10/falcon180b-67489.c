//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} message;

contact contacts[1000]; // maximum number of contacts
int num_contacts;

void add_contact(char *name, char *email) {
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_message(char *subject, char *message) {
    printf("Sending message with subject: %s\n", subject);
    printf("Message:\n%s\n", message);
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    do {
        printf("1. Add contact\n");
        printf("2. Send message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(name, email);
                break;
            case 2:
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter message: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin); // read message with newline
                send_message(subject, message);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}