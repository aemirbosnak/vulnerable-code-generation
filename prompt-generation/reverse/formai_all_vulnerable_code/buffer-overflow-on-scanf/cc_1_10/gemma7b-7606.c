//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void beautify_html(char **lines, int num_lines)
{
  int i, j, k, indent = 0;
  char line[MAX_LINES], tag[MAX_LINES];

  for (i = 0; i < num_lines; i++)
  {
    strcpy(line, lines[i]);
    k = 0;

    // Identify tags and indent accordingly
    for (j = 0; line[j] != '\0'; j++)
    {
      if (line[j] == '<' && line[j + 1] == 'h')
      {
        indent++;
      }
      else if (line[j] == '>' && line[j - 1] == 'h')
      {
        indent--;
      }
      tag[k++] = line[j];
    }

    // Replace tags with indents
    for (j = 0; tag[j] != '\0'; j++)
    {
      switch (tag[j])
      {
        case 'h':
          lines[i] = strcat(lines[i], " ");
          for (k = 0; k < indent; k++)
          {
            lines[i] = strcat(lines[i], "  ");
          }
          break;
      }
    }
  }
}

int main()
{
  char **lines = NULL;
  int num_lines = 0;

  // Get the number of lines
  printf("Enter the number of lines: ");
  scanf("%d", &num_lines);

  // Allocate memory for the lines
  lines = malloc(num_lines * sizeof(char *));

  // Get the lines
  printf("Enter the lines: ");
  for (int i = 0; i < num_lines; i++)
  {
    lines[i] = malloc(MAX_LINES * sizeof(char));
    scanf("%[^\n]%*c", lines[i]);
  }

  // Beautify the HTML
  beautify_html(lines, num_lines);

  // Print the beautified lines
  for (int i = 0; i < num_lines; i++)
  {
    printf("%s\n", lines[i]);
  }

  // Free the memory
  for (int i = 0; i < num_lines; i++)
  {
    free(lines[i]);
  }
  free(lines);

  return 0;
}