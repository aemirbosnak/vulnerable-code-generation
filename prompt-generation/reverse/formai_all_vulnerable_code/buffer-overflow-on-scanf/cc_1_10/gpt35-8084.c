//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>

// function to convert hex color code to RGB values
void hexToRgb(char hexCode[], int *r, int *g, int *b) {
  // loop through the hex code string to extract individual values
  for(int i = 0; i < 6; i++) {
    char c = hexCode[i];
    int val = 0;
    if(c >= '0' && c <= '9') {
      val = c - '0';
    } else if(c >= 'a' && c <= 'f') {
      val = c - 'a' + 10;
    } else if(c >= 'A' && c <= 'F') {
      val = c - 'A' + 10;
    }
    // determine the RGB value based on position in hex code string
    if(i % 2 == 0) {
      *r += val * 16;
    } else if(i % 2 == 1 && i < 4) {
      *g += val * 16;
    } else {
      *b += val * 16;
    }
  }
}

// function to convert RGB values to hex color code
void rgbToHex(int r, int g, int b, char hexCode[]) {
  sprintf(hexCode, "%02X%02X%02X", r, g, b);
}

// main function
int main() {
  char hexCode[7];
  int r = 0, g = 0, b = 0;
  
  // prompt user for hex code input
  printf("Enter a 6-digit hex color code (e.g. FF00FF): ");
  scanf("%s", hexCode);
  
  // convert hex code to RGB
  hexToRgb(hexCode, &r, &g, &b);
  
  // display RGB values
  printf("RGB values: %d, %d, %d\n", r, g, b);
  
  // convert RGB values to hex code
  rgbToHex(r, g, b, hexCode);
  
  // display hex code
  printf("Hex color code: #%s\n", hexCode);
  
  return 0;
}