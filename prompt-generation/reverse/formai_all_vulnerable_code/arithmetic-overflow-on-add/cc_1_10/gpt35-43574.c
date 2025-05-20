//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void main() {
  int red, green, blue;
  printf("Welcome to the Surrealist Color Code Converter!\n");
  printf("Enter the RGB values for your color:\n");
  printf("Red (0-255): ");
  scanf("%d", &red);
  printf("Green (0-255): ");
  scanf("%d", &green);
  printf("Blue (0-255): ");
  scanf("%d", &blue);

  int sum = red + green + blue;
  int hex1 = sum % 16;
  int hex2 = (sum / 16) % 16;
  int hex3 = (sum / 256) % 16;

  printf("\nYour color code is: #");
  if (hex1 == 0) {
    printf("00");
  } else if (hex1 < 6) {
    printf("0%d", hex1 * 10);
  } else if (hex1 < 10) {
    printf("%d0", hex1);
  } else {
    printf("%d", hex1);
  }

  if (hex2 == 0) {
    printf("00");
  } else if (hex2 < 6) {
    printf("0%d", hex2 * 10);
  } else if (hex2 < 10) {
    printf("%d0", hex2);
  } else {
    printf("%d", hex2);
  }

  if (hex3 == 0) {
    printf("00");
  } else if (hex3 < 6) {
    printf("0%d", hex3 * 10);
  } else if (hex3 < 10) {
    printf("%d0", hex3);
  } else {
    printf("%d", hex3);
  }

  printf("\n\nThank you for using the Surrealist Color Code Converter!\n");
  printf("Remember to always think outside the box!\n");
}