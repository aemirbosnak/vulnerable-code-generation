#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n_disks = 5;
  int *disks = NULL;
  int i;

  disks = malloc(n_disks * sizeof(int));
  for (i = 0; i < n_disks; i++) {
    disks[i] = i + 1;
  }

  // Potential integer overflow vulnerability
  n_disks = n_disks * 2;
  disks = realloc(disks, n_disks * sizeof(int));
  for (i = n_disks - 1; i >= 0; i--) {
    disks[i] = n_disks - i;
  }

  free(disks);
  return 0;
}
