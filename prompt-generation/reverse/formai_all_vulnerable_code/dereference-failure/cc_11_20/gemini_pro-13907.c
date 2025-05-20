//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A simple data mining program that reads a file of records and prints the
 * most frequent values for each field.
 */

int main(int argc, char **argv)
{
  FILE *f;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *fields[10];
  int field_counts[10];
  int i, j;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while ((read = getline(&line, &len, f)) != -1) {
    /* Split the line into fields. */
    for (i = 0; i < 10; i++) {
      fields[i] = strtok(line, ",");
      if (fields[i] == NULL) {
        break;
      }
    }

    /* Count the frequency of each field value. */
    for (i = 0; i < 10; i++) {
      field_counts[i] = 0;
      for (j = 0; j < 10; j++) {
        if (strcmp(fields[i], fields[j]) == 0) {
          field_counts[i]++;
        }
      }
    }

    /* Print the most frequent field values. */
    for (i = 0; i < 10; i++) {
      if (field_counts[i] > 0) {
        printf("%s: %d\n", fields[i], field_counts[i]);
      }
    }
  }

  fclose(f);
  free(line);

  return EXIT_SUCCESS;
}