//Gemma-7B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Recipients 10

typedef struct Recipient {
  char name[50];
  char email[50];
} Recipient;

void read_recipients(Recipient **recipients, int *num_recipients) {
  int i = 0;
  *num_recipients = 0;

  printf("Enter the number of recipients: ");
  scanf("%d", num_recipients);

  *recipients = malloc((*num_recipients) * sizeof(Recipient));

  for (i = 0; i < *num_recipients; i++) {
    printf("Enter the name of the recipient: ");
    scanf("%s", (*recipients)[i].name);

    printf("Enter the email address of the recipient: ");
    scanf("%s", (*recipients)[i].email);
  }
}

void send_email(Recipient *recipients, int num_recipients) {
  int i = 0;

  printf("Enter the subject of your email: ");
  char subject[50];
  scanf("%s", subject);

  printf("Enter the message of your email: ");
  char message[500];
  scanf("%s", message);

  for (i = 0; i < num_recipients; i++) {
    printf("Sending email to: %s <%s>\n", recipients[i].name, recipients[i].email);

    // Send email using your favorite email API
  }
}

int main() {
  Recipient *recipients = NULL;
  int num_recipients = 0;

  read_recipients(&recipients, &num_recipients);
  send_email(recipients, num_recipients);

  free(recipients);

  return 0;
}