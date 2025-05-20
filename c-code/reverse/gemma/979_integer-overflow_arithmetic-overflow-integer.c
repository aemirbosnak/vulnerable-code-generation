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
  if (stat(path, &stat_buf) == 0) {
    long long used_space = stat_buf.st_size;
    long long total_space = stat_buf.st_blocks * 512;
    long long free_space = total_space - used_space;
    long long percentage_used = (used_space * 100) / total_space;

    printf("Disk space usage for %s:\n", path);
    printf("  - Used space: %.2f GB (%lld bytes)\n", used_space / 1000000.0);
    printf("  - Total space: %.2f GB (%lld bytes)\n", total_space / 1000000.0);
    printf("  - Free space: %.2f GB (%lld bytes)\n", free_space / 1000000.0);
    printf("  - Percentage used: %.2f%%\n", percentage_used);
  } else {
    printf("Error calculating disk space usage.\n");
  }

  return 0;
}
