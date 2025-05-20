//Gemma-7B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_Recipients 5

typedef struct Mailbox {
  char sender[50];
  char recipients[MAX_Recipients][50];
  char subject[50];
  char message[2000];
} Mailbox;

Mailbox mailbox;

void read_mail() {
  printf("Enter the sender's name: ");
  scanf("%s", mailbox.sender);

  printf("Enter the recipient's name: ");
  scanf("%s", mailbox.recipients[0]);

  printf("Enter the subject: ");
  scanf("%s", mailbox.subject);

  printf("Enter the message: ");
  scanf("%s", mailbox.message);
}

void send_mail() {
  printf("Enter the recipient's name: ");
  scanf("%s", mailbox.recipients[0]);

  printf("Enter the subject: ");
  scanf("%s", mailbox.subject);

  printf("Enter the message: ");
  scanf("%s", mailbox.message);

  printf("Mail sent!\n");
}

int main() {
  int choice;

  printf("Welcome to the Retro Email Client!\n");
  printf("1. Read Mail\n");
  printf("2. Send Mail\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      read_mail();
      break;
    case 2:
      send_mail();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}