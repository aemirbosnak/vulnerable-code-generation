#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int src, int dest) {
  if (n == 1) {
    printf("Move disk 1 from %d to %d\n", src, dest);
  } else {
    hanoi(n - 1, src, dest);
    printf("Move disk %d from %d to %d\n", n, src, dest);
    hanoi(1, src, dest);
  }
}

int main() {
  hanoi(3, 1, 2);
  return 0;
}
