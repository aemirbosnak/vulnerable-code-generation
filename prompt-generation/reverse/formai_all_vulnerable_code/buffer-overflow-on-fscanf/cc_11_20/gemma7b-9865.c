//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x = 0, y = 0, n = 0;
  char c;
  FILE *fp;
  fp = fopen("ascii.txt", "r");
  fscanf(fp, "%d", &n);
  for (x = 0; x < n; x++) {
    for (y = 0; y < n; y++) {
      c = fgetc(fp);
      switch (c) {
        case 32:
          printf(" ");
          break;
        case 48:
          printf("0");
          break;
        case 49:
          printf("1");
          break;
        case 50:
          printf("2");
          break;
        case 51:
          printf("3");
          break;
        case 52:
          printf("4");
          break;
        case 53:
          printf("5");
          break;
        case 54:
          printf("6");
          break;
        case 55:
          printf("7");
          break;
        case 56:
          printf("8");
          break;
        case 57:
          printf("9");
          break;
        case 10:
          printf("\n");
          break;
      }
    }
  }
  fclose(fp);
  return 0;
}