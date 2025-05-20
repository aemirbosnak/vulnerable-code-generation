//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hexadecimal to Decimal converter
int HexToDecimal(char c) {
  int val = 0;
  switch (c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      val = c - '0';
      break;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
      val = c - 'A' + 10;
      break;
    default:
      val = -1;
  }
  return val;
}

// Decimal to Hexadecimal converter
char DecToHex(int d) {
  char hex = '0';
  if (d < 0) {
    hex = '-';
    d = -d;
  }
  if (d < 10) {
    hex = d + '0';
  } else if (d < 16) {
    hex = d + 'A' - 10;
  } else {
    hex = 'F';
  }
  return hex;
}

int main() {
  printf("Enter a Hexadecimal number: ");
  char hex_num[10];
  scanf("%s", hex_num);

  int decimal_val = 0;
  for (int i = 0; hex_num[i]!= '\0'; i++) {
    decimal_val += HexToDecimal(hex_num[i]);
  }

  printf("Decimal value is: %d\n", decimal_val);

  int hex_val = decimal_val;
  printf("Enter a Decimal number: ");
  scanf("%d", &hex_val);

  char hex_output[10];
  for (int i = 0; hex_output[i]!= '\0'; i++) {
    hex_output[i] = DecToHex(hex_val % 16);
    hex_val /= 16;
  }

  printf("Hexadecimal value is: %s\n", hex_output);

  return 0;
}