//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 500
#define MAX_NUM_RECIPIENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Recipient;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
    time_t timestamp;
} Message;

void add_recipient(Recipient *recipient_list, int num_recipients, char *name, char *email) {
    if (num_recipients >= MAX_NUM_RECIPIENTS) {
        printf("Cannot add more recipients. Maximum limit reached.\n");
        return;
    }

    strncpy(recipient_list[num_recipients].name, name, MAX_NAME_LEN);
    strncpy(recipient_list[num_recipients].email, email, MAX_EMAIL_LEN);
    num_recipients++;
}

void send_message(Recipient *recipient_list, int num_recipients, char *subject, char *message) {
    Message msg;

    strncpy(msg.subject, subject, MAX_SUBJECT_LEN);
    strncpy(msg.message, message, MAX_MESSAGE_LEN);
    msg.timestamp = time(NULL);

    printf("Sending message to %d recipients...\n", num_recipients);
    for (int i = 0; i < num_recipients; i++) {
        printf("Sending message to %s (%s)\n", recipient_list[i].name, recipient_list[i].email);
    }
}

int main() {
    Recipient recipient_list[MAX_NUM_RECIPIENTS];
    int num_recipients = 0;

    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    while (1) {
        printf("Enter recipient's name (or 'q' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter recipient's email address: ");
        scanf("%s", email);

        add_recipient(recipient_list, num_recipients, name, email);
    }

    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter message: ");
    scanf("%s", message);

    send_message(recipient_list, num_recipients, subject, message);

    return 0;
}