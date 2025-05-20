//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECTS 100
#define MAX_SENDERS 100
#define MAX_RECIPIENTS 100
#define MAX_BODIES 1000
#define MAX_ATTACHMENTS 100

typedef struct {
    char subject[MAX_SUBJECTS];
    char sender[MAX_SENDERS];
    char recipients[MAX_RECIPIENTS];
    char body[MAX_BODIES];
} Email;

typedef struct {
    char filename[MAX_ATTACHMENTS];
    char content[MAX_ATTACHMENTS];
} Attachment;

Email emails[100];
Attachment attachments[100];

int num_emails = 0;
int num_attachments = 0;

void add_email() {
    printf("Enter subject: ");
    scanf("%s", emails[num_emails].subject);
    printf("Enter sender: ");
    scanf("%s", emails[num_emails].sender);
    printf("Enter recipients (separated by commas): ");
    scanf("%s", emails[num_emails].recipients);
    printf("Enter body: ");
    scanf("%[^\n]", emails[num_emails].body);
    printf("\n");

    num_emails++;
}

void add_attachment() {
    printf("Enter filename: ");
    scanf("%s", attachments[num_attachments].filename);
    printf("Enter content: ");
    scanf("%[^\n]", attachments[num_attachments].content);
    printf("\n");

    num_attachments++;
}

void send_email() {
    printf("Sending email...\n");
    printf("Subject: %s\n", emails[num_emails-1].subject);
    printf("Sender: %s\n", emails[num_emails-1].sender);
    printf("Recipients: %s\n", emails[num_emails-1].recipients);
    printf("Body:\n%s\n", emails[num_emails-1].body);

    for (int i = 0; i < num_attachments; i++) {
        printf("Attachment %d:\nFilename: %s\nContent:\n%s\n", i+1, attachments[i].filename, attachments[i].content);
    }
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        printf("\nEmail Client\n");
        printf("1. Add email\n");
        printf("2. Add attachment\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                add_attachment();
                break;
            case 3:
                send_email();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}