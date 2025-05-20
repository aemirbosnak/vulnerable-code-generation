#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char email[100];
  char subject[50];
  char message[200];

  printf("Enter email address: ");
  fgets(email, 100, stdin);

  printf("Enter subject: ");
  fgets(subject, 50, stdin);

  printf("Enter message: ");
  fgets(message, 200, stdin);

  printf("Sending email to %s...", email);

  // Send email code (this is just a placeholder)
  printf("Email sent!");

  return 0;
}
