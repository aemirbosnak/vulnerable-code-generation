//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>

int main() {
   int num, i, j, k, n, rem, quotient, choice;
   char hex[100];
   
   printf("Welcome to the Hexadecimal Converter Program.\n");
   
   printf("Enter your choice:\n");
   printf("1. Decimal to Hexadecimal Conversion\n");
   printf("2. Hexadecimal to Decimal Conversion\n");
   scanf("%d", &choice);
   
   switch(choice) {
      case 1:
         printf("Enter a decimal number: ");
         scanf("%d", &num);
         
         quotient = num;
         i = 0;
         
         while(quotient != 0) {
            rem = quotient % 16;
            
            if(rem < 10) {
               hex[i] = rem + 48;
               i++;
            }
            else {
               hex[i] = rem + 55;
               i++;
            }
            
            quotient = quotient / 16;
         }
         
         printf("Hexadecimal equivalent of %d is: ", num);
         for(j = i -1; j >= 0; j--)
            printf("%c", hex[j]);
            
         break;
      
      case 2:
         printf("Enter a hexadecimal number: ");
         scanf("%s", hex);
         
         n = 0;
         rem = 0;
         j = 0;
         
         for(i = (strlen(hex)-1); i >= 0; i--) {
            if(hex[i] >= '0' && hex[i] <= '9') {
               rem = hex[i] - '0';
            }
            else if(hex[i] >= 'A' && hex[i] <= 'F') {
               rem = hex[i] - 'A' + 10;
            }
            else if(hex[i] >= 'a' && hex[i] <= 'f') {
               rem = hex[i] - 'a' + 10;
            }
            
            n += (rem * pow(16, j));
            j++;
         }
         
         printf("Decimal equivalent of %s is: %d", hex, n);
         
         break;
      
      default:
         printf("Wrong choice! Please enter 1 or 2.");
         
   }
   
   return 0;
}