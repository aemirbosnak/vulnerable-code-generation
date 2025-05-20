//FormAI DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUPS 5
#define MAX_FILENAME_LENGTH 20

typedef struct backup {
  char filename[MAX_FILENAME_LENGTH];
  time_t timestamp;
} Backup;

int main() {
  Backup backups[MAX_BACKUPS];
  int num_backups = 0;

  printf("Welcome to the Future-Proof File Backup System!\n\n");

  while (1) {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file to backup (or 'quit' to exit): ");
    scanf("%s", filename);

    if (strcmp(filename, "quit") == 0) {
      break;
    }

    Backup new_backup;
    strcpy(new_backup.filename, filename);
    new_backup.timestamp = time(NULL);

    if (num_backups == MAX_BACKUPS) {
      // remove the oldest backup
      Backup oldest_backup = backups[0];

      for (int i = 1; i < MAX_BACKUPS; i++) {
        if (backups[i].timestamp < oldest_backup.timestamp) {
          oldest_backup = backups[i];
        }
      }

      printf("Maximum number of backups reached. Removing oldest backup: %s\n",
             oldest_backup.filename);

      // remove the oldest backup from the array
      for (int i = 0; i < MAX_BACKUPS; i++) {
        if (strcmp(backups[i].filename, oldest_backup.filename) == 0) {
          for (int j = i; j < MAX_BACKUPS - 1; j++) {
            backups[j] = backups[j + 1];
          }
          break;
        }
      }

      num_backups--;
    }

    backups[num_backups] = new_backup;
    num_backups++;

    printf("File '%s' backed up successfully.\n\n", filename);
  }

  printf("Goodbye!\n");

  return 0;
}