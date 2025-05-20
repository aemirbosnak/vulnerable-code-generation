//FormAI DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This program is a C Color Code Converter!
// Enter either a hexadecimal or RGB color code and it will convert it to the other format.

int main() {
  char hexCode[7], rgbCode[12];
  int red, green, blue;

  printf("Welcome to the C Color Code Converter!\n");
  printf("Please enter a color code in either hexadecimal or RGB format.\n");

  printf("Enter hex code: ");
  scanf("%s", hexCode);

  if (strlen(hexCode) == 6) { // check for valid hex code

    red = (int)strtol(strncpy(rgbCode, hexCode, 2), NULL, 16); // extract red component
    green = (int)strtol(strncpy(rgbCode + 4, hexCode + 2, 2), NULL, 16); // extract green component
    blue = (int)strtol(strncpy(rgbCode + 8, hexCode + 4, 2), NULL, 16); // extract blue component

    printf("RGB code: %d, %d, %d\n", red, green, blue);

  } else if (strlen(hexCode) == 7 && hexCode[0] == '#') { // check for valid hex code with '#' prefix

    red = (int)strtol(strncpy(rgbCode, hexCode + 1, 2), NULL, 16); // extract red component
    green = (int)strtol(strncpy(rgbCode + 4, hexCode + 3, 2), NULL, 16); // extract green component
    blue = (int)strtol(strncpy(rgbCode + 8, hexCode + 5, 2), NULL, 16); // extract blue component

    printf("RGB code: %d, %d, %d\n", red, green, blue);

  } else if (strlen(hexCode) == 3) { // check for valid shorthand hex code (e.g. #FFF)

    red = (int)strtol(strncpy(rgbCode, hexCode, 1), NULL, 16) * 17; // expand shorthand red component
    green = (int)strtol(strncpy(rgbCode + 4, hexCode + 1, 1), NULL, 16) * 17; // expand shorthand green component
    blue = (int)strtol(strncpy(rgbCode + 8, hexCode + 2, 1), NULL, 16) * 17; // expand shorthand blue component

    printf("RGB code: %d, %d, %d\n", red, green, blue);

  } else { // invalid hex code

    printf("Invalid hex code entered.\n");

  }

  printf("Enter RGB code (with commas between components): ");
  scanf("%d,%d,%d", &red, &green, &blue);

  if (red >= 0 && red <= 255 && green >= 0 && green <= 255 && blue >= 0 && blue <= 255) { // check for valid RGB code

    sprintf(hexCode, "%02X%02X%02X", red, green, blue); // convert to hex code

    printf("Hex code: #%s\n", hexCode);

  } else { // invalid RGB code

    printf("Invalid RGB code entered.\n");

  }

  return 0;
}