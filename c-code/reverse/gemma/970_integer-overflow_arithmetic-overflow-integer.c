#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <sys/stat.h>

int main() {
  struct stat st;
  stat("/", &st);
  long total_size = st.st_size;
  long used_space = st.st_blocks * 512;
  long free_space = total_size - used_space;
  int total_percentage = (total_size * 100) / total_size;
  int used_percentage = (used_space * 100) / total_size;
  int free_percentage = (free_space * 100) / total_size;

  printf("Total size: %ld bytes\n", total_size);
  printf("Used space: %ld bytes (%d%%)\n", used_space, used_percentage);
  printf("Free space: %ld bytes (%d%%)\n", free_space, free_percentage);
  printf("Total percentage: %d%%\n", total_percentage);

  return 0;
}
