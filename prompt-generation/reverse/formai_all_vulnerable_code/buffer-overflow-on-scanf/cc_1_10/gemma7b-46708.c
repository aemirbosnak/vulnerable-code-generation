//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255

void sanitize_name(char *name)
{
  char *p = name;
  char ch;

  // Remove leading and trailing whitespace
  while (*p && isspace(*p))
    p++;

  // Convert to uppercase
  while (*p)
  {
    ch = toupper(*p);
    if (!isalnum(ch))
    {
      *p = '\0';
    } else
    {
      *p = ch;
    }
    p++;
  }

  // Normalize name to lowercase
  p = name;
  while (*p)
  {
    ch = tolower(*p);
    *p = ch;
    p++;
  }

  // Trim trailing whitespace
  while (*p && isspace(*p))
    *p-- = '\0';

  // Return the sanitized name
  return;
}

int main()
{
  char name[MAX_NAME_LENGTH];

  printf("Enter your name: ");
  scanf("%s", name);

  sanitize_name(name);

  printf("Sanitized name: %s\n", name);

  return 0;
}