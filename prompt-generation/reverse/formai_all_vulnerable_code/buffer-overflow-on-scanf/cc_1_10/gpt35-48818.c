//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char hex[17];
   long int decimal = 0, place = 1;
   int i = 0, val, len;
   char choice;

   printf("Hello, my dear. I have a little something for you today.\n");
   printf("I have created a C program that will convert hexadecimal numbers to decimal numbers.\n");
   printf("Isn't that romantic? Let me show you how it works.\n");

   do {
       printf("\nEnter a hexadecimal number: ");
       scanf("%s", hex);
       len = strlen(hex);
       len--;

       for(i=0;hex[i]!='\0';i++)
       {
           if(hex[i]>='0' && hex[i]<='9')
           {
               val = hex[i] - 48;
           }
           else if(hex[i]>='a' && hex[i]<='f')
           {
               val = hex[i] - 97 + 10;
           }
           else if(hex[i]>='A' && hex[i]<='F')
           {
               val = hex[i] - 65 + 10;
           }

           decimal += val * pow(16, len);
           len--;
       }

       printf("\nThe decimal number is: %ld", decimal);

       printf("\n\nDo you want to convert another hexadecimal number? (y/n): ");
       scanf(" %c", &choice);
       decimal = 0;

   } while(choice == 'y' || choice == 'Y');

   printf("\nThank you my dear for trying my program out.\n");
   return 0;
}