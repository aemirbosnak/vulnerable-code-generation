#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAGIC_NUMBER_SIZE 4

int main() {
  DIR *dir;
  struct dirent *entry;
  struct stat stat_buf;
  unsigned char magic_number[MAGIC_NUMBER_SIZE];
  char file_path[256];

  dir = opendir("/path/to/directory");
  if (!dir) {
    perror("opendir");
    return 1;
  }

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      sprintf(file_path, "/path/to/directory/%s", entry->d_name);
      stat(file_path, &stat_buf);

      if (read(file_path, magic_number, MAGIC_NUMBER_SIZE) > 0) {
        // Compare magic number to known file type signatures
        // (e.g., magic number for JPEG file: 0xFFD8)
        // If magic number matches, print file type and path
      } else {
        perror("read");
      }
    }
  }

  closedir(dir);

  return 0;
}
