//FormAI DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h> // Standard Input-Output library
#include <stdlib.h> // Standard library
#include <string.h> // String library
 
int main() 
{
   char hex[7]; // Hexadecimal string
   printf("Enter a Hexadecimal Color Code: "); // User prompt
   scanf("%s", hex); // Reads the user input 
   printf("You entered the Hexadecimal Color Code: %s\n", hex); // Prints the user input  

   int r, g, b; // RGB values
   sscanf(hex, "%2x%2x%2x", &r, &g, &b); // Converts the hexadecimal string into RGB values
 
   printf("RGB values of the Hexadecimal Color Code are: \n"); // Output
   printf("Red: %d\n", r);
   printf("Green: %d\n", g);
   printf("Blue: %d\n", b);
 
   float h, s, v; // HSV values
 
   // Convert the RGB values into the HSV values
   // Algorithm source: https://www.rapidtables.com/convert/color/hsv-to-rgb.html
   float r0 = (float)r / 255;
   float g0 = (float)g / 255;
   float b0 = (float)b / 255;
   float cmax = fmaxf(r0, fmaxf(g0, b0));
   float cmin = fminf(r0, fminf(g0, b0));
   float delta = cmax - cmin;
 
   if (delta == 0) {
       h = 0;
   }
   else if (cmax == r0) {
       h = fmodf((g0 - b0) / delta, 6);
   }
   else if (cmax == g0) {
       h = (b0 - r0) / delta + 2;
   }
   else {
       h = (r0 - g0) / delta + 4;
   }
 
   h = h / 6 * 360;
   if (h < 0) {
       h += 360;
   }
 
   if (cmax == 0) {
       s = 0;
   }
   else {
       s = delta / cmax;
   }
 
   v = cmax;

   // Output
   printf("HSV values of the Hexadecimal Color Code are: \n"); 
   printf("Hue: %.2f\n", h);
   printf("Saturation: %.2f\n", s);
   printf("Value: %.2f\n", v);
 
   return 0;
}