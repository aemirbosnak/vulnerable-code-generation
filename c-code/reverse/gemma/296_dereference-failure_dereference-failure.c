#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int classify_file(char *path) {
  int magic_number = read_magic_number(path);
  switch (magic_number) {
    case 0x1a:
      return 1;
    case 0x4a:
      return 2;
    default:
      return 0;
  }
}

int read_magic_number(char *path) {
  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    return -1;
  }
  int magic_number = read(fp, (char *) &magic_number, sizeof(int));
  fclose(fp);
  return magic_number;
}

int main() {
  DIR *dir = opendir("/path/to/directory");
  if (dir == NULL) {
    perror("Error opening directory");
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      char path[256];
      snprintf(path, sizeof(path), "/path/to/directory/%s", entry->d_name);
      int classification = classify_file(path);
      switch (classification) {
        case 1:
          printf("%s is a type 1 file\n", path);
          break;
        case 2:
          printf("%s is a type 2 file\n", path);
          break;
        default:
          printf("%s is not classified\n", path);
          break;
      }
    }
  }

  closedir(dir);
  return 0;
}
