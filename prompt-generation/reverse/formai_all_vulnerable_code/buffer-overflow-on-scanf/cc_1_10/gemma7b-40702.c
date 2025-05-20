//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main()
{
  char pwd[1024];
  printf("Enter password: ");
  scanf("%s", pwd);

  int pwd_strength = strength(pwd);
  switch (pwd_strength)
  {
    case 0:
      printf("Password is extremely weak.\n");
      break;
    case 1:
      printf("Password is weak.\n");
      break;
    case 2:
      printf("Password is moderate.\n");
      break;
    case 3:
      printf("Password is strong.\n");
      break;
    case 4:
      printf("Password is very strong.\n");
      break;
    case 5:
      printf("Password is extremely strong.\n");
      break;
  }

  return 0;
}

int strength(char *pwd)
{
  int strength = 0;
  int i = 0;

  // Check for uppercase letters
  while (pwd[i] != '\0')
  {
    if (pwd[i] >= 'A' && pwd[i] <= 'Z')
    {
      strength++;
    }
    i++;
  }

  // Check for lowercase letters
  i = 0;
  while (pwd[i] != '\0')
  {
    if (pwd[i] >= 'a' && pwd[i] <= 'z')
    {
      strength++;
    }
    i++;
  }

  // Check for numbers
  i = 0;
  while (pwd[i] != '\0')
  {
    if (pwd[i] >= '0' && pwd[i] <= '9')
    {
      strength++;
    }
    i++;
  }

  // Check for special characters
  i = 0;
  while (pwd[i] != '\0')
  {
    if (pwd[i] >= '!' && pwd[i] <= '~')
    {
      strength++;
    }
    i++;
  }

  return strength;
}