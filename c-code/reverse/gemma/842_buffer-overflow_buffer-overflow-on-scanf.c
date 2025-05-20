#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void send_email(char *to, char *subject, char *body) {
  // Replace with actual email sending code
}

int main() {
  char menu_choice;
  char to[100];
  char subject[100];
  char body[1000];

  printf("Email Client\n");
  printf("--------------------\n");
  printf("1. Compose Email\n");
  printf("2. Exit\n");

  printf("Enter your choice: ");
  scanf("%c", &menu_choice);

  switch (menu_choice) {
    case '1':
      printf("Enter the recipient's email address: ");
      scanf("%s", to);
      printf("Enter the subject: ");
      scanf("%s", subject);
      printf("Enter the email body: ");
      scanf("%s", body);
      send_email(to, subject, body);
      break;
    case '2':
      exit(0);
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
