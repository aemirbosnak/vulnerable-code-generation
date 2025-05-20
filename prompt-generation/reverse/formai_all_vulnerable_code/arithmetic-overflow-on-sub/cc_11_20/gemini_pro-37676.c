//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

// Define the maximum file size
#define MAX_FILE_SIZE 1024 * 1024 * 1024

// Define the number of backup files to keep
#define NUM_BACKUP_FILES 5

// Define the backup directory
#define BACKUP_DIR "/backup"

// Main function
int main() {
  // Get the current time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  // Create the backup directory if it doesn't exist
  if (mkdir(BACKUP_DIR, 0755) != 0) {
    perror("mkdir");
    return EXIT_FAILURE;
  }

  // Open the file to be backed up
  FILE *fp = fopen("file.txt", "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Get the file size
  struct stat st;
  if (fstat(fileno(fp), &st) != 0) {
    perror("fstat");
    return EXIT_FAILURE;
  }

  // Check if the file is too large
  if (st.st_size > MAX_FILE_SIZE) {
    fprintf(stderr, "File is too large to backup\n");
    return EXIT_FAILURE;
  }

  // Create the backup file name
  char backup_file_name[256];
  snprintf(backup_file_name, sizeof(backup_file_name), "%s/%s_%04d%02d%02d_%02d%02d%02d.txt", BACKUP_DIR, "file", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

  // Open the backup file
  FILE *fp_backup = fopen(backup_file_name, "w");
  if (fp_backup == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Copy the file to the backup file
  char buffer[1024];
  while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
    fwrite(buffer, 1, sizeof(buffer), fp_backup);
  }

  // Close the files
  fclose(fp);
  fclose(fp_backup);

  // Delete the oldest backup file
  if (NUM_BACKUP_FILES > 0) {
    char oldest_backup_file_name[256];
    snprintf(oldest_backup_file_name, sizeof(oldest_backup_file_name), "%s/%s_oldest.txt", BACKUP_DIR, "file");

    if (remove(oldest_backup_file_name) != 0) {
      perror("remove");
      return EXIT_FAILURE;
    }
  }

  // Rename the backup files
  for (int i = NUM_BACKUP_FILES - 1; i > 0; i--) {
    char backup_file_name_old[256];
    snprintf(backup_file_name_old, sizeof(backup_file_name_old), "%s/%s_%04d%02d%02d_%02d%02d%02d.txt", BACKUP_DIR, "file", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday - i, tm->tm_hour, tm->tm_min, tm->tm_sec);

    char backup_file_name_new[256];
    snprintf(backup_file_name_new, sizeof(backup_file_name_new), "%s/%s_%04d%02d%02d_%02d%02d%02d.txt", BACKUP_DIR, "file", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday - i + 1, tm->tm_hour, tm->tm_min, tm->tm_sec);

    if (rename(backup_file_name_old, backup_file_name_new) != 0) {
      perror("rename");
      return EXIT_FAILURE;
    }
  }

  // Rename the newest backup file to the oldest backup file
  if (NUM_BACKUP_FILES > 0) {
    char backup_file_name_newest[256];
    snprintf(backup_file_name_newest, sizeof(backup_file_name_newest), "%s/%s_%04d%02d%02d_%02d%02d%02d.txt", BACKUP_DIR, "file", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    char oldest_backup_file_name[256];
    snprintf(oldest_backup_file_name, sizeof(oldest_backup_file_name), "%s/%s_oldest.txt", BACKUP_DIR, "file");

    if (rename(backup_file_name_newest, oldest_backup_file_name) != 0) {
      perror("rename");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}