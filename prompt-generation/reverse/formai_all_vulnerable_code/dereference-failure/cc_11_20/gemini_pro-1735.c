//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main(int iI, char** sS) {
  char** sCp, **sCp2, **sCp3;
  char* sC, *sC2, *sC3;
  int iC = 0;
  for (sCp = sS + 1; *sCp; sCp++) {
    iC++;
    if (iC & 1)
      sC = *sCp;
    else
      sC2 = *sCp;
  }
  if (iI == 2) {
    sC3 = sC2;
    sC2 = sC;
    sC = sC3;
  }
  if (sC) {
    if (*sC == '\0')
      sC = NULL;
    else {
      if (sC2) {
        if (*sC2 == '\0')
          sC2 = NULL;
        else {
          if (iI == 1) {
            for (sCp3 = sCp + 1; *sCp3; sCp3++) {
              sC3 = *sCp3;
              if (strcmp(sC, sC3) > 0)
                sC = sC3;
              if (strcmp(sC2, sC3) < 0)
                sC2 = sC3;
            }
          } else {
            for (sCp3 = sCp + 1; *sCp3; sCp3++) {
              sC3 = *sCp3;
              if (strcmp(sC, sC3) < 0)
                sC = sC3;
              if (strcmp(sC2, sC3) > 0)
                sC2 = sC3;
            }
          }
        }
      }
      if (sC)
        printf("%s\n", sC);
      if (sC2)
        printf("%s\n", sC2);
      if (sC3)
        printf("%s\n", sC3);
    }
  }
}