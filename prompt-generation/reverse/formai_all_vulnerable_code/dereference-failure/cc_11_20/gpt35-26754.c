//FormAI DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>

int main() {
  FILE *fpIn, *fpOut;
  char c, prevC;
  int newlineCounter = 0, spaceCounter = 0;

  fpIn = fopen("input.html", "r");
  fpOut = fopen("output.html", "w");

  if (fpIn == NULL || fpOut == NULL) {
    printf("Error: Unable to open file.\n");
    return -1;
  }

  while ((c = fgetc(fpIn)) != EOF ) {
    // Check if current character is a tag
    if (c == '<') {
      putc(c, fpOut);
      prevC = c;

      // Continue reading until closing tag is found
      while ((c = fgetc(fpIn)) != '>') {
        if (c == '\n') {
          newlineCounter++;
        } else if (c == ' ') {
          spaceCounter++;
        }
        putc(c, fpOut);
        prevC = c;
      }

      if (prevC != '/') {
        newlineCounter = 0;
      }
    } else {
      putc(c, fpOut);
      prevC = c;

      if (prevC == ' ' && newlineCounter > 0) {
        newlineCounter = 0;
      }

      if (prevC == '\n' && spaceCounter > 1) {
        spaceCounter = 0;
      }
    }
  }

  printf("File processed successfully.\n");

  fclose(fpIn);
  fclose(fpOut);

  return 0;
}