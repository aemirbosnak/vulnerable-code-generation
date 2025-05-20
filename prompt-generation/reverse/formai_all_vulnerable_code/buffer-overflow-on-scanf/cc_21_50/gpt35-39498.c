//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char hex[17], bin[65] = "";
  int num, i = 0, j = 0, dec = 0;
  printf("Enter a hexadecimal number to convert to binary:\n");
  scanf("%s", hex);
  while (hex[i])
  {
    switch (hex[i])
    {
    case '0':
      strcat(bin, "0000");
      break;
    case '1':
      strcat(bin, "0001");
      break;
    case '2':
      strcat(bin, "0010");
      break;
    case '3':
      strcat(bin, "0011");
      break;
    case '4':
      strcat(bin, "0100");
      break;
    case '5':
      strcat(bin, "0101");
      break;
    case '6':
      strcat(bin, "0110");
      break;
    case '7':
      strcat(bin, "0111");
      break;
    case '8':
      strcat(bin, "1000");
      break;
    case '9':
      strcat(bin, "1001");
      break;
    case 'A':
    case 'a':
      strcat(bin, "1010");
      break;
    case 'B':
    case 'b':
      strcat(bin, "1011");
      break;
    case 'C':
    case 'c':
      strcat(bin, "1100");
      break;
    case 'D':
    case 'd':
      strcat(bin, "1101");
      break;
    case 'E':
    case 'e':
      strcat(bin, "1110");
      break;
    case 'F':
    case 'f':
      strcat(bin, "1111");
      break;
    default:
      printf("Invalid hexadecimal digit %c", hex[i]);
      return 0;
    }
    i++;
  }
  printf("\nEquivalent binary value of %s is: %s", hex, bin);
  printf("\nEnter a binary number to convert to decimal:\n");
  scanf("%d", &num);
  while (num > 0)
  {
    if (num % 10 == 1)
    {
      dec += 1 << j;
    }
    j++;
    num = num / 10;
  }
  printf("\nDecimal value of %d is: %d", num, dec);
  return 0;
}