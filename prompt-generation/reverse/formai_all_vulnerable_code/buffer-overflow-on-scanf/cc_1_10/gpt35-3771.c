//FormAI DATASET v1.0 Category: Color Code Converter ; Style: grateful
// Hello there! Welcome to my Color Code Converter program.
// This program will convert RGB values to hexadecimal values and vice versa.
// It's going to be a fun and colorful ride, so hold on tight!

#include <stdio.h>

// The following function takes the RGB values as input and returns the corresponding hexadecimal value.
int RGB_to_hex(int R, int G, int B) {
   
   int hex_value = 0x0;
   
   // Left shift the Red value by 16, Green by 8 and Blue by 0 bits to convert to hex value.
   hex_value |= (R << 16);
   hex_value |= (G << 8);
   hex_value |= (B << 0);

   return hex_value;
}

// The following function takes the hexadecimal value as input and returns the corresponding RGB values.
void hex_to_RGB(int hex_value, int *R, int *G, int *B) {
   
   // Right shift the hex value by 16 to get the Red value, mask it with 0xFF to keep only the last 8 bits.
   *R = (hex_value >> 16) & 0xFF;

   // Right shift the hex value by 8 to get the Green value, mask it with 0xFF to keep only the last 8 bits.
   *G = (hex_value >> 8) & 0xFF;

   // Mask the hex value with 0xFF to keep only the last 8 bits to get the Blue value.
   *B = hex_value & 0xFF;
}

// The main function that drives the program.
int main() {

   int R, G, B, hex_value;
   
   // Take user input for the RGB values.
   printf("Enter the Red value (0-255): ");
   scanf("%d", &R);
   printf("Enter the Green value (0-255): ");
   scanf("%d", &G);
   printf("Enter the Blue value (0-255): ");
   scanf("%d", &B);

   // Convert the RGB values to hexadecimal value and print it.
   hex_value = RGB_to_hex(R, G, B);
   printf("\nHexadecimal Value: %X\n\n", hex_value);

   // Take user input for the hexadecimal value.
   printf("Enter the Hexadecimal value (in format 0xXXXXXX): ");
   scanf("%x", &hex_value);

   // Convert the hexadecimal value to RGB values and print them.
   hex_to_RGB(hex_value, &R, &G, &B);
   printf("\nRGB Values: R = %d, G = %d, B = %d\n\n", R, G, B);

   return 0;
}