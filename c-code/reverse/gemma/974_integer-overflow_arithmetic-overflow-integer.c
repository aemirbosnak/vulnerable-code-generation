#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  long long disk_size = 1000000000000; // 100GB
  long long used_space = 99999999999; // 99.9GB

  long long percentage = (used_space * 100) / disk_size;

  printf("Disk space usage: %.2f%%", (double)percentage);

  return 0;
}
