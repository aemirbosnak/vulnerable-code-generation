#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char email[1024];
  int choice;

  printf("1. Send email\n");
  printf("2. View inbox\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the recipient's email address: ");
      scanf("%s", email);
      printf("Enter the subject: ");
      scanf("%s", email);
      printf("Enter the message: ");
      scanf("%s", email);

      // Buffer overflow vulnerability
      email[1024 - 1] = '\0';

      printf("Email sent successfully!\n");
      break;
    case 2:
      printf("Your inbox is empty.\n");
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
