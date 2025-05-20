//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Function to get the size of a file in bytes
long get_file_size(const char *filename) {
  struct stat st;
  if (stat(filename, &st) == 0) {
    return st.st_size;
  } else {
    return -1;
  }
}

// Function to get the total size of all files in a directory
long get_directory_size(const char *dirname) {
  DIR *dir;
  struct dirent *ent;
  long total_size = 0;

  dir = opendir(dirname);
  if (dir == NULL) {
    return -1;
  }

  while ((ent = readdir(dir)) != NULL) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    char full_path[256];
    snprintf(full_path, sizeof(full_path), "%s/%s", dirname, ent->d_name);

    if (ent->d_type == DT_DIR) {
      total_size += get_directory_size(full_path);
    } else {
      total_size += get_file_size(full_path);
    }
  }

  closedir(dir);

  return total_size;
}

// Function to print the size of a directory in a human-readable format
void print_directory_size(const char *dirname, long size) {
  char suffix[4];
  double human_size;

  if (size >= 1024 * 1024 * 1024) {
    human_size = size / (1024.0 * 1024.0 * 1024.0);
    strcpy(suffix, "GB");
  } else if (size >= 1024 * 1024) {
    human_size = size / (1024.0 * 1024.0);
    strcpy(suffix, "MB");
  } else if (size >= 1024) {
    human_size = size / 1024.0;
    strcpy(suffix, "KB");
  } else {
    human_size = size;
    strcpy(suffix, "B");
  }

  printf("%s: %.2f %s\n", dirname, human_size, suffix);
}

int main() {
  char dirname[256];
  long size;

  printf("Enter the directory to analyze: ");
  scanf("%s", dirname);

  size = get_directory_size(dirname);
  if (size == -1) {
    printf("Error getting directory size.\n");
    return 1;
  }

  print_directory_size(dirname, size);

  return 0;
}