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

  printf("Enter body: ");
  scanf("%s", body);

  // Intentionally leave this vulnerable to a buffer overflow
  printf("Email sent to %s with subject %s\n", recipient, subject);
  printf("Body: %s\n", body);

  return 0;
}
