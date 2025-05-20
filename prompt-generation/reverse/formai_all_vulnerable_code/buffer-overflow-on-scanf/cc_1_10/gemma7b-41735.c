//Gemma-7B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <string.h>

void validate_user_input(char **user_input)
{
  if (user_input == NULL)
  {
    return;
  }

  if (*user_input == NULL)
  {
    return;
  }

  if (strlen(*user_input) < 3)
  {
    return;
  }

  if (strchr(*user_input, ' ') != NULL)
  {
    return;
  }

  return;
}

int main()
{
  char *user_input = NULL;

  printf("Enter a message: ");
  user_input = malloc(1024);

  if (user_input == NULL)
  {
    return 1;
  }

  scanf("%s", user_input);

  validate_user_input(&user_input);

  if (user_input != NULL)
  {
    free(user_input);
  }

  return 0;
}