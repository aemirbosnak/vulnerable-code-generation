//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  char input[100], output[100], hex[16];
  int decimal, i, j, remainder, quotient;

  printf("---Welcome to the Cyber Hexadecimal Converter---\n\n");

  printf("Enter a decimal number to convert to hexadecimal: ");
  scanf("%d", &decimal);

  quotient = decimal;
  i = 0;

  while (quotient != 0)
  {
    remainder = quotient % 16;

    if (remainder < 10)
      hex[i] = remainder + 48; // converts to ascii value of number
    else
      hex[i] = remainder + 55; // converts to corresponding letter in ascii table

    quotient /= 16;
    i++;
  }

  printf("\nHexadecimal value of %d is: ", decimal);

  for (j = i - 1; j >= 0; j--)
    printf("%c", hex[j]);

  printf("\n\nEnter a hexadecimal number to convert to decimal: ");
  scanf("%s", input);

  int len = strlen(input);
  decimal = 0;

  for (i = 0; i < len; i++)
  {
    switch(input[i])
    {
      case '0': decimal += 0 * pow(16, len - i - 1);
                break;
      case '1': decimal += 1 * pow(16, len - i - 1);
                break;
      case '2': decimal += 2 * pow(16, len - i - 1);
                break;
      case '3': decimal += 3 * pow(16, len - i - 1);
                break;
      case '4': decimal += 4 * pow(16, len - i - 1);
                break;
      case '5': decimal += 5 * pow(16, len - i - 1);
                break;
      case '6': decimal += 6 * pow(16, len - i - 1);
                break;
      case '7': decimal += 7 * pow(16, len - i - 1);
                break;
      case '8': decimal += 8 * pow(16, len - i - 1);
                break;
      case '9': decimal += 9 * pow(16, len - i - 1);
                break;
      case 'A': decimal += 10 * pow(16, len - i - 1);
                break;
      case 'B': decimal += 11 * pow(16, len - i - 1);
                break;
      case 'C': decimal += 12 * pow(16, len - i - 1);
                break;
      case 'D': decimal += 13 * pow(16, len - i - 1);
                break;
      case 'E': decimal += 14 * pow(16, len - i - 1);
                break;
      case 'F': decimal += 15 * pow(16, len - i - 1);
                break;
    }
  }

  printf("\nDecimal value of %s is: %d", input, decimal);

  printf("\n\n---The conversion is complete. Thank you for using our program!---");
}