//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include<stdio.h>
#include<stdlib.h>

typedef struct email {
    int id;
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[1000];
} Email;

Email inbox[50];
int num_emails = 0;

void send_email(char sender[], char recipient[], char subject[], char body[]);
void list_emails();
void read_email(int id);

int main() {
    int choice;
    char sender[50], recipient[50], subject[100], body[1000];

    while(1) {
        printf("Enter 1 to send an email\n");
        printf("Enter 2 to list all emails\n");
        printf("Enter 3 to read an email\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter sender's email address: ");
                scanf("%s", sender);

                printf("Enter recipient's email address: ");
                scanf("%s", recipient);

                printf("Enter subject: ");
                scanf("%s", subject);

                printf("Enter body: ");
                scanf("%s", body);

                send_email(sender, recipient, subject, body);
                break;

            case 2:
                list_emails();
                break;

            case 3:
                printf("Enter email id: ");
                int id;
                scanf("%d", &id);

                read_email(id);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void send_email(char sender[], char recipient[], char subject[], char body[]) {
    Email new_email;
    new_email.id = num_emails;
    num_emails++;

    strcpy(new_email.sender, sender);
    strcpy(new_email.recipient, recipient);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);

    inbox[new_email.id] = new_email;

    printf("Email sent successfully!\n");
}

void list_emails() {
    if(num_emails == 0) {
        printf("Inbox is empty\n");
        return;
    }

    for(int i=0; i<num_emails; i++) {
        printf("%d. Sender: %s\n", inbox[i].id, inbox[i].sender);
        printf("   Recipient: %s\n", inbox[i].recipient);
        printf("   Subject: %s\n", inbox[i].subject);
        printf("   Body: %s\n\n", inbox[i].body);
    }
}

void read_email(int id) {
    if(id < 0 || id >= num_emails) {
        printf("Invalid email id\n");
        return;
    }

    printf("Sender: %s\n", inbox[id].sender);
    printf("Recipient: %s\n", inbox[id].recipient);
    printf("Subject: %s\n", inbox[id].subject);
    printf("Body: %s\n", inbox[id].body);
}