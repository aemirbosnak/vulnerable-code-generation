#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int classify_file(char *path) {
  int magic_number = 0;
  FILE *fp = fopen(path, "rb");
  if (fp) {
    fseek(fp, 0L, SEEK_SET);
    magic_number = read(fp, (char *) &magic_number, sizeof(int));
    fclose(fp);
  }
  switch (magic_number) {
    case 0xcafebabe:
      return 1;
    case 0xfacfacf:
      return 2;
    default:
      return 0;
  }
}

int main() {
  DIR *dir;
  struct dirent *entry;
  char path[1024];

  dir = opendir("/path/to/directory");
  if (dir) {
    while ((entry = readdir(dir)) != NULL) {
      sprintf(path, "/path/to/directory/%s", entry->d_name);
      classify_file(path);
    }
    closedir(dir);
  }
  return 0;
}
