//FormAI DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define MAX_NUM_EMAILS 1000

struct Email {
  char subject[MAX_SUBJECT_LEN];
  char body[MAX_BODY_LEN];
  char sender[MAX_SUBJECT_LEN];
  char receiver[MAX_SUBJECT_LEN];
};

int num_emails = 0;
struct Email emails[MAX_NUM_EMAILS];

void send_email(char* subject, char* body, char* sender, char* receiver) {
  if (num_emails >= MAX_NUM_EMAILS) {
    printf("Error: Maximum number of emails reached\n");
    return;
  }

  struct Email email;
  strcpy(email.subject, subject);
  strcpy(email.body, body);
  strcpy(email.sender, sender);
  strcpy(email.receiver, receiver);
  emails[num_emails++] = email;

  printf("Email sent from %s to %s\n", sender, receiver);
  printf("Subject: %s\n", subject);
  printf("Body: %s\n", body);
}

void display_emails() {
  printf("--------------------------------------------------\n");
  printf("%-20s %-20s %-20s %-20s\n", "Sender", "Receiver", "Subject", "Body");
  printf("--------------------------------------------------\n");

  for (int i = 0; i < num_emails; i++) {
    struct Email email = emails[i];
    printf("%-20s %-20s %-20s %-20s\n", email.sender, email.receiver, email.subject, email.body);
  }

  printf("--------------------------------------------------\n");
}

int main() {
  char subject[MAX_SUBJECT_LEN];
  char body[MAX_BODY_LEN];
  char sender[MAX_SUBJECT_LEN];
  char receiver[MAX_SUBJECT_LEN];

  while (1) {
    printf("\nMenu:\n");
    printf("1. Send email\n");
    printf("2. Display emails\n");
    printf("3. Exit\n");

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter subject: ");
        scanf("%s", subject);
        printf("Enter body: ");
        scanf("%s", body);
        printf("Enter sender: ");
        scanf("%s", sender);
        printf("Enter receiver: ");
        scanf("%s", receiver);
        send_email(subject, body, sender, receiver);
        break;

      case 2:
        display_emails();
        break;

      case 3:
        printf("Quitting program...\n");
        exit(0);

      default:
        printf("Error: Invalid choice\n");
        break;
    }
  }

  return 0;
}