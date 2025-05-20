//GEMINI-pro DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

int main() {
  char s[N];
  int i, j, k, l;
  float a, b, c;
  double d, e, f;

  // The clocks chime, summoning the slumbering code
  printf("Hark! The clocks call like lost sheep\n");

  // Crimson threads intertwine, weaving a tapestry of words
  scanf("%s", s);

  // The canvas shimmers, a kaleidoscope of characters
  for (i = 0; i < strlen(s); i++) {
    // Each keystroke, a dash of color, painting the void
    printf("%c", s[i]);
  }

  // The numbers dance, a waltz of ones and zeros
  scanf("%d %d %d\n", &i, &j, &k);

  // They intertwine, their movements an enigma
  l = i + j - k;

  // The universe expands, a celestial dance of numbers
  printf("%d\n", l);

  // The air hums, a symphony of floating-point dreams
  scanf("%f %f %f\n", &a, &b, &c);

  // They merge and divide, ethereal melodies etching patterns
  d = a * b / c;

  // The cosmos reverberates, a chorus of floating-point voices
  printf("%f\n", d);

  // The echoes linger, ghostly whispers of computation
  scanf("%lf %lf %lf\n", &e, &f, &d);

  // They vanish into the void, leaving ripples in the fabric of time
  e = f - d;

  // The dream fades, the code subsides into silence
  printf("%lf\n", e);

  // The screen flickers, a gentle reminder of the transient nature of creation
  return 0;
}