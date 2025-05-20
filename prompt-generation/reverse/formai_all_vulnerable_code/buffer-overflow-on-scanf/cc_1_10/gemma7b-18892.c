//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
  char password[MAX_PASSWORD_LENGTH];
  int password_length;
  int strength = 0;

  printf("Enter your password: ");
  scanf("%s", password);
  password_length = strlen(password);

  // Check for minimum length
  if (password_length < 8)
  {
    printf("Error: Password must be at least 8 characters long.\n");
    return 1;
  }

  // Check for uppercase letter
  if (!strchr(password, 'A'))
  {
    strength++;
  }

  // Check for lowercase letter
  if (!strchr(password, 'a'))
  {
    strength++;
  }

  // Check for number
  if (!strchr(password, '0'))
  {
    strength++;
  }

  // Check for special character
  if (!strchr(password, '!'))
  {
    strength++;
  }

  // Calculate strength percentage
  strength = strength * 100 / MAX_PASSWORD_LENGTH;

  // Print strength
  printf("Your password strength is: %d%%", strength);

  return 0;
}