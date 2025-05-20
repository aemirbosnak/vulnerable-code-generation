//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

int main()
{
  char data[MAX];
  int i, j, n, k, l, w, h, code[MAX];

  printf("Enter data: ");
  scanf("%s", data);

  n = strlen(data) + 1;
  k = 0;

  for (i = 0; i < n; i++)
  {
    switch (data[i])
    {
      case '0':
        code[k++] = 0x11;
        break;
      case '1':
        code[k++] = 0x12;
        break;
      case '2':
        code[k++] = 0x13;
        break;
      case '3':
        code[k++] = 0x14;
        break;
      case '4':
        code[k++] = 0x15;
        break;
      case '5':
        code[k++] = 0x16;
        break;
      case '6':
        code[k++] = 0x17;
        break;
      case '7':
        code[k++] = 0x18;
        break;
      case '8':
        code[k++] = 0x19;
        break;
      case '9':
        code[k++] = 0x1A;
        break;
      default:
        code[k++] = 0x1F;
        break;
    }
  }

  w = (n + 7) / 8;
  h = (w + 3) / 4;

  printf("QR Code:\n");
  for (i = 0; i < h; i++)
  {
    for (j = 0; j < w; j++)
    {
      if (code[k] & 0x80)
        printf("X ");
      else
        printf("O ");
    }

    printf("\n");
  }

  return 0;
}