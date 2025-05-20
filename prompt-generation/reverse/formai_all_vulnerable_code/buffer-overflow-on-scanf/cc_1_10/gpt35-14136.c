//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool has_lowercase(char password[]);
bool has_uppercase(char password[]);
bool has_number(char password[]);
bool has_special(char password[]);
bool is_long_enough(char password[]);

int main()
{
  char password[30];
  int score = 0;

  printf("Enter your password: ");
  scanf("%s", password);

  if (has_lowercase(password))
  {
    score += 10;
  }
  else
  {
    printf("Your password needs to have at least one lowercase letter.\n");
  }

  if (has_uppercase(password))
  {
    score += 10;
  }
  else
  {
    printf("Your password needs to have at least one uppercase letter.\n");
  }

  if (has_number(password))
  {
    score += 10;
  }
  else
  {
    printf("Your password needs to have at least one number.\n");
  }

  if (has_special(password))
  {
    score += 10;
  }
  else
  {
    printf("Your password needs to have at least one special character.\n");
  }

  if (is_long_enough(password))
  {
    score += 10;
  }
  else
  {
    printf("Your password needs to be at least 8 characters long.\n");
  }

  printf("Your password's strength is %d/50.\n", score);

  return 0;
}

bool has_lowercase(char password[])
{
  for (int i = 0; i < strlen(password); i++)
  {
    if (password[i] >= 'a' && password[i] <= 'z')
    {
      return true;
    }
  }

  return false;
}

bool has_uppercase(char password[])
{
  for (int i = 0; i < strlen(password); i++)
  {
    if (password[i] >= 'A' && password[i] <= 'Z')
    {
      return true;
    }
  }

  return false;
}

bool has_number(char password[])
{
  for (int i = 0; i < strlen(password); i++)
  {
    if (password[i] >= '0' && password[i] <= '9')
    {
      return true;
    }
  }

  return false;
}

bool has_special(char password[])
{
  for (int i = 0; i < strlen(password); i++)
  {
    if ((password[i] >= '!' && password[i] <= '/') ||
        (password[i] >= ':' && password[i] <= '@') ||
        (password[i] >= '[' && password[i] <= '`') ||
        (password[i] >= '{' && password[i] <= '~'))
    {
      return true;
    }
  }

  return false;
}

bool is_long_enough(char password[])
{
  return strlen(password) >= 8;
}