//FormAI DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>

int main() {
  char choice;
  printf("Choose conversion type: \n");
  printf("Enter 1 for RGB to Hex \n");
  printf("Enter 2 for Hex to RGB \n");
  scanf("%c", &choice);

  switch (choice) {
    case '1':
      {
        int r, g, b;
        printf("Enter RGB values (each 0-255): \n");
        scanf("%d %d %d", &r, &g, &b);

        // validate input
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
          printf("Invalid RGB values entered. \n");
          return 0;
        }

        // convert values to hex
        char hex[7];
        sprintf(hex, "#%02X%02X%02X", r, g, b);
        printf("Hex equivalent: %s \n", hex);
        break;
      }
    case '2':
      {
        char hex[7];
        printf("Enter Hex value (include '#'): \n");
        scanf("%s", hex);

        if (hex[0] != '#' || strlen(hex) != 7) {
          printf("Invalid Hex value entered. \n");
          return 0;
        }

        // convert hex to RGB
        int r, g, b;
        sscanf(hex+1, "%02x%02x%02x", &r, &g, &b);
        printf("RGB equivalent: %d %d %d \n", r, g, b);
        break;
      }
    default:
      printf("Invalid conversion type. \n");
  }

  return 0;
}