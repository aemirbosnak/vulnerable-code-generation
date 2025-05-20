//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum length of file paths and names */
#define MAX_PATH_LEN 200
#define MAX_FILE_NAME_LEN 100

/* Define maximum number of backups to keep */
#define MAX_BACKUPS 10

/* Define a struct to hold data for each backup */
typedef struct backup {
  char name[MAX_FILE_NAME_LEN];
  char path[MAX_PATH_LEN];
  char date[20]; // use string for simplicity
} backup_t;

/* Declare an array to hold backup structs */
backup_t backups[MAX_BACKUPS];

/* Declare a variable to keep track of number of backups created */
int num_backups = 0;

/* Define a function to create a new backup */
void create_backup(char *path, char *name) {
  // Get current date/time and store as a string
  char date[20]; // This variable needs to be filled with the current date
  strftime(date, 20, "%Y-%m-%d %H:%M:%S", localtime());

  // Create a new backup struct
  backup_t new_backup;
  strcpy(new_backup.path, path);
  strcpy(new_backup.name, name);
  strcpy(new_backup.date, date);

  // Add the new backup to the array
  backups[num_backups] = new_backup;
  num_backups++;

  // Print success message
  printf("Backup created successfully!\n");
}

/* Define a function to print all backups */
void print_backups() {
  if (num_backups == 0) {
    printf("No backups found.\n");
    return;
  }

  printf("Backups:\n");
  for (int i = 0; i < num_backups; i++) {
    printf("%d. %s\n", i+1, backups[i].name);
  }
}

/* Define a function to delete a backup */
void delete_backup(int index) {
  if (index < 1 || index > num_backups) {
    printf("Invalid backup index.\n");
    return;
  }

  // Shift array elements to remove the backup at the specified index
  for (int i = index-1; i < num_backups-1; i++) {
    backups[i] = backups[i+1];
  }
  num_backups--;

  // Print success message
  printf("Backup deleted successfully.\n");
}

int main() {
  char path[MAX_PATH_LEN], name[MAX_FILE_NAME_LEN];
  int choice, index;

  printf("Welcome to the Backup System!\n");

  while (1) {
    printf("Enter 1 to create a backup, 2 to print all backups, 3 to delete a backup, or 4 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter file path: ");
        scanf("%s", path);
        printf("Enter file name: ");
        scanf("%s", name);
        create_backup(path, name);
        break;
      case 2:
        print_backups();
        break;
      case 3:
        printf("Enter index of backup to delete: ");
        scanf("%d", &index);
        delete_backup(index);
        break;
      case 4:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}