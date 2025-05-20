//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
  char sender[MAX_BUFFER_SIZE];
  char recipient[MAX_BUFFER_SIZE];
  char subject[MAX_BUFFER_SIZE];
  char message[MAX_BUFFER_SIZE];
} Email;

Email emails[100];

void readEmail(Email *email) {
  printf("Enter sender: ");
  scanf("%s", email->sender);

  printf("Enter recipient: ");
  scanf("%s", email->recipient);

  printf("Enter subject: ");
  scanf("%s", email->subject);

  printf("Enter message: ");
  scanf("%[^\n]", email->message);

  printf("\n");
}

void sendEmail(Email *email) {
  printf("Sending email to: %s <%s>\n", email->recipient, email->sender);

  printf("Subject: %s\n", email->subject);

  printf("Message:\n%s\n", email->message);

  printf("\n");
}

int main() {
  int i = 0;
  Email email;

  printf("Welcome to the Turing Email Client!\n");

  while (1) {
    printf("Enter 'a' to add a new email, 's' to send an email, or 'q' to quit: ");
    char command;
    scanf("%c", &command);

    switch (command) {
      case 'a':
        readEmail(&emails[i]);
        i++;
        break;
      case 's':
        sendEmail(&emails[i - 1]);
        break;
      case 'q':
        printf("Thank you for using the Turing Email Client! Goodbye!\n");
        return 0;
      default:
        printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}