//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void beep(int n)
{
  for (int i = 0; i < n; i++)
  {
    write(1, "\a", 1);
  }
}

int main()
{
  char *buf, *p, c;
  int i, j, d, w, h, r, b;
  unsigned int n, m;

  buf = malloc(1024);
  p = buf;

  printf("Enter the number of rows and columns for the QR code: ");
  scanf("%d %d", &h, &w);

  printf("Enter the data for the QR code: ");
  fgets(buf, 1024, stdin);

  n = h * w;
  m = n * w;

  for (i = 0; i < m; i++)
  {
    c = buf[i];
    r = c / w;
    b = c % w;

    for (j = 0; j < r; j++)
    {
      for (d = 0; d < w; d++)
      {
        if (b == d)
        {
          beep(1);
        }
      }
    }
  }

  free(buf);

  return 0;
}