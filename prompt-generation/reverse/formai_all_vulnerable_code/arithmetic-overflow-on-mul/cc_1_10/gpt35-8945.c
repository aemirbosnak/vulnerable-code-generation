//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 16 // Maximum length of a hexadecimal string (excluding 0x prefix)

// Function to convert a hexadecimal string to an integer value
int hexToInt(char* hex)
{
   int len = strlen(hex);
   
   // Check if the string starts with 0x prefix
   if(len > 2 && hex[0] == '0' && hex[1] == 'x')
      hex += 2; // Skip the 0x prefix
   
   len = strlen(hex);
   int result = 0;

   for(int i = 0; i < len; i++)
   {
      char c = hex[i];
      int val;

      if(c >= '0' && c <= '9')
         val = c - '0';
      else if(c >= 'a' && c <= 'f')
         val = c - 'a' + 10;
      else if(c >= 'A' && c <= 'F')
         val = c - 'A' + 10;
      else
      {
         printf("Error: Invalid character '%c' in hexadecimal string '%s'\n", c, hex);
         return -1;
      }

      result = result * 16 + val;
   }

   return result;
}

// Function to convert an integer value to a hexadecimal string
char* intToHex(int num)
{
   char* hex = (char*) malloc(MAX_HEX_LENGTH + 3);
   sprintf(hex, "0x%x", num);
   return hex;
}

int main()
{
   char hexStr[MAX_HEX_LENGTH + 3]; // +3 to account for 0x prefix and null terminator
   
   // Prompt the user to enter a hexadecimal string
   printf("Enter a hexadecimal string: ");
   fgets(hexStr, MAX_HEX_LENGTH + 3, stdin); // Read hex string with fgets to prevent buffer overflow

   // Remove newline character from input
   if(strlen(hexStr) > 0 && hexStr[strlen(hexStr) - 1] == '\n')
      hexStr[strlen(hexStr) - 1] = '\0';

   // Convert hexadecimal string to integer
   int num = hexToInt(hexStr);
   if(num == -1) // Handle invalid input
      return 1;

   // Convert integer to hexadecimal string and print the result
   char* hex = intToHex(num);
   printf("The hexadecimal value of %d is %s\n", num, hex);
   free(hex);

   return 0;
}