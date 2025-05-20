#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int hano(int n, int src, int dest, int tmp) {
  if (n == 0) {
    return 0;
  }
  hano(n - 1, src, tmp, dest);
  printf("Move disk %d from %c to %c\n", n, src, dest);
  hano(1, tmp, dest, src);
  return 0;
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);
  hano(num_disks, 'a', 'c', 'b');
  return 0;
}
