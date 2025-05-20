#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char recipient[256];
  char subject[256];
  char body[256];

  printf("Enter recipient: ");
  scanf("%s", recipient);

  printf("Enter subject: ");
  scanf("%s", subject);

  printf("Enter email body: ");
  scanf("%s", body);

  // Vulnerable code: Buffer overflow in body input handling
  body[255] = '\0';

  printf("Email sent to: %s\n", recipient);
  printf("Subject: %s\n", subject);
  printf("Body: %s\n", body);

  return 0;
}
