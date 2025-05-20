//FormAI DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 500
#define MAX_SUBJECT_SIZE 100
#define MAX_RECIPIENT_SIZE 50
#define MAX_NUM_ATTACHMENTS 5
#define MAX_ATTACHMENT_SIZE 100

typedef struct Email {
    char recipient[MAX_RECIPIENT_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_EMAIL_SIZE];
    char attachments[MAX_NUM_ATTACHMENTS][MAX_ATTACHMENT_SIZE];
    int num_attachments;
} Email;

void send_email(Email email) {
    printf("Sending email...\n");
    printf("Recipient: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
    if (email.num_attachments > 0) {
        printf("Attachments:\n");
        for (int i = 0; i < email.num_attachments; i++) {
            printf("%s\n", email.attachments[i]);
        }
    }
}

int main() {
    Email email;
    printf("Enter recipient email address: ");
    fgets(email.recipient, MAX_RECIPIENT_SIZE, stdin);
    email.recipient[strcspn(email.recipient, "\n")] = '\0'; // remove newline character
    printf("Enter subject: ");
    fgets(email.subject, MAX_SUBJECT_SIZE, stdin);
    email.subject[strcspn(email.subject, "\n")] = '\0'; // remove newline character
    printf("Enter email body: ");
    fgets(email.body, MAX_EMAIL_SIZE, stdin);
    email.body[strcspn(email.body, "\n")] = '\0'; // remove newline character
    printf("Enter number of attachments (max %d): ", MAX_NUM_ATTACHMENTS);
    scanf("%d", &email.num_attachments);
    getchar(); // remove newline character
    for (int i = 0; i < email.num_attachments; i++) {
        printf("Enter attachment %d: ", i+1);
        fgets(email.attachments[i], MAX_ATTACHMENT_SIZE, stdin);
        email.attachments[i][strcspn(email.attachments[i], "\n")] = '\0'; // remove newline character
    }
    send_email(email);
    return 0;
}