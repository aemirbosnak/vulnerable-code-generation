//Gemma-7B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct Recipient {
  char name[50];
  char email[100];
  struct Recipient* next;
} Recipient;

void addRecipient(Recipient** head) {
  Recipient* newRecipient = malloc(sizeof(Recipient));
  printf("Enter recipient name: ");
  scanf("%s", newRecipient->name);
  printf("Enter recipient email: ");
  scanf("%s", newRecipient->email);
  newRecipient->next = NULL;

  if (*head == NULL) {
    *head = newRecipient;
  } else {
    (*head)->next = newRecipient;
  }
}

void sendEmail(Recipient* head) {
  printf("Enter subject: ");
  char subject[100];
  scanf("%s", subject);

  printf("Enter message: ");
  char message[1000];
  scanf("%s", message);

  while (head) {
    printf("Sending email to: %s (%s)\n", head->name, head->email);
    // Send email code here
    head = head->next;
  }

  printf("Email sent successfully!\n");
}

int main() {
  Recipient* head = NULL;
  int choice;

  do {
    printf("1. Add Recipient\n");
    printf("2. Send Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addRecipient(&head);
        break;
      case 2:
        sendEmail(head);
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 3);

  return 0;
}