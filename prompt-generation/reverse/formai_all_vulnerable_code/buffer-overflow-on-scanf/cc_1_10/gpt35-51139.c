//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
// Romeo, a C programmer, meets Juliet, a hexadecimal converter program
#include <stdio.h>
#include <string.h>

int main() {
   char hex[17], hexVal;
   int i, decimalValue = 0, value;
   
   // Romeo meets Juliet
   printf("Oh, what a bright star shines in the world of programming!\n");
   printf("Who art thou, O charming program of conversion?\n");
   printf("Ah, fair Juliet, thy name befits thy beauty!\n");
   printf("I am a hexadecimal converter, dear Romeo.\n");
   printf("My code converts hexadecimal to decimal and vice versa.\n\n");

   while (1) {
      // Romeo asks for input
      printf("O Juliet, pray tell, what shall we convert today?\n");
      printf("Please input a hexadecimal number: ");
      fflush(stdout);
      
      // Juliet receives and processes input
      scanf("%s", hex);
      printf("\n");
      
      // Romeo marvels at Juliet's beauty and intelligence
      printf("Thou art truly a marvel, O Juliet!\n");
      printf("How swiftly thou hast converted %s to decimal!\n", hex);

      // Juliet converts hex to decimal
      for (i = 0; hex[i] != '\0'; i++) {
         hexVal = hex[i];
         if (hexVal >= '0' && hexVal <= '9') {
            value = hexVal - 48;
         }
         else if (hexVal >= 'a' && hexVal <= 'f') {
            value = hexVal - 97 + 10;
         }
         else if (hexVal >= 'A' && hexVal <= 'F') {
            value = hexVal - 65 + 10;
         }
         decimalValue = decimalValue * 16 + value;
      }

      // Romeo congratulates Juliet on her success
      printf("\nBravo, fair Juliet! Thy result is: %d\n", decimalValue);
      printf("However, I must ask, what dost thou think of my code?\n");
      printf("Is it not romantic, like our love, O fair Juliet?\n\n");

      // Juliet responds to Romeo's request for feedback
      printf("Sweet Romeo, thy code is as beautiful as thy love for me.\n");
      printf("Truly, there is no flaw in the programming of thy heart.\n");
      printf("But alas, the code can always be optimized, my love!\n");
      printf("I shall work on it henceforth with all my might, O Romeo!\n\n");

      // Romeo and Juliet exchange sweet nothings before parting ways
      printf("Farewell, my love, until we meet again!\n");
      printf("May the programming gods bless us with fast compilers and perfect code.\n\n");
	   
	   // Reset decimalValue for next input
      decimalValue = 0;
   }
   return 0;
}