//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8   //Minimum length requirement
#define MAX_LENGTH 25  //Maximum length requirement

void checkPassword(char *password);

int main()
{
  char password[50];
  printf("Enter your password: ");
  scanf("%s", password);
  checkPassword(password);

  return 0;
}

void checkPassword(char *password)
{
  int length = strlen(password);
  int uppercase = 0, lowercase = 0, digit = 0, special = 0;

  if (length < MIN_LENGTH || length > MAX_LENGTH)
  {
    printf("Password length should be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
    return;
  }

  for (int i = 0; i < length; i++)
  {
    char ch = *(password + i);
    if (isupper(ch))
    {
      uppercase++;
    }
    else if (islower(ch))
    {
      lowercase++;
    }
    else if (isdigit(ch))
    {
      digit++;
    }
    else
    {
      special++;
    }
  }

  if (uppercase > 0 && lowercase > 0 && digit > 0 && special > 0)
  {
    printf("Password is strong and meets all of the following requirements:\n");
    printf("1. Password length is between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
    printf("2. Contains at least one uppercase letter.\n");
    printf("3. Contains at least one lowercase letter.\n");
    printf("4. Contains at least one digit.\n");
    printf("5. Contains at least one special character such as !,@,#, etc.\n");
  }
  else
  {
    printf("Password is weak and must meet the following requirements:\n");
    printf("1. Password length should be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
    printf("2. Password should contain at least one uppercase letter.\n");
    printf("3. Password should contain at least one lowercase letter.\n");
    printf("4. Password should contain at least one digit.\n");
    printf("5. Password should contain at least one special character such as !,@,#, etc.\n");
  }
}