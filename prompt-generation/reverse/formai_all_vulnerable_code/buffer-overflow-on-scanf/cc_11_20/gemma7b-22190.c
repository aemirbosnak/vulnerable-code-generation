//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char password[256];
  int i, strength = 0, min_length = 8;

  printf("Enter password: ");
  scanf("%s", password);

  // Check for minimum length
  if (strlen(password) < min_length)
  {
    printf("Password too short! Please enter a password of at least %d characters.", min_length);
    return 1;
  }

  // Iterate over password characters
  for (i = 0; password[i] != '\0'; i++)
  {
    // Uppercase letter
    if (password[i] >= 'A' && password[i] <= 'Z')
    {
      strength++;
    }
    // Lowercase letter
    else if (password[i] >= 'a' && password[i] <= 'z')
    {
      strength++;
    }
    // Number
    else if (password[i] >= '0' && password[i] <= '9')
    {
      strength++;
    }
    // Symbol
    else if (password[i] >= '!' && password[i] <= '~')
    {
      strength++;
    }
  }

  // Calculate strength percentage
  strength = (strength / strlen(password)) * 100;

  // Display strength
  printf("Password strength: %d%%", strength);

  return 0;
}