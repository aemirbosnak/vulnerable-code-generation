//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 10

typedef struct {
  char name[50];
  char contents[MAX_FILE_SIZE];
  time_t last_modified;
} File;

File files[MAX_NUM_FILES];
int num_files = 0;

void add_file(char *name, char *contents) {
  if (num_files >= MAX_NUM_FILES) {
    fprintf(stderr, "Error: too many files\n");
    return;
  }

  strcpy(files[num_files].name, name);
  strcpy(files[num_files].contents, contents);
  files[num_files].last_modified = time(NULL);
  num_files++;
}

void print_file(File *file) {
  printf("File: %s\n", file->name);
  printf("Contents: %s\n", file->contents);
  printf("Last modified: %s\n", ctime(&file->last_modified));
}

void backup_files() {
  FILE *backup_file = fopen("backup.txt", "w");
  if (backup_file == NULL) {
    fprintf(stderr, "Error: could not open backup file\n");
    return;
  }

  for (int i = 0; i < num_files; i++) {
    fprintf(backup_file, "%s\n%s\n%ld\n", files[i].name, files[i].contents, files[i].last_modified);
  }

  fclose(backup_file);
}

void restore_files() {
  FILE *backup_file = fopen("backup.txt", "r");
  if (backup_file == NULL) {
    fprintf(stderr, "Error: could not open backup file\n");
    return;
  }

  num_files = 0;
  while (fscanf(backup_file, "%s\n%s\n%ld\n", files[num_files].name, files[num_files].contents, &files[num_files].last_modified) != EOF) {
    num_files++;
  }

  fclose(backup_file);
}

int main() {
  add_file("file1.txt", "This is the first file.");
  add_file("file2.txt", "This is the second file.");

  backup_files();

  // Modify the files
  strcpy(files[0].contents, "This is the modified first file.");
  files[1].last_modified = time(NULL);

  restore_files();

  // Print the restored files
  for (int i = 0; i < num_files; i++) {
    print_file(&files[i]);
  }

  return 0;
}