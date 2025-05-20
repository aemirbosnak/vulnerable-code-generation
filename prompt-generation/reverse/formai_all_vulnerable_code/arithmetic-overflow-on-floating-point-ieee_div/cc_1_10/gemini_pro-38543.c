//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int a, b, c;
  float d, e, f;
  double g, h, i;
  long double j, k, l;

  // Get input from the user.

  printf("Enter three integers: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("Enter three floats: ");
  scanf("%f %f %f", &d, &e, &f);

  printf("Enter three doubles: ");
  scanf("%lf %lf %lf", &g, &h, &i);

  printf("Enter three long doubles: ");
  scanf("%Lf %Lf %Lf", &j, &k, &l);

  // Perform arithmetic operations on the input values.

  a += b;
  b -= c;
  c *= a;
  d /= b;
  e += f;
  f *= d;
  g /= e;
  h -= f;
  i *= g;
  j += h;
  k -= i;
  l *= j;

  // Print the results to the console.

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %f\n", d);
  printf("e = %f\n", e);
  printf("f = %f\n", f);
  printf("g = %lf\n", g);
  printf("h = %lf\n", h);
  printf("i = %lf\n", i);
  printf("j = %Lf\n", j);
  printf("k = %Lf\n", k);
  printf("l = %Lf\n", l);

  return 0;
}