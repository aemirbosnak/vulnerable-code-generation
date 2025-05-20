//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
// Where hearts entangled, passion's flame ignites,
// A tale of star-crossed lovers, in code's delights.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo, a bard of binary prose,
// With verses of data, his love he avows.
char *romeo, *juliet;

// Friar Laurence, the wise, with compression's might,
// To join their words, a sacred union in sight.
void compress(char *src, char *dest);

int main(int argc, char **argv) {
  // From Verona to fair Mantua, the tale takes flight,
  // Juliet's sweet words, Romeo's with all his might.
  romeo = malloc(1024);
  juliet = malloc(1024);
  printf("Romeo, speak thy heart's desire!\n");
  gets(romeo);
  printf("Juliet, fair maid, thy love inspire!\n");
  gets(juliet);

  // Friar Laurence blesses their union, with wisdom's aid,
  // Compressing words, their love forever laid.
  printf("Friar Laurence, unite their words, I pray!\n");
  compress(romeo, juliet);

  // The lovers' words, now one, forever bound,
  // In digital embrace, love eternal found.
  printf("Behold, their love, in bits and bytes entwined:\n%s", juliet);

  // The tale ends, but love's compression knows no end,
  // A testament to hearts that fate cannot unbend.
  free(romeo);
  free(juliet);
  return 0;
}

void compress(char *src, char *dest) {
  // Romeo's words, a string of ones and zeros true,
  // Juliet's words, a melody of bits anew.
  int romeoLen = strlen(src);
  int julietLen = strlen(dest);

  // Each symbol, a union, a dance of yin and yang,
  // Zipped and intertwined, a tale they sing.
  for (int i = 0; i < romeoLen + julietLen; i++) {
    int bit = (i < romeoLen) ? src[i] - '0' : dest[i - romeoLen] - '0';
    dest[i] = (bit ^ (i & 1)) + '0';
  }
}