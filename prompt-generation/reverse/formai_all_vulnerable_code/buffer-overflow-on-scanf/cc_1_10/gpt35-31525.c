//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <string.h>

void dec_to_hex(int decimal, char *hexadecimal) {
  int i, remainder, quotient;

  i = 1;
  quotient = decimal;

  while (quotient != 0) {
    remainder = quotient % 16;

    if (remainder < 10)
      hexadecimal[strlen(hexadecimal) - i] = 48 + remainder;
    else
      hexadecimal[strlen(hexadecimal) - i] = 55 + remainder;

    i++;
    quotient = quotient / 16;
  }
}

int hex_to_dec(char *hexadecimal) {
  int decimal = 0, i, j, power;

  for (i = strlen(hexadecimal) - 1, j = 0; i >= 0; i--, j++) {
    if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
      decimal += (hexadecimal[i] - '0') * (1 << (j * 4));
    else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f')
      decimal += (hexadecimal[i] - 'a' + 10) * (1 << (j * 4));
    else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
      decimal += (hexadecimal[i] - 'A' + 10) * (1 << (j * 4));
  }

  return decimal;
}

int main() {
  int decimal, choice;
  char hexadecimal[100], repeat;

  do {
    printf("Enter your choice:\n");
    printf("1: Decimal to Hexadecimal Conversion.\n");
    printf("2: Hexadecimal to Decimal Conversion.\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        printf("Enter the decimal number: ");
        scanf("%d", &decimal);

        snprintf(hexadecimal, sizeof(hexadecimal), "%X", decimal);
        printf("The hexadecimal representation of decimal %d is: %s\n ", decimal, hexadecimal);

        break;
      }

      case 2: {
        printf("Enter the hexadecimal number: ");
        scanf("%s", hexadecimal);

        decimal = hex_to_dec(hexadecimal);
        printf("The decimal representation of hexadecimal %s is: %d\n", hexadecimal, decimal);

        break;
      }

      default:
        printf("Invalid choice! Please choose 1 or 2.\n");
    }

    printf("Do you want to convert another number? (y/n): ");
    scanf(" %c", &repeat);
  } while (repeat == 'y');

  return 0;
}