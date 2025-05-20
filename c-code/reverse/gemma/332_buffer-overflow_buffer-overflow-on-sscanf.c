#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char email[100];
  printf("Enter your email address: ");
  scanf("%s", email);

  char format[] = "%[a-zA-Z0-9._%+-]+@[a-zA-Z0-9]+(?:\.[a-zA-Z0-9]+)*";
  int result = sscanf(email, format, email);

  if (result == 1) {
    printf("Email address: %s\n", email);
  } else {
    printf("Error parsing email address.\n");
  }

  return 0;
}
