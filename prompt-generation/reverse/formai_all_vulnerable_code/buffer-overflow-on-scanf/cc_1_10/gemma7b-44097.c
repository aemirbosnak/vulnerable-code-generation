//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 16

int main()
{
  char password[PASSWORD_LENGTH];

  printf("Please enter your password:\n");
  scanf("%s", password);

  int strength = check_password_strength(password);

  switch (strength)
  {
    case 0:
      printf("Your password is extremely weak. Please use a stronger password.\n");
      break;
    case 1:
      printf("Your password is weak. Please use a stronger password.\n");
      break;
    case 2:
      printf("Your password is moderate. It is acceptable, but could be improved.\n");
      break;
    case 3:
      printf("Your password is strong. It is difficult to crack.\n");
      break;
    case 4:
      printf("Your password is very strong. It is extremely difficult to crack.\n");
      break;
  }

  return 0;
}

int check_password_strength(char *password)
{
  int strength = 0;
  int i;

  for (i = 0; i < PASSWORD_LENGTH; i++)
  {
    if (password[i] >= 'a' && password[i] <= 'z')
    {
      strength++;
    }
    else if (password[i] >= 'A' && password[i] <= 'Z')
    {
      strength++;
    }
    else if (password[i] >= '0' && password[i] <= '9')
    {
      strength++;
    }
    else if (password[i] == '$' || password[i] == '#')
    {
      strength++;
    }
  }

  return strength;
}