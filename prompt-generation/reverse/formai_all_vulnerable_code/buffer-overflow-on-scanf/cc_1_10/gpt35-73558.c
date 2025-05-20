//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 100

struct Email {
  char to[50];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
};

struct Email inbox[MAX_EMAILS];
int num_emails = 0;

void display_inbox() {
  if (num_emails == 0) {
    printf("Your inbox is empty!\n");
    return;
  }

  printf("\n----- INBOX -----\n");
  for (int i = 0; i < num_emails; i++) {
    printf("(%d) From: %s | Subject: %s | Body: %s\n",
           i + 1, inbox[i].to, inbox[i].subject, inbox[i].body);
  }
}

void send_email() {
  struct Email new_email;
  printf("\n----- NEW EMAIL -----\n");
  printf("To: ");
  fgets(new_email.to, 50, stdin);
  new_email.to[strcspn(new_email.to, "\n")] = 0;
  printf("Subject: ");
  fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
  new_email.subject[strcspn(new_email.subject, "\n")] = 0;
  printf("Body: ");
  fgets(new_email.body, MAX_BODY_LENGTH, stdin);
  new_email.body[strcspn(new_email.body, "\n")] = 0;

  inbox[num_emails++] = new_email;
  printf("Email sent successfully!\n");
}

int main() {
  int choice = 0;

  do {
    printf("\n----- MENU -----\n");
    printf("1. View Inbox\n");
    printf("2. Send Email\n");
    printf("3. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline character

    switch (choice) {
      case 1:
        display_inbox();
        break;
      case 2:
        send_email();
        break;
      case 3:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != 3);

  return 0;
}