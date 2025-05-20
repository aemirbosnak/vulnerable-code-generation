//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_NUM_RECIPIENTS 10

typedef struct {
    char name[50];
    char email[100];
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_recipients;
    recipient recipients[MAX_NUM_RECIPIENTS];
} email;

void send_email(email* msg) {
    printf("Sending email...\n");
    printf("Subject: %s\n", msg->subject);
    printf("Body:\n%s\n", msg->body);
    printf("Recipients:\n");
    for (int i = 0; i < msg->num_recipients; i++) {
        printf("%s <%s>\n", msg->recipients[i].name, msg->recipients[i].email);
    }
}

int main() {
    email msg;

    printf("Enter your name: ");
    scanf("%s", msg.recipients[0].name);
    printf("Enter your email: ");
    scanf("%s", msg.recipients[0].email);

    int num_recipients = 1;
    printf("Enter number of additional recipients (0 to %d): ", MAX_NUM_RECIPIENTS - 1);
    scanf("%d", &num_recipients);

    for (int i = 1; i < num_recipients + 1; i++) {
        printf("Enter name of recipient %d: ", i);
        scanf("%s", msg.recipients[i].name);
        printf("Enter email of recipient %d: ", i);
        scanf("%s", msg.recipients[i].email);
    }

    printf("Enter email subject: ");
    scanf("%s", msg.subject);

    printf("Enter email body:\n");
    fgets(msg.body, MAX_BODY_LENGTH, stdin);

    send_email(&msg);

    return 0;
}