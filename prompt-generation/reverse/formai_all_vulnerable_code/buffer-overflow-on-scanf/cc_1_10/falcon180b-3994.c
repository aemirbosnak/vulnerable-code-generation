//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 128
#define MAX_SUBJECT_LEN 256
#define MAX_BODY_LEN 1024
#define MAX_RECIPIENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    time_t sent_time;
} message;

void add_recipient(recipient *list, int num_recipients, char *name, char *email) {
    if (num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Too many recipients.\n");
        return;
    }

    strncpy(list[num_recipients].name, name, MAX_NAME_LEN);
    strncpy(list[num_recipients].email, email, MAX_EMAIL_LEN);

    num_recipients++;
}

int send_message(recipient *list, int num_recipients, char *subject, char *body) {
    message msg;

    strncpy(msg.subject, subject, MAX_SUBJECT_LEN);
    strncpy(msg.body, body, MAX_BODY_LEN);

    time(&msg.sent_time);

    for (int i = 0; i < num_recipients; i++) {
        printf("Sending message to %s (%s)\n", list[i].name, list[i].email);
    }

    return 0;
}

int main() {
    recipient list[MAX_RECIPIENTS];
    int num_recipients = 0;

    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter recipient information:\n");

    while (1) {
        printf("Name: ");
        scanf("%s", name);

        printf("Email: ");
        scanf("%s", email);

        add_recipient(list, num_recipients, name, email);

        printf("Add another recipient? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'n') {
            break;
        }
    }

    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];

    printf("Enter message subject:\n");
    scanf("%s", subject);

    printf("Enter message body:\n");
    scanf("%[^\n]", body);

    send_message(list, num_recipients, subject, body);

    return 0;
}