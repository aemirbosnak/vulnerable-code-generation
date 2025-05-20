//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>

char intToHex(int num) {
  if (num < 10) {
    return num + '0';
  } else {
    return num - 10 + 'A';
  }
}

int hexToInt(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else {
    return -1;
  }
}

void decToHex(int num) {
  int rem, i, len = 0;
  char hex[100];

  while (num > 0) {
    rem = num % 16;

    hex[len] = intToHex(rem);

    len++;
    num /= 16;
  }

  for (i = len - 1; i >= 0; i--) {
    printf("%c", hex[i]);
  }
}

int hexToDec(char hex[]) {
  int i, len, base = 1, dec = 0;

  for (len = 0; hex[len] != '\0'; len++);

  for (i = len - 1; i >= 0; i--) {
    if (hexToInt(hex[i]) == -1) {
      printf("\nInvalid hexadecimal digit %c", hex[i]);
      return -1;
    }

    dec += hexToInt(hex[i]) * base;
    base *= 16;
  }

  return dec;
}

int main() {
  int num;
  char hex[100];

  printf("Enter a decimal number: ");
  scanf("%d", &num);
  printf("Hexadecimal number is: ");
  decToHex(num);

  printf("\nEnter a hexadecimal number: ");
  scanf("%s", hex);
  printf("Decimal number is: %d", hexToDec(hex));

  return 0;
}