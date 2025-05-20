//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <time.h>

int main() {
  time_t start, end;
  double time_taken;
  char str[100];
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

  start = time(NULL);

  for (i = 0; i < 100; i++) {
    str[i] = 'a' + i;
  }

  for (j = 0; j < 10; j++) {
    for (k = 0; k < 20; k++) {
      for (l = 0; l < 30; l++) {
        for (m = 0; m < 40; m++) {
          for (n = 0; n < 50; n++) {
            for (o = 0; o < 60; o++) {
              for (p = 0; p < 70; p++) {
                for (q = 0; q < 80; q++) {
                  for (r = 0; r < 90; r++) {
                    for (s = 0; s < 100; s++) {
                      for (t = 0; t < 110; t++) {
                        for (u = 0; u < 120; u++) {
                          for (v = 0; v < 130; v++) {
                            for (w = 0; w < 140; w++) {
                              for (x = 0; x < 150; x++) {
                                for (y = 0; y < 160; y++) {
                                  for (z = 0; z < 170; z++) {
                                    str[z] = 'a' + z;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  end = time(NULL);

  time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Time taken: %.2lf seconds\n", time_taken);

  return 0;
}