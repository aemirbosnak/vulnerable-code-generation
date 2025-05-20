#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  long long disk_space_used = 10000000000; // 10GB
  long long total_disk_space = 100000000000LL; // 100GB

  long long percentage_used = (disk_space_used * 100) / total_disk_space;

  printf("Disk space usage: %lld%%", percentage_used);

  return 0;
}
