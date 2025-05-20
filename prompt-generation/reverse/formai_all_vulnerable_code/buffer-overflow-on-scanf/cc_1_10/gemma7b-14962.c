//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char password[100];

  printf("Enter a password: ");
  scanf("%s", password);

  int strength = password_strength(password);

  switch (strength)
  {
    case 0:
      printf("Your password is very weak. Please use a stronger password.\n");
      break;
    case 1:
      printf("Your password is weak. Please use a stronger password.\n");
      break;
    case 2:
      printf("Your password is moderate. It could be stronger.\n");
      break;
    case 3:
      printf("Your password is strong. It meets the recommended criteria.\n");
      break;
    case 4:
      printf("Your password is very strong. It is extremely difficult to crack.\n");
      break;
  }

  return 0;
}

int password_strength(char *password)
{
  int length = strlen(password);
  int has_number = 0;
  int has_symbol = 0;
  int has_upper = 0;
  int has_repeat = 0;

  for (int i = 0; i < length; i++)
  {
    if (password[i] >= '0' && password[i] <= '9')
    {
      has_number = 1;
    }
    else if (password[i] >= 'a' && password[i] <= 'z')
    {
      has_upper = 1;
    }
    else if (password[i] >= '!' && password[i] <= '/')
    {
      has_symbol = 1;
    }
    else if (password[i] == password[i-1])
    {
      has_repeat = 1;
    }
  }

  int strength = 0;

  if (length >= 8)
  {
    strength++;
  }
  if (has_number)
  {
    strength++;
  }
  if (has_symbol)
  {
    strength++;
  }
  if (has_upper)
  {
    strength++;
  }
  if (!has_repeat)
  {
    strength++;
  }

  return strength;
}