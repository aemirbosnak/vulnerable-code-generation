//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: innovative
// unique_file_backup.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH_LEN 256
#define MAX_FILES 100

typedef struct {
  char path[MAX_PATH_LEN];
  char name[MAX_PATH_LEN];
  char extension[MAX_PATH_LEN];
} FileInfo;

void print_usage(char *program_name) {
  printf("Usage: %s <path to backup> <path to destination>\n", program_name);
}

void backup_file(char *path, char *dest) {
  char *filename = strrchr(path, '/');
  if (filename == NULL) {
    filename = path;
  } else {
    filename++;
  }
  char dest_path[MAX_PATH_LEN];
  snprintf(dest_path, MAX_PATH_LEN, "%s/%s", dest, filename);
  if (rename(path, dest_path) == -1) {
    perror("Error: ");
    exit(EXIT_FAILURE);
  }
}

void backup_directory(char *path, char *dest) {
  DIR *dir;
  struct dirent *entry;
  dir = opendir(path);
  if (dir == NULL) {
    perror("Error: ");
    exit(EXIT_FAILURE);
  }
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    char entry_path[MAX_PATH_LEN];
    snprintf(entry_path, MAX_PATH_LEN, "%s/%s", path, entry->d_name);
    struct stat entry_stat;
    if (stat(entry_path, &entry_stat) == -1) {
      perror("Error: ");
      exit(EXIT_FAILURE);
    }
    if (S_ISDIR(entry_stat.st_mode)) {
      backup_directory(entry_path, dest);
    } else {
      backup_file(entry_path, dest);
    }
  }
  closedir(dir);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    print_usage(argv[0]);
    exit(EXIT_FAILURE);
  }
  char *path = argv[1];
  char *dest = argv[2];
  backup_directory(path, dest);
  return 0;
}