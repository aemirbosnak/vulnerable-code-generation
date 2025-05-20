//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
  char password[MAX_PASSWORD_LENGTH] = "";
  int password_length = 0;
  int strength = 0;

  // Get the password from the user
  printf("Enter your password: ");
  scanf("%s", password);
  password_length = strlen(password);

  // Calculate the password strength
  for (int i = 0; i < password_length; i++)
  {
    char character = password[i];

    if (character >= 'a' && character <= 'z')
    {
      strength++;
    }
    else if (character >= 'A' && character <= 'Z')
    {
      strength++;
    }
    else if (character >= '0' && character <= '9')
    {
      strength++;
    }
    else if (character == '$' || character == '#' || character == '%')
    {
      strength++;
    }
  }

  // Display the password strength
  switch (strength)
  {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
  }

  return 0;
}