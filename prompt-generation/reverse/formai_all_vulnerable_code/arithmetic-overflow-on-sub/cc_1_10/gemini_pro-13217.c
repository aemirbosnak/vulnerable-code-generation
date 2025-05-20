//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <time.h>
#include <math.h>
static void universal(char *a[]) {
  clock_t b = clock();
  clock_t c = clock();
  double d = (double)(c - b) / CLOCKS_PER_SEC;
  printf("%g%s", d, a[1]);
  exit(0);
}
int E(int a) { return rand() % a + 1; }
int F(int *a, int b) {
  int c = 0;
  while (c < b) {
    if (E(2) == 1) {
      a[c] = c;
      c++;
    }
  }
  return b - c;
}
int G(int a[]) {
  int b = 0, c;
  while (c = a[b] >= 0) b++;
  return c;
}
int H(int a) {
  int b = 0, c, d;
  while ((c = a % 10) >= 0) {
    d = b * 11 + (c < 10 ? c : c - 7);
    a = a / 10;
    b = d;
  }
  return d;
}
double I(int a) {
  double b = 1;
  while (a > 1) {
    if (a % 2 == 0)
      a = a / 2;
    else
      a = 3 * a + 1;
    b *= 2.0;
  }
  return log(b) / log(3.0);
}
int main(int a, char *b[]) {
  if (a < 3) universal(b);
  int c;
  switch (a < 5 ? atoi(b[2]) : H(atoi(b[1]))) {
  case 0:
    universal(b);
  case 2:
    c = F(b + 1, a - 1);
    printf("%s\n%d\n%g", b[c + 1], G(b + 1), I(c));
    return 0;
  case 3:
    printf("%s\n%g", b[1], asin(atof(b[2])));
    return 0;
  case 4:
    printf("%s\n%g", b[2], pow(atof(b[1]), 2));
    return 0;
  }
}