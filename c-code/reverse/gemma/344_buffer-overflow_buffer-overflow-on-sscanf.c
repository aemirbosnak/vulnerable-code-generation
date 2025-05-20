#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char query[1024];
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

  printf("Enter a query: ");
  scanf("%s", query);

  sprintf(buffer, "SELECT * FROM users WHERE name = '%s'", query);
  printf("Results:\n");
  // Vulnerable code using sscanf
  sscanf(buffer, "%[^\n]%*c", buffer);

  return 0;
}
