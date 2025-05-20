//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define MAX_SIZE 1024

/* Function to extract metadata from a given string */
int extractMetadata(char *str, char *metadata) {
  int i, j, k, count = 0;
  char temp[MAX_SIZE];

  /* Initialize metadata to empty string */
  metadata[0] = '\0';

  /* Iterate over the given string */
  for (i = 0; str[i] != '\0'; i++) {
    /* If the current character is a digit, then start extracting metadata */
    if (isdigit(str[i])) {
      /* Extract the metadata until a non-digit character is encountered */
      j = i;
      while (isdigit(str[j]))
        j++;
      strncpy(temp, str + i, j - i);
      temp[j - i] = '\0';

      /* Check if the extracted metadata is valid */
      k = atoi(temp);
      if (k >= 0 && k <= 255) {
        /* Convert the metadata to a string and append it to the metadata string */
        sprintf(temp, "%d,", k);
        strcat(metadata, temp);
        count++;
      }

      /* Increment the counter */
      i = j - 1;
    }
  }

  /* Remove the trailing comma from the metadata string */
  if (count > 0)
    metadata[strlen(metadata) - 1] = '\0';

  /* Return the number of metadata values extracted */
  return count;
}

/* Main function */
int main() {
  char str[MAX_SIZE], metadata[MAX_SIZE];

  /* Get the input string from the user */
  printf("Enter a string: ");
  gets(str);

  /* Extract metadata from the given string */
  int count = extractMetadata(str, metadata);

  /* Print the extracted metadata */
  if (count > 0) {
    printf("Metadata: %s\n", metadata);
  } else {
    printf("No metadata found in the given string.\n");
  }

  return 0;
}