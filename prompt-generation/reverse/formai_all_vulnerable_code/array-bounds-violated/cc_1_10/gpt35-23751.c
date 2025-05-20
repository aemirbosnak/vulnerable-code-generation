//FormAI DATASET v1.0 Category: Text processing ; Style: Alan Touring
// Alan Turing Style C Text Processing Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of input string
#define MAX_LENGTH 100

int main() {
   char input_string[MAX_LENGTH];
   int string_length, i, j, k;
   
   printf("Please enter a string: ");
   
   // Read the input string from the user
   fgets(input_string, MAX_LENGTH, stdin);
   
   // Find the length of the input string
   string_length = strlen(input_string);
   
   // Remove any newline character from the end of the string
   if (input_string[string_length-1] == '\n')
      input_string[string_length-1] = '\0';
   
   // Convert all the characters in the string to uppercase
   for (i = 0; i < string_length; i++) {
      if (input_string[i] >= 'a' && input_string[i] <= 'z')
         input_string[i] = input_string[i] - 32; // 'A' = 'a' - 32
   }
   
   // Reverse the order of words in the string
   i = 0;
   while (input_string[i] != '\0') {
      j = i;
      while (input_string[j] != ' ' && input_string[j] != '\0')
         j++;
      k = j-1;
      while (i < k) {
         char temp = input_string[i];
         input_string[i] = input_string[k];
         input_string[k] = temp;
         i++;
         k--;
      }
      i = j+1;
   }
   
   // Print the modified string
   printf("Modified String: %s\n", input_string);
   
   return 0;
}