//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 256

typedef struct password_strength_t
{
  int strength;
  char *message;
} password_strength_t;

password_strength_t check_password_strength(char *password)
{
  password_strength_t strength_info;
  strength_info.strength = 0;
  strength_info.message = NULL;

  if (strlen(password) < 8)
  {
    strength_info.message = "Password too short";
  }
  else if (strlen(password) >= 8 && strlen(password) < 16)
  {
    strength_info.strength = 1;
    strength_info.message = "Weak";
  }
  else if (strlen(password) >= 16 && strlen(password) < 24)
  {
    strength_info.strength = 2;
    strength_info.message = "Moderate";
  }
  else if (strlen(password) >= 24)
  {
    strength_info.strength = 3;
    strength_info.message = "Strong";
  }

  return strength_info;
}

int main()
{
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter your password: ");
  scanf("%s", password);

  password_strength_t strength_info = check_password_strength(password);

  if (strength_info.message)
  {
    printf("Password strength: %s\n", strength_info.message);
  }
  else
  {
    printf("Password strength: Strong\n");
  }

  return 0;
}