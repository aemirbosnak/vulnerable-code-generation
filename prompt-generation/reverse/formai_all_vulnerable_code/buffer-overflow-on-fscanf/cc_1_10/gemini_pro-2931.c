//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_NAME_LEN 32
#define MAX_DATA_LEN 128

typedef struct {
  char name[MAX_NAME_LEN];
  char data[MAX_DATA_LEN];
} FitnessTrackerEntry;

int main() {
  FitnessTrackerEntry *entries = NULL;
  int num_entries = 0;
  int max_entries = 0;

  // Read in the entries from a file.
  FILE *fp = fopen("fitness_tracker.txt", "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (!feof(fp)) {
    if (num_entries == max_entries) {
      max_entries *= 2;
      entries = realloc(entries, max_entries * sizeof(FitnessTrackerEntry));
    }

    fscanf(fp, "%s %s", entries[num_entries].name, entries[num_entries].data);
    num_entries++;
  }

  fclose(fp);

  // Sort the entries by name.
  qsort(entries, num_entries, sizeof(FitnessTrackerEntry), strcmp);

  // Print the entries.
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", entries[i].name, entries[i].data);
  }

  // Free the memory allocated for the entries.
  free(entries);

  return EXIT_SUCCESS;
}