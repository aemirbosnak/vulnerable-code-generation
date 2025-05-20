//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
  char name[50];
  int size;
  char *data;
} file;

typedef struct backup {
  char name[50];
  int num_files;
  file *files;
} backup;

void create_backup(char *backup_name) {
  backup b;
  strcpy(b.name, backup_name);
  b.num_files = 0;
  b.files = NULL;

  printf("Enter the number of files to back up: ");
  scanf("%d", &b.num_files);

  b.files = malloc(sizeof(file) * b.num_files);

  for (int i = 0; i < b.num_files; i++) {
    printf("Enter the name of file %d: ", i + 1);
    scanf("%s", b.files[i].name);

    printf("Enter the size of file %d (in bytes): ", i + 1);
    scanf("%d", &b.files[i].size);

    b.files[i].data = malloc(b.files[i].size);

    printf("Enter the data for file %d: ", i + 1);
    scanf("%s", b.files[i].data);
  }

  FILE *f = fopen(backup_name, "w");
  fwrite(&b, sizeof(backup), 1, f);
  fclose(f);

  printf("Backup created successfully!\n");
}

void restore_backup(char *backup_name) {
  backup b;
  FILE *f = fopen(backup_name, "r");
  fread(&b, sizeof(backup), 1, f);
  fclose(f);

  for (int i = 0; i < b.num_files; i++) {
    FILE *f = fopen(b.files[i].name, "w");
    fwrite(b.files[i].data, b.files[i].size, 1, f);
    fclose(f);
  }

  printf("Backup restored successfully!\n");
}

int main() {
  int choice;

  printf("1. Create backup\n");
  printf("2. Restore backup\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  char backup_name[50];

  switch (choice) {
    case 1:
      printf("Enter the name of the backup file: ");
      scanf("%s", backup_name);
      create_backup(backup_name);
      break;
    case 2:
      printf("Enter the name of the backup file to restore: ");
      scanf("%s", backup_name);
      restore_backup(backup_name);
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}