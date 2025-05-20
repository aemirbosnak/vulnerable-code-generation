//Gemma-7B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_Recipients 5

typedef struct Mailbox {
  char sender[50];
  char recipient[MAX_Recipients][50];
  char subject[50];
  char message[2000];
} Mailbox;

Mailbox mailbox;

void send_mail() {
  printf("Enter the sender's name: ");
  scanf("%s", mailbox.sender);

  printf("Enter the recipient's name: ");
  scanf("%s", mailbox.recipient[0]);

  printf("Enter the subject: ");
  scanf("%s", mailbox.subject);

  printf("Enter the message: ");
  scanf("%s", mailbox.message);

  // Send the mail
  printf("Mail sent!\n");
}

int main() {
  mailbox.recipient[0][0] = '\0';
  mailbox.recipient[1][0] = '\0';
  mailbox.recipient[2][0] = '\0';
  mailbox.recipient[3][0] = '\0';
  mailbox.recipient[4][0] = '\0';

  while (1) {
    printf("Enter 'send' to send mail, 'quit' to quit: ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "send") == 0) {
      send_mail();
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}