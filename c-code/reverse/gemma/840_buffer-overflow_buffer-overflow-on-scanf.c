#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int choice;
  char email[100];
  char subject[50];
  char message[200];

  printf("1. Compose email\n");
  printf("2. Exit\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter email address: ");
      scanf("%s", email);

      printf("Enter subject: ");
      scanf("%s", subject);

      printf("Enter message: ");
      scanf("%s", message);

      // Vulnerable code: Buffer overflow in message storage
      message[200] = '\0';

      printf("Email sent successfully!\n");
      break;
    case 2:
      exit(0);
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
