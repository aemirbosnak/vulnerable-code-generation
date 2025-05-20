//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
  char input[100];
  int output[100];
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  bool negative;

  printf("Enter a binary number: ");
  scanf("%s", input);

  i = strlen(input);
  j = 0;
  k = 0;
  l = 0;
  m = 0;
  n = 0;
  o = 0;
  p = 0;
  q = 0;
  r = 0;
  s = 0;
  t = 0;
  u = 0;
  v = 0;
  w = 0;
  x = 0;
  y = 0;
  z = 0;

  for (i = strlen(input) - 1; i >= 0; i--) {
    if (input[i] == '1') {
      output[j] = pow(2, k);
      j++;
    }
    k++;
  }

  for (l = 0; l < j; l++) {
    m += output[l];
  }

  if (input[0] == '1') {
    n = -m;
  } else {
    n = m;
  }

  printf("The decimal equivalent of %s is %d\n", input, n);

  return 0;
}