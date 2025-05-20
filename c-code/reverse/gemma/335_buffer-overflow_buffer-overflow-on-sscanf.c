#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char email[256];
  printf("Enter your email address: ");
  scanf("%s", email);

  char username[64];
  sscanf(email, "%[^@]@%s", username, email);

  if (strlen(username) > 63) {
    printf("Error: username too long.\n");
  } else {
    printf("Your username is: %s\n", username);
  }

  return 0;
}
