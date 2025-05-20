//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
  char password[100];
  int length, upper_case = 0, lower_case = 0, number = 0, special_char = 0;

  printf("Enter the password: ");
  scanf("%s", password);

  length = strlen(password);

  for(int i = 0; i < length; i++)
  {
    if(password[i] >= 'A' && password[i] <= 'Z')
      upper_case++;

    if(password[i] >= 'a' && password[i] <= 'z')
      lower_case++;

    if(password[i] >= '0' && password[i] <= '9')
      number++;

    if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*')
      special_char++;
  }

  if(length < 8)
  {
    printf("\nYour password is too short. It should be at least 8 characters long.\nTry again!\n");
    return 0;
  }

  if(upper_case < 1)
  {
    printf("\nYour password is not strong enough!\nIt should contain at least one upper case letter.\nTry again!\n");
    return 0;
  }

  if(lower_case < 1)
  {
    printf("\nYour password is not strong enough!\nIt should contain at least one lower case letter.\nTry again!\n");
    return 0;
  }

  if(number < 1)
  {
    printf("\nYour password is not strong enough!\nIt should contain at least one number.\nTry again!\n");
    return 0;
  }

  if(special_char < 1)
  {
    printf("\nYour password is not strong enough!\nIt should contain at least one special character.\nTry again!\n");
    return 0;
  }

  printf("\nCongratulations! Your password is strong enough!\n");

  return 0;
}