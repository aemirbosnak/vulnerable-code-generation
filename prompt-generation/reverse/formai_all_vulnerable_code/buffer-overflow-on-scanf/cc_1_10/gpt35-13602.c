//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>

// Function to convert decimal to hexadecimal
int decimalToHexadecimal(int decimalNumber) {
   if(decimalNumber == 0) {
      return 0;
   } else {
      return (decimalNumber % 16) + 10 * decimalToHexadecimal(decimalNumber / 16);
   }
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hex[]) {
   int decimalNumber = 0, i = 0;

   // Find the length of the hexadecimal number
   while(hex[i] != '\0') {
      i++;
   }

   // Calculate the decimal equivalent of the given hexadecimal number
   int baseVal = 1;
   for(int j = i-1; j >= 0; j--) {
      if(hex[j] >= '0' && hex[j] <= '9') {
         decimalNumber += (hex[j] - '0') * baseVal;
      } else if(hex[j] >= 'A' && hex[j] <= 'F') {
         decimalNumber += (hex[j] - 55) * baseVal;
      } else if(hex[j] >= 'a' && hex[j] <= 'f') {
         decimalNumber += (hex[j] - 87) * baseVal;
      }
      baseVal *= 16;
   }

   return decimalNumber;
}

int main() {
   int decimalNumber, choice;
   char hex[20];
 
   // Display Menu
   printf("Choose Conversion Type: \n");
   printf("1. Decimal to Hexadecimal\n");
   printf("2. Hexadecimal to Decimal\n");
   scanf("%d", &choice);

   // User Input
   switch(choice) {
      case 1:
         printf("Enter Decimal Number: ");
         scanf("%d", &decimalNumber);
         printf("The Hexadecimal Number is: %X", decimalToHexadecimal(decimalNumber));
         break;
      case 2:
         printf("Enter Hexadecimal Number: ");
         scanf("%s", hex);
         printf("The Decimal Number is: %d", hexadecimalToDecimal(hex));
         break;
      default:
         printf("Invalid Choice.");
   }

   return 0;
}