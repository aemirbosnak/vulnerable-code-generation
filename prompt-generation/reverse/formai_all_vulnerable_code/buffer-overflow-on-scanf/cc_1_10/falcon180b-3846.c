//Falcon-180B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char name[MAX_SUBJECT_LENGTH];
    char email[MAX_SUBJECT_LENGTH];
} recipient;

typedef struct {
    char name[MAX_SUBJECT_LENGTH];
    char path[MAX_BODY_LENGTH];
} attachment;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_recipients;
    recipient recipients[MAX_RECIPIENTS];
    int num_attachments;
    attachment attachments[MAX_ATTACHMENTS];
} email;

void send_email(email* msg) {
    printf("Sending email...\n");
    printf("Subject: %s\n", msg->subject);
    printf("Body:\n%s\n", msg->body);
    for (int i = 0; i < msg->num_recipients; i++) {
        printf("Recipient %d:\nName: %s\nEmail: %s\n", i + 1, msg->recipients[i].name, msg->recipients[i].email);
    }
    for (int i = 0; i < msg->num_attachments; i++) {
        printf("Attachment %d:\nName: %s\nPath: %s\n", i + 1, msg->attachments[i].name, msg->attachments[i].path);
    }
}

int main() {
    email msg;

    printf("Enter subject (max %d characters):\n", MAX_SUBJECT_LENGTH - 1);
    scanf("%s", msg.subject);

    printf("Enter body (max %d characters):\n", MAX_BODY_LENGTH - 1);
    scanf("%[^\n]", msg.body);

    printf("Enter number of recipients (max %d):\n", MAX_RECIPIENTS);
    scanf("%d", &msg.num_recipients);

    for (int i = 0; i < msg.num_recipients; i++) {
        printf("Enter recipient %d name (max %d characters):\n", i + 1, MAX_SUBJECT_LENGTH - 1);
        scanf("%s", msg.recipients[i].name);

        printf("Enter recipient %d email (max %d characters):\n", i + 1, MAX_SUBJECT_LENGTH - 1);
        scanf("%s", msg.recipients[i].email);
    }

    printf("Enter number of attachments (max %d):\n", MAX_ATTACHMENTS);
    scanf("%d", &msg.num_attachments);

    for (int i = 0; i < msg.num_attachments; i++) {
        printf("Enter attachment %d name (max %d characters):\n", i + 1, MAX_SUBJECT_LENGTH - 1);
        scanf("%s", msg.attachments[i].name);

        printf("Enter attachment %d path (max %d characters):\n", i + 1, MAX_BODY_LENGTH - 1);
        scanf("%s", msg.attachments[i].path);
    }

    send_email(&msg);

    return 0;
}