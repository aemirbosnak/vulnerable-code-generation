//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: systematic
// C disk space analyzer example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory_path>\n", argv[0]);
    return 1;
  }

  char *path = argv[1];
  DIR *dir = opendir(path);
  if (dir == NULL) {
    printf("Error opening directory: %s\n", strerror(errno));
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char filepath[PATH_MAX];
    snprintf(filepath, PATH_MAX, "%s/%s", path, entry->d_name);

    struct stat st;
    if (stat(filepath, &st) == -1) {
      printf("Error getting file info: %s\n", strerror(errno));
      continue;
    }

    if (S_ISDIR(st.st_mode)) {
      printf("Directory: %s\n", entry->d_name);
    } else if (S_ISREG(st.st_mode)) {
      printf("File: %s (%lu bytes)\n", entry->d_name, (unsigned long)st.st_size);
    } else {
      printf("Other: %s\n", entry->d_name);
    }
  }

  closedir(dir);
  return 0;
}