//FormAI DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 500
#define MAX_SUBJECT_LENGTH 50
#define MAX_EMAILS 20

struct Email {
  char subject[MAX_SUBJECT_LENGTH];
  char message[MAX_MSG_LENGTH];
  char to[50];
};

struct Email inbox[MAX_EMAILS];
int numEmails = 0;

// Sends an email and adds it to the inbox
void sendEmail(char *to, char *subj, char *msg) {
  struct Email newEmail;
  strncpy(newEmail.to, to, 50);
  strncpy(newEmail.subject, subj, MAX_SUBJECT_LENGTH);
  strncpy(newEmail.message, msg, MAX_MSG_LENGTH);
  inbox[numEmails++] = newEmail;
  printf("Message sent successfully!\n");
}

// Prints all emails in the inbox
void printInbox() {
  printf("Inbox:\n");
  for(int i = 0; i < numEmails; i++) {
    printf("To: %s\n", inbox[i].to);
    printf("Subject: %s\n", inbox[i].subject);
    printf("Message: %s\n", inbox[i].message);
    printf("\n");
  }
}

int main() {
  printf("Welcome to the C Email Client!\n");

  while(1) {
    printf("\nEnter 's' to send an email or 'p' to print inbox: ");
    char choice;
    scanf("%c", &choice);

    if(choice == 's') {
      // Clear input buffer
      while((getchar()) != '\n');

      char to[50];
      printf("\nEnter recipient email address: ");
      fgets(to, 50, stdin);
      to[strcspn(to, "\n")] = '\0'; // Remove newline character

      char subj[MAX_SUBJECT_LENGTH];
      printf("Enter email subject: ");
      fgets(subj, MAX_SUBJECT_LENGTH, stdin);
      subj[strcspn(subj, "\n")] = '\0'; // Remove newline character

      char msg[MAX_MSG_LENGTH];
      printf("Enter email message: ");
      fgets(msg, MAX_MSG_LENGTH, stdin);
      msg[strcspn(msg, "\n")] = '\0'; // Remove newline character

      sendEmail(to, subj, msg);
    }
    else if(choice == 'p') {
      // Clear input buffer
      while((getchar()) != '\n');

      printInbox();
    }
    else {
      // Clear input buffer
      while((getchar()) != '\n');

      printf("\nInvalid choice. Please try again.\n");
    }
  }
  return 0;
}