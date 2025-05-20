//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_PASSWD_LENGTH 255

int main()
{
  char passwd[MAX_PASSWD_LENGTH];
  int i, strength, min_strength = 0;

  printf("Enter your password: ");
  scanf("%s", passwd);

  strength = check_password_strength(passwd);

  if (strength < min_strength)
  {
    printf("Your password is too weak. Please choose a stronger password.\n");
  }
  else
  {
    printf("Your password is strong. You can use this password.\n");
  }

  return 0;
}

int check_password_strength(char *passwd)
{
  int length = strlen(passwd);
  int has_digit = 0, has_upper = 0, has_symbol = 0;

  for (int i = 0; i < length; i++)
  {
    if (isdigit(passwd[i]))
    {
      has_digit = 1;
    }
    else if (isupper(passwd[i]))
    {
      has_upper = 1;
    }
    else if (ispunct(passwd[i]))
    {
      has_symbol = 1;
    }
  }

  if (has_digit && has_upper && has_symbol)
  {
    return 3;
  }
  else if (has_digit || has_upper)
  {
    return 2;
  }
  else
  {
    return 1;
  }
}