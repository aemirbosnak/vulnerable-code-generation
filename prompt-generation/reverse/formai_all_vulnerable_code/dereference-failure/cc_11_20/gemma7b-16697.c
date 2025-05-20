//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
  char str[100] = "The quick brown fox jumps over the sleeping dog. The lazy cat sits on the mat. The clock strikes twelve.";

  // 1. Remove unnecessary whitespace
  char *p = str;
  char *q = str;
  while (*p)
  {
    if (*p != ' ' && *p != '\t' && *p != '\n')
    {
      *q = *p;
      q++;
    }
    p++;
  }

  // 2. Rearrange sentences
  char *s = str;
  char *t = str;
  int i = 0;
  while (*s)
  {
    if (*s == '.')
    {
      t = s + 1;
      i++;
    }
    s++;
  }

  // 3. Capitalize first letter of each sentence
  for (int j = 0; j < i; j++)
  {
    if (t[0] >= 'a' && t[0] <= 'z')
    {
      t[0] -= 32;
    }
    t++;
  }

  // 4. Add punctuation
  char punctuation[] = ",.?!";
  int k = 0;
  for (int l = 0; l < strlen(str); l++)
  {
    if (str[l] == ' ' && punctuation[k] != '\0')
    {
      str[l] = punctuation[k];
      k++;
    }
  }

  // 5. Print the beautified text
  printf("%s\n", str);

  return 0;
}