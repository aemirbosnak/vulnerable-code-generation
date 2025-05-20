//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  unsigned char *buf;
  unsigned int checksum;

  i = 0;
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

  buf = malloc(1024);
  if (buf == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  fread(buf, 1, 1024, stdin);

  for (i = 0; i < 1024; i++) {
    j += buf[i];
    k += j;
    l += k;
    m += l;
    n += m;
    o += n;
    p += o;
    q += p;
    r += q;
    s += r;
    t += s;
    u += t;
    v += u;
    w += v;
    x += w;
    y += x;
    z += y;
  }

  checksum = z;

  printf("Checksum: %08x\n", checksum);

  free(buf);

  return EXIT_SUCCESS;
}