//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>

int main()
{
  int n = 0, i, j, k;
  char c, d, e, f, g, h;

  printf("Enter the number of logs:");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    printf("Enter the log:");
    scanf("%c %c %c %c %c %c %c", &c, &d, &e, &f, &g, &h);

    switch (c)
    {
      case 'A':
        printf("Log type: Alert\n");
        break;
      case 'C':
        printf("Log type: Caution\n");
        break;
      case 'I':
        printf("Log type: Inform\n");
        break;
      default:
        printf("Invalid log type\n");
    }

    switch (h)
    {
      case 'H':
        printf("Severity: High\n");
        break;
      case 'M':
        printf("Severity: Medium\n");
        break;
      case 'L':
        printf("Severity: Low\n");
        break;
      default:
        printf("Invalid severity level\n");
    }

    printf("Log message: %s\n", d);
  }

  return 0;
}