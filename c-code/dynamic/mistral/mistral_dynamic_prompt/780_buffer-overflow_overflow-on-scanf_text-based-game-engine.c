#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void secret_function(char *input) {
  char buffer[10];
  strcpy(buffer, input);
}

int main() {
  char user_input[100];
  printf("Welcome to the Game of Secrets! Please enter your secret key: ");
  scanf("%s", user_input);
  secret_function(user_input);
  printf("Your secret has been received.\n");
  return 0;
}
