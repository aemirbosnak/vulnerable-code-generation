//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_STRING_LENGTH 100

typedef struct Email {
  char sender[MAX_STRING_LENGTH];
  char recipient[MAX_STRING_LENGTH];
  char subject[MAX_STRING_LENGTH];
  char body[MAX_STRING_LENGTH];
} Email;

int main() {
  Email inbox[MAX_EMAILS];
  int num_emails = 0;
  
  while (1) {
    printf("Enter option number:\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");

    int option = 0;
    scanf("%d", &option);
    
    if (option == 1) {
      char sender[MAX_STRING_LENGTH];
      char recipient[MAX_STRING_LENGTH];
      char subject[MAX_STRING_LENGTH];
      char body[MAX_STRING_LENGTH];

      printf("Enter sender email address: ");
      scanf("%s", sender);

      printf("Enter recipient email address: ");
      scanf("%s", recipient);

      printf("Enter email subject: ");
      scanf("%s", subject);

      printf("Enter email body: ");
      scanf("%s", body);

      Email email;
      strcpy(email.sender, sender);
      strcpy(email.recipient, recipient);
      strcpy(email.subject, subject);
      strcpy(email.body, body);

      inbox[num_emails++] = email;
      printf("Email sent successfully!\n");
    } else if (option == 2) {
      if (num_emails == 0) {
        printf("No emails in inbox\n");
      } else {
        printf("Inbox:\n");
        for (int i = 0; i < num_emails; i++) {
          printf("Email %d:\n", i+1);
          printf("From: %s\n", inbox[i].sender);
          printf("To: %s\n", inbox[i].recipient);
          printf("Subject: %s\n", inbox[i].subject);
          printf("Body: %s\n\n", inbox[i].body);
        }
      }
    } else if (option == 3) {
      printf("Exiting program. Goodbye!\n");
      return 0;
    } else {
      printf("Invalid option number\n");
    }
  }
}