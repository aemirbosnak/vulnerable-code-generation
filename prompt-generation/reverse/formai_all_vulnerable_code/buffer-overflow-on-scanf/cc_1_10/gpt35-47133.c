//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>

int hexToDec(char hexDigit) {
  if (hexDigit >= '0' && hexDigit <= '9') {
    return hexDigit - '0';
  } else if (hexDigit >= 'A' && hexDigit <= 'F') {
    return 10 + hexDigit - 'A';
  } else if (hexDigit >= 'a' && hexDigit <= 'f') {
    return 10 + hexDigit - 'a';
  } else {
    printf("Invalid input!\n");
    return -1;
  }
}

void hexColorToRGB(char *hexColor, int *r, int *g, int *b) {
  *r = hexToDec(hexColor[0])*16 + hexToDec(hexColor[1]);
  *g = hexToDec(hexColor[2])*16 + hexToDec(hexColor[3]);
  *b = hexToDec(hexColor[4])*16 + hexToDec(hexColor[5]);
}

char decToHex(int decDigit) {
  if (decDigit >= 0 && decDigit <= 9) {
    return '0' + decDigit;
  } else if (decDigit >= 10 && decDigit <= 15) {
    return 'a' + (decDigit - 10);
  } else {
    printf("Invalid input!\n");
    return '\0';
  }
}

void RGBtoHexColor(int r, int g, int b, char *hexColor) {
  hexColor[0] = decToHex(r/16);
  hexColor[1] = decToHex(r%16);
  hexColor[2] = decToHex(g/16);
  hexColor[3] = decToHex(g%16);
  hexColor[4] = decToHex(b/16);
  hexColor[5] = decToHex(b%16);
  hexColor[6] = '\0'; // Null character to terminate C string
}

int main() {
  char hexColor[7];
  int r, g, b;

  printf("Enter a 6-digit hexadecimal color code: ");
  scanf("%s", hexColor);

  hexColorToRGB(hexColor, &r, &g, &b);

  printf("The RGB values are: %d %d %d\n", r, g, b);

  RGBtoHexColor(r, g, b, hexColor);

  printf("The converted hexadecimal color code is: %s\n", hexColor);

  return 0;
}