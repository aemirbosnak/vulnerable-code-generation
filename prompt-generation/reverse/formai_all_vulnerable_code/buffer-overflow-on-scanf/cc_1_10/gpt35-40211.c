//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_DIGITS 10

long long int hextodec(char hex[]);
char dectohex(long long int dec);

int main() {
  char hex[MAX_HEX_DIGITS];
  long long int dec;

  printf("Enter a hexadecimal number (up to 8 digits): ");
  scanf("%8s", hex);

  dec = hextodec(hex);
  printf("%s in decimal is %lld\n", hex, dec);

  printf("Enter a decimal number: ");
  scanf("%lld", &dec);

  printf("%lld in hexadecimal is %c", dec, dectohex(dec));
  printf("%c\n", '\n');

  return 0;
}

long long int hextodec(char hex[]) {
  int len = strlen(hex);
  long long int dec = 0;
  int base = 1;

  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - '0') * base;
      base *= 16;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
      base *= 16;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
      base *= 16;
    }
  }

  return dec;
}

char dectohex(long long int dec) {
  char hex;

  if (dec <= 9) {
    hex = dec + '0';
  } else {
    hex = dec - 10 + 'a';
  }

  return hex;
}