//FormAI DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void send_email(char *target_email, char *subject, char *body);
void receive_email();

int main() {
  int choice;
  char target_email[MAX_LEN], subject[MAX_LEN], body[MAX_LEN];

  printf("Welcome to the C Email Client!\n");

  do {
    printf("Choose an action:\n");
    printf("1. Send email\n");
    printf("2. Receive email\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the target email address (e.g. john@example.com): ");
        scanf("%s", target_email);

        printf("Enter the subject of the email: ");
        getchar(); // Clear buffer
        fgets(subject, MAX_LEN, stdin);

        printf("Enter the body of the email: ");
        fgets(body, MAX_LEN, stdin);

        send_email(target_email, subject, body);
        break;

      case 2:
        receive_email();
        break;

      case 3:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

    printf("\n");

  } while(choice != 3);

  return 0;
}

void send_email(char *target_email, char *subject, char *body) {
  printf("Email sent to %s with subject \"%s\" and body \"%s\".\n", target_email, subject, body);
  // Add email sending functionality here
}

void receive_email() {
  printf("Checking for new emails...\n");
  // Add email receiving functionality here
}