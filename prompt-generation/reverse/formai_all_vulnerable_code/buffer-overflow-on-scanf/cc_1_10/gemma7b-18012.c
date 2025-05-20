//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
  int i = 0;
  char num[11];

  if (n == 0)
  {
    num[0] = '0';
    num[1] = '\0';
  }
  else
  {
    while (n)
    {
      int digit = n % 10;
      num[i++] = digit + '0';
      n /= 10;
    }

    num[i] = '\0';
  }

  strcpy(s, num);
}

int main()
{
  int n;
  char text[1000];

  printf("Enter text: ");
  fgets(text, 1000, stdin);

  printf("Enter number of lines: ");
  scanf("%d", &n);

  int l = 0;
  char *ascii_art = malloc(n * 20);

  for (int i = 0; i < n; i++)
  {
    itoa(l, ascii_art);
    l++;

    printf("%s\n", ascii_art);

    free(ascii_art);
    ascii_art = malloc(n * 20);
  }

  return 0;
}