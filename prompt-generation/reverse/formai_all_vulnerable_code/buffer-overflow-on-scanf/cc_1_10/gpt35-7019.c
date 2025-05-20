//FormAI DATASET v1.0 Category: QR code reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
  uint8_t matrix[21][21]; // a 21x21 matrix to hold the QR code
  printf("Oh, hark! What light through yonder window breaks?\n"); // Romeo speaks
  printf("It is the QR code reader for C, and it shines bright as day!\n");
  printf("Shall I read it for thee, my dear Juliet?\n"); // Romeo asks
  printf("Oh Romeo, Romeo, wherefore art thou QR code reader?\n"); // Juliet responds
  printf("Fret not, my love. 'Tis here, but first it must be scanned.\n"); // Romeo replies
  printf("Let us begin by entering the QR code's dimensions.\n");
  uint8_t dim;
  printf("\nWhat say you? Is the QR code square or rectangular?");
  printf("\nEnter \"1\" for Square or \"2\" for Rectangular\n");
  scanf("%hhu", &dim);
  if (dim == 1)
  {
    printf("\nWhat is the dimension of the square QR code?");
  }
  else
  {
    printf("\nWhat are the dimensions of the rectangular QR code?");
  }
  uint8_t n, m; // n = rows, m = columns
  scanf("%hhu %hhu", &n, &m); // input dimensions
  printf("\nAha! We have a %hhu x %hhu QR code!\n", n, m);
  printf("Please enter the QR code as a string of %d characters:\n", n*m);
  char code[n*m+1];
  scanf("%s", code); // input QR code string
  uint8_t i, j, k = 0; // k iterates through code characters
  // read QR code into matrix
  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < m; ++j)
    {
      matrix[i][j] = code[k] - '0';
      ++k;
    }
  }
  // print QR code matrix
  printf("\nBehold, the QR code:\n");
  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < m; ++j)
    {
      printf("%hhu ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("There you have it, my love! The QR code is ready for use.\n"); // Romeo speaks
  return 0;
}