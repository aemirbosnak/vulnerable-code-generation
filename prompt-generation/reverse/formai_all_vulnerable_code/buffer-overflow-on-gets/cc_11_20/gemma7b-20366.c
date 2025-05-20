//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <string.h>

int main()
{
  char str[1000];
  printf("Enter text: ");
  gets(str);

  if (strlen(str) > 20)
  {
    printf("Warning: Text length exceeds 20 characters.\n");
  }

  if (strchr(str, '$') || strchr(str, '%') || strchr(str, '#') || strchr(str, '&'))
  {
    printf("Warning: Found suspicious characters.\n");
  }

  if (strcspn(str, "abcdefghijklmnopqrstuvwxyz") < 5)
  {
    printf("Warning: Text lacks sufficient alphabet diversity.\n");
  }

  if (strpbrk(str, "()[]|\\:;'*") != NULL)
  {
    printf("Warning: Found punctuation marks.\n");
  }

  if (strtok(str, " ") > 5)
  {
    printf("Warning: Text contains excessive whitespace.\n");
  }

  if (strcmp(str, "The quick brown fox jumps over the lazy dog") == 0)
  {
    printf("Warning: Text is identical to a common phrase.\n");
  }

  if (str[0] >= 'a' && str[0] <= 'z')
  {
    printf("Warning: Text begins with a lowercase letter.\n");
  }

  if (str[strlen(str) - 1] == '.')
  {
    printf("Warning: Text ends with a period.\n");
  }

  if (str[strlen(str) - 1] == '!')
  {
    printf("Warning: Text ends with an exclamation mark.\n");
  }

  printf("Text Analysis Complete.\n");

  return 0;
}