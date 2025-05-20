//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_MESSAGE_LEN 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Recipient;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
    int num_recipients;
    Recipient recipients[MAX_RECIPIENTS];
} Message;

void add_recipient(Message* msg) {
    printf("Enter name: ");
    scanf("%s", msg->recipients[msg->num_recipients].name);
    printf("Enter email: ");
    scanf("%s", msg->recipients[msg->num_recipients].email);
    msg->num_recipients++;
}

void send_message(Message* msg) {
    for (int i = 0; i < msg->num_recipients; i++) {
        printf("Sending message to %s (%s)\n", msg->recipients[i].name, msg->recipients[i].email);
    }
}

int main() {
    Message msg;
    char choice;

    do {
        printf("Mailing List Manager\n");
        printf("1. Create new message\n");
        printf("2. Edit existing message\n");
        printf("3. Send message\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                msg.num_recipients = 0;
                strcpy(msg.subject, "");
                strcpy(msg.message, "");
                break;
            case '2':
                printf("Enter message ID: ");
                scanf("%d", &msg.num_recipients);
                break;
            case '3':
                send_message(&msg);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= '4');

    return 0;
}