#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int hano(int n, int src, int dest, int aux) {
  if (n == 0) {
    return 0;
  }
  hano(n - 1, src, aux, dest);
  printf("Move disk %d from %c to %c\n", n, src, dest);
  hano(1, aux, dest, src);
  return 0;
}

int main() {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);
  hano(num_disks, 'a', 'c', 'b');
  return 0;
}
