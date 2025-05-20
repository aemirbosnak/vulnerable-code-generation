//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main()
{
  char password[100];
  int strength = 0;
  int i = 0;

  printf("Enter a password: ");
  scanf("%s", password);

  // Check for minimum length
  if (strlen(password) < 8)
  {
    strength = strength - 1;
  }

  // Check for uppercase letter
  for (i = 0; i < strlen(password); i++)
  {
    if (isupper(password[i]))
    {
      strength = strength + 1;
    }
  }

  // Check for lowercase letter
  for (i = 0; i < strlen(password); i++)
  {
    if (islower(password[i]))
    {
      strength = strength + 1;
    }
  }

  // Check for number
  for (i = 0; i < strlen(password); i++)
  {
    if (isdigit(password[i]))
    {
      strength = strength + 1;
    }
  }

  // Check for symbol
  for (i = 0; i < strlen(password); i++)
  {
    if (ispunct(password[i]))
    {
      strength = strength + 1;
    }
  }

  // Print strength
  switch (strength)
  {
    case 0:
      printf("Password strength: Weak\n");
      break;
    case 1:
      printf("Password strength: Moderate\n");
      break;
    case 2:
      printf("Password strength: Good\n");
      break;
    case 3:
      printf("Password strength: Strong\n");
      break;
    default:
      printf("Password strength: Very Strong\n");
      break;
  }

  return 0;
}