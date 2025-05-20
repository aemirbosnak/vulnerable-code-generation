#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BACKUPS 5

typedef struct BackupFile {
  char *filename;
  time_t timestamp;
} BackupFile;

int main() {
  BackupFile files[MAX_BACKUPS];
  int i = 0;

  // Create a new backup file
  files[i].filename = malloc(20);
  sprintf(files[i].filename, "backup_%d_%s.txt", time(NULL), "yyyy-mm-dd-hh:mm:ss");
  files[i].timestamp = time(NULL);
  i++;

  // Add more backup files if needed

  // Remove oldest backup file if exceeding limit
  if (i > MAX_BACKUPS) {
    time_t oldest_timestamp = files[0].timestamp;
    int j = 0;
    for (j = 1; j < i; j++) {
      if (files[j].timestamp < oldest_timestamp) {
        oldest_timestamp = files[j].timestamp;
      }
    }
    free(files[j].filename);
    i--;
  }

  // Perform file operations (e.g., copy, move, delete)

  return 0;
}
