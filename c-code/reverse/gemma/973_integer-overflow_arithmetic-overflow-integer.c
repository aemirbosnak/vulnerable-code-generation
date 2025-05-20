#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
  char path[1024];
  printf("Enter a path: ");
  scanf("%s", path);

  struct stat stat_buf;
  if (stat(path, &stat_buf) == -1) {
    perror("Error stat()ing path");
    return 1;
  }

  long long used_space = stat_buf.st_size;
  long long total_space = stat_buf.st_blocks * 512;
  double usage_percentage = (double)used_space * 100.0 / (double)total_space;

  printf("Disk space usage for %s:\n", path);
  printf("  - Used space: %.2f MB\n", used_space / 1048576.0);
  printf("  - Total space: %.2f MB\n", total_space / 1048576.0);
  printf("  - Usage percentage: %.2f%%\n", usage_percentage);

  return 0;
}
