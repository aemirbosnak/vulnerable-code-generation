//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECTS 100
#define MAX_RECIPIENTS 1000
#define MAX_MESSAGE_LENGTH 10000

typedef struct {
    char subject[MAX_SUBJECTS];
    char recipients[MAX_RECIPIENTS][MAX_SUBJECTS];
    char message[MAX_MESSAGE_LENGTH];
} mailing_list;

void add_subject(mailing_list *list) {
    int i = 0;
    char subject[MAX_SUBJECTS];
    printf("Enter a subject: ");
    fgets(subject, MAX_SUBJECTS, stdin);
    while (subject[i]!= '\0') {
        if (!isalpha(subject[i])) {
            printf("Invalid subject.\n");
            return;
        }
        i++;
    }
    strcpy(list->subject, subject);
}

void add_recipient(mailing_list *list, int index) {
    char recipient[MAX_RECIPIENTS][MAX_SUBJECTS];
    printf("Enter recipient %d: ", index + 1);
    fgets(recipient, MAX_RECIPIENTS, stdin);
    strcpy(list->recipients[index], recipient);
}

void compose_message(mailing_list *list) {
    int i = 0;
    char message[MAX_MESSAGE_LENGTH];
    printf("Compose your message:\n");
    while (fgets(message, MAX_MESSAGE_LENGTH, stdin)!= NULL) {
        if (message[0] == '.') {
            if (i == 0) {
                printf("Message cannot be empty.\n");
                return;
            }
            message[strlen(message) - 1] = '\0';
            break;
        }
        i++;
    }
    strcpy(list->message, message);
}

void send_mail(mailing_list *list, int num_recipients) {
    int i = 0;
    while (i < num_recipients) {
        printf("Sending mail to %s...\n", list->recipients[i]);
        i++;
    }
    printf("Mail sent successfully.\n");
}

int main() {
    mailing_list list;
    int num_recipients = 0;

    add_subject(&list);

    while (num_recipients < MAX_RECIPIENTS) {
        printf("Enter 'a' to add a recipient,'s' to send mail, or 'q' to quit:\n");
        char choice;
        scanf("%c", &choice);
        switch (choice) {
        case 'a':
            num_recipients++;
            add_recipient(&list, num_recipients - 1);
            break;
        case's':
            compose_message(&list);
            send_mail(&list, num_recipients);
            break;
        case 'q':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}