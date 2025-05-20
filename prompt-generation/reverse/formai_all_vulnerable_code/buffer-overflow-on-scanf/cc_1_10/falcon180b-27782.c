//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} subscriber;

typedef struct {
    char from[MAX_EMAIL_LEN];
    char to[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} message;

subscriber subscribers[100];
int num_subscribers = 0;

void add_subscriber(char* name, char* email) {
    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void send_message(message* msg) {
    FILE* fp;
    char buffer[MAX_BODY_LEN];
    int len;

    fp = fopen(msg->to, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", msg->to);
        return;
    }

    fprintf(fp, "To: %s\r\n", msg->to);
    fprintf(fp, "From: %s\r\n", msg->from);
    fprintf(fp, "Subject: %s\r\n", msg->subject);
    fprintf(fp, "\r\n");
    fprintf(fp, "%s", msg->body);

    fclose(fp);
}

void send_message_to_subscribers(message* msg) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        send_message(msg);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);

    add_subscriber(name, email);

    printf("Enter the subject of the message: ");
    scanf("%s", subject);

    printf("Enter the message body:\n");
    fgets(body, MAX_BODY_LEN, stdin);

    message msg;
    strcpy(msg.from, email);
    strcpy(msg.to, email);
    strcpy(msg.subject, subject);
    strcpy(msg.body, body);

    send_message_to_subscribers(&msg);

    printf("Message sent successfully!\n");

    return 0;
}