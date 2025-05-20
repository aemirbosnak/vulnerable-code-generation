//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024

int main(int argc, char *argv[]) {
  // Check for the correct number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  // Open the directory
  DIR *dir = opendir(argv[1]);
  if (!dir) {
    fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
    return 1;
  }

  // Iterate over the directory entries
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Skip over . and .. entries
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Build the full path to the entry
    char path[MAX_PATH_LENGTH];
    snprintf(path, MAX_PATH_LENGTH, "%s/%s", argv[1], entry->d_name);

    // Stat the entry
    struct stat st;
    if (stat(path, &st) == -1) {
      fprintf(stderr, "Error stat-ing %s: %s\n", path, strerror(errno));
      continue;
    }

    // Print the entry's size
    printf("%s: %ld bytes\n", path, st.st_size);
  }

  // Close the directory
  closedir(dir);

  return 0;
}