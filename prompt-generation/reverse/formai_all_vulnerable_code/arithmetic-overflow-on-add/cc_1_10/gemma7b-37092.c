//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void beautify_html(char *html)
{
  int i, j, k, indent = 0, state = 0;
  char buffer[MAX_BUFFER_SIZE];

  for (i = 0; html[i] != '\0'; i++)
  {
    switch (state)
    {
      case 0:
        if (html[i] == '<')
        {
          state = 1;
          buffer[k++] = '\n';
          buffer[k++] = ' ';
        }
        else
        {
          buffer[k++] = html[i];
        }
        break;

      case 1:
        if (html[i] == '>' || html[i] == '/' || html[i] == '"')
        {
          state = 0;
          buffer[k++] = '\n';
          buffer[k++] = ' ';
        }
        else
        {
          buffer[k++] = html[i];
        }
        break;
    }

    if (indent > 0)
    {
      for (j = 0; j < indent; j++)
      {
        buffer[k++] = ' ';
      }
    }
  }

  printf("%s", buffer);
}

int main()
{
  char html[] = "<div><b>Hello, world!</b></div>";

  beautify_html(html);

  return 0;
}