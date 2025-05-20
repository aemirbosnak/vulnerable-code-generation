//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 32

typedef struct {
  int length;
  char *password;
} password_t;

password_t generate_password(int length);
void print_password(password_t password);

int main() {
  int password_length;
  password_t password;

  printf("Enter the desired password length (1-%d): ", MAX_PASSWORD_LENGTH);
  scanf("%d", &password_length);

  if (password_length <= 0 || password_length > MAX_PASSWORD_LENGTH) {
    printf("Invalid password length. Please enter a value between 1 and %d.\n", MAX_PASSWORD_LENGTH);
    return 1;
  }

  password = generate_password(password_length);
  print_password(password);

  free(password.password);

  return 0;
}

password_t generate_password(int length) {
  int i;
  char character_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  int character_set_length = strlen(character_set);
  password_t password;

  password.length = length;
  password.password = malloc(length + 1);

  for (i = 0; i < length; i++) {
    password.password[i] = character_set[rand() % character_set_length];
  }

  password.password[length] = '\0';

  return password;
}

void print_password(password_t password) {
  printf("Your password is: %s\n", password.password);
}