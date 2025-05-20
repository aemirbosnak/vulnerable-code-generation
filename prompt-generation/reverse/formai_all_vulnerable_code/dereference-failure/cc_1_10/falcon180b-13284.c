//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: irregular
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
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
    int num_recipients;
    recipient *recipients;
} email;

void add_recipient(email *e) {
    recipient *recipient_list = e->recipients;
    int num_recipients = e->num_recipients;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter recipient name: ");
    scanf("%s", name);
    printf("Enter recipient email: ");
    scanf("%s", email);

    recipient *new_recipient = (recipient*)malloc(sizeof(recipient));
    strcpy(new_recipient->name, name);
    strcpy(new_recipient->email, email);
    recipient_list[num_recipients] = *new_recipient;
    num_recipients++;
    e->num_recipients = num_recipients;
}

void send_email(email *e) {
    recipient *recipient_list = e->recipients;
    int num_recipients = e->num_recipients;

    printf("Sending email to %d recipients:\n", num_recipients);
    for (int i = 0; i < num_recipients; i++) {
        printf("To: %s <%s>\n", recipient_list[i].name, recipient_list[i].email);
    }
}

int main() {
    email e;
    e.num_recipients = 0;
    e.recipients = NULL;

    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];

    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email message: ");
    scanf("%s", message);

    strcpy(e.subject, subject);
    strcpy(e.message, message);

    int choice;
    do {
        printf("\n1. Add recipient\n2. Send email\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_recipient(&e);
                break;
            case 2:
                send_email(&e);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}