#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char recipient[256];
  char subject[256];
  char email_body[1024];

  printf("Enter recipient's email address: ");
  scanf("%s", recipient);

  printf("Enter subject: ");
  scanf("%s", subject);

  printf("Enter email body: ");
  scanf("%[^\n]%*c", email_body);

  // Potential vulnerability: Buffer overflow for email_body
  if (strlen(email_body) > 1024) {
    printf("Error: Email body too long.\n");
  } else {
    printf("Email sent successfully to %s.\n", recipient);
  }

  return 0;
}
