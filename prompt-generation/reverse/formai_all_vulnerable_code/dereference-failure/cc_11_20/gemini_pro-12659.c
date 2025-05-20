//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input = fopen(argv[1], "r");
  if (input == NULL)
  {
    fprintf(stderr, "Error opening input file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  FILE *output = fopen(argv[2], "w");
  if (output == NULL)
  {
    fprintf(stderr, "Error opening output file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  char *buffer = malloc(1024);
  if (buffer == NULL)
  {
    fprintf(stderr, "Error allocating memory for buffer\n");
    return EXIT_FAILURE;
  }

  while (fgets(buffer, 1024, input) != NULL)
  {
    char *p = buffer;
    while (*p != '\0')
    {
      if (*p >= 'A' && *p <= 'Z')
      {
        *p += 32;
      }
      else if (*p >= 'a' && *p <= 'z')
      {
        *p -= 32;
      }
      p++;
    }

    fprintf(output, "%s", buffer);
  }

  free(buffer);
  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}