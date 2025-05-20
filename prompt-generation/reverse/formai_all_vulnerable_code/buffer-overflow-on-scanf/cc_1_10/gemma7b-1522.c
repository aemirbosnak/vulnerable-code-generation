//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyze_password(char *password)
{
  int password_length = strlen(password);
  int has_upper_case = 0;
  int has_lower_case = 0;
  int has_number = 0;
  int has_symbol = 0;

  for (int i = 0; i < password_length; i++)
  {
    if (password[i] >= 'A' && password[i] <= 'Z')
    {
      has_upper_case = 1;
    }
    else if (password[i] >= 'a' && password[i] <= 'z')
    {
      has_lower_case = 1;
    }
    else if (password[i] >= '0' && password[i] <= '9')
    {
      has_number = 1;
    }
    else if (password[i] >= '!' && password[i] <= '~')
    {
      has_symbol = 1;
    }
  }

  if (has_upper_case && has_lower_case && has_number && has_symbol)
  {
    printf("Your password is strong.\n");
  }
  else
  {
    printf("Your password is not strong. Please use a stronger password.\n");
  }
}

int main()
{
  char password[20];

  printf("Enter your password: ");
  scanf("%s", password);

  analyze_password(password);

  return 0;
}