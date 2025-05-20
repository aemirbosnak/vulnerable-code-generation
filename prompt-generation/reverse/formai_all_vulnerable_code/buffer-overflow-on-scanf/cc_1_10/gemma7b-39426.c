//Gemma-7B DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct Recipient {
  char name[50];
  char email[50];
} Recipient;

void read_recipients(Recipient **recipients, int *num_recipients) {
  *num_recipients = 0;
  printf("Enter the number of recipients: ");
  scanf("%d", num_recipients);

  *recipients = malloc((*num_recipients) * sizeof(Recipient));

  for (int i = 0; i < *num_recipients; i++) {
    printf("Enter the name of recipient %d: ", i + 1);
    scanf("%s", (*recipients)[i].name);

    printf("Enter the email address of recipient %d: ", i + 1);
    scanf("%s", (*recipients)[i].email);
  }
}

void compose_email(Recipient *recipients, int num_recipients) {
  char subject[100];
  char message[2000];

  printf("Enter the subject of your email: ");
  scanf("%s", subject);

  printf("Enter the message of your email: ");
  scanf("%s", message);

  for (int i = 0; i < num_recipients; i++) {
    printf("Sending email to: %s (%s)\n", recipients[i].name, recipients[i].email);

    // Send email code here
  }
}

int main() {
  Recipient *recipients = NULL;
  int num_recipients = 0;

  read_recipients(&recipients, &num_recipients);
  compose_email(recipients, num_recipients);

  free(recipients);

  return 0;
}