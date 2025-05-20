//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* hexToDec takes a hexadecimal number and returns its decimal equivalent */
int hexToDec(char hex[]) {
  int dec = 0;
  int base = 1; // Initialize power of 16

  int len = strlen(hex);
  for (int i = len - 1; i >= 0; i--) {
    // If character lies in '0'-'9', convert it to integer
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - 48) * base;
      base = base * 16;
    }
    // If character lies in 'A'-'F', convert it to integer
    else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 55) * base;
      base = base * 16;
    }
  }
  return dec;
}

/* decToHex takes a decimal number and converts it to its hexadecimal equivalent */
char *decToHex(int dec) {
  char *hex = malloc(sizeof(char) * 10);
  int i = 0;
  while (dec > 0) {
    int rem = dec % 16;
    if (rem < 10) {
      hex[i++] = rem + 48;
    } else {
      hex[i++] = rem + 55;
    }
    dec /= 16;
  }
  hex[i] = '\0';
  // reverse the string
  int len = strlen(hex);
  for (int j = 0; j < len / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[len - j - 1];
    hex[len - j - 1] = temp;
  }
  return hex;
}

int main() {
  char hex[10];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  int dec = hexToDec(hex);
  printf("%s in decimal is %d\n", hex, dec);

  int num = 0;
  printf("Enter a decimal number: ");
  scanf("%d", &num);

  char *hex2 = decToHex(num);
  printf("%d in hexadecimal is %s\n", num, hex2);

  return 0;
}