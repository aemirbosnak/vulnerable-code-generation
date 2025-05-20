//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

typedef struct {
  char sender[50];
  char recipient[50];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
  int priority;
} Email;

Email* emails[MAX_EMAILS];
int num_emails = 0;

void send_email(char* sender, char* recipient, char* subject, char* body, int priority) {
  Email* new_email = (Email*) malloc(sizeof(Email));
  strcpy(new_email->sender, sender);
  strcpy(new_email->recipient, recipient);
  strcpy(new_email->subject, subject);
  strcpy(new_email->body, body);
  new_email->priority = priority;

  if (num_emails < MAX_EMAILS) {
    emails[num_emails] = new_email;
    num_emails++;
    printf("Email sent successfully!\n");
  } else {
    printf("Unable to send email. Inbox full.\n");
    free(new_email);
  }
}

void display_emails() {
  printf("Inbox:\n");
  for (int i = 0; i < num_emails; i++) {
    printf("From: %s\n", emails[i]->sender);
    printf("To: %s\n", emails[i]->recipient);
    printf("Subject: %s\n", emails[i]->subject);
    printf("Body: %s\n", emails[i]->body);
    printf("Priority: %d\n", emails[i]->priority);
    printf("---------------------------------\n");
  }
}

int main() {
  printf("Welcome to BraveMail!\n\n");

  while (1) {
    printf("Select an option:\n");
    printf("1. Compose email\n");
    printf("2. View inbox\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice) {
      case 1: {
        char sender[50], recipient[50], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];
        int priority;

        printf("Enter sender name: ");
        fgets(sender, 50, stdin);
        sender[strcspn(sender, "\n")] = '\0';

        printf("Enter recipient name: ");
        fgets(recipient, 50, stdin);
        recipient[strcspn(recipient, "\n")] = '\0';

        printf("Enter subject: ");
        fgets(subject, MAX_SUBJECT_LENGTH, stdin);
        subject[strcspn(subject, "\n")] = '\0';

        printf("Enter body: ");
        fgets(body, MAX_BODY_LENGTH, stdin);
        body[strcspn(body, "\n")] = '\0';

        printf("Enter priority (1-5): ");
        scanf("%d", &priority);
        getchar();

        send_email(sender, recipient, subject, body, priority);

        break;
      }
      case 2: {
        display_emails();
        break;
      }
      case 3: {
        printf("Exiting BraveMail. Goodbye!");
        exit(0);
      }
      default: {
        printf("Invalid choice. Try again.\n");
        break;
      }
    }
  }

  return 0;
}