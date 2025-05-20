//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main()
{
  char password[256];
  int strength = 0;

  printf("Enter a password: ");
  scanf("%s", password);

  for (int i = 0; password[i] != '\0'; i++)
  {
    if (isupper(password[i]))
    {
      strength++;
    }
    if (islower(password[i]))
    {
      strength++;
    }
    if (isdigit(password[i]))
    {
      strength++;
    }
    if (ispunct(password[i]))
    {
      strength++;
    }
  }

  switch (strength)
  {
    case 0:
      printf("Password is very weak!\n");
      break;
    case 1:
      printf("Password is weak.\n");
      break;
    case 2:
      printf("Password is fair.\n");
      break;
    case 3:
      printf("Password is strong.\n");
      break;
    case 4:
      printf("Password is very strong!\n");
      break;
  }

  return 0;
}