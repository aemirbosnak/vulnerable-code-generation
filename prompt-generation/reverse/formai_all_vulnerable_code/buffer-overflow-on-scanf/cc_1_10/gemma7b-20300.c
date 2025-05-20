//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char password[100];
  printf("Enter your password: ");
  scanf("%s", password);

  int password_strength = check_password_strength(password);

  switch (password_strength)
  {
    case 0:
      printf("Your password is weak. Please try again.\n");
      break;
    case 1:
      printf("Your password is moderate. It could be better.\n");
      break;
    case 2:
      printf("Your password is strong. It meets all the requirements.\n");
      break;
    case 3:
      printf("Your password is very strong. It is impossible to crack.\n");
      break;
  }

  return 0;
}

int check_password_strength(char *password)
{
  int strength = 0;
  int length = strlen(password);

  // Check for minimum length
  if (length < 8)
  {
    strength--;
  }

  // Check for uppercase letter
  if (!strchr(password, 'A'))
  {
    strength--;
  }

  // Check for lowercase letter
  if (!strchr(password, 'a'))
  {
    strength--;
  }

  // Check for number
  if (!strchr(password, '0') || !strchr(password, '9'))
  {
    strength--;
  }

  // Check for special character
  if (!strchr(password, '!'))
  {
    strength--;
  }

  return strength;
}