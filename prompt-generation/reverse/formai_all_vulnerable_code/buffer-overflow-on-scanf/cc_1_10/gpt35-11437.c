//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>

char reverse(char *string) {
   if(string == NULL)
       return 0;
   else {
       int length = strlen(string);
       char reversed[length + 1]; // declare an empty array and add 1 extra space for the null terminating character
       int i, j = 0;
       for(i = length - 1; i >= 0; i--, j++) {
           reversed[j] = string[i]; // assign the i-th character of the input string to the j-th position of the output string
       }
       reversed[j] = '\0'; // add the null terminating character at the end of the output string
       printf("Reversed string is: %s\n", reversed);
       return reversed;
   }
}

int palindrome(char *string) {
   if(string == NULL)
       return 0;
   else {
       int length = strlen(string);
       if(length == 0 || length == 1)
           return 1;
       else {
           char reversed[length + 1]; // declare an empty array and add 1 extra space for the null terminating character
           int i, j = 0;
           for(i = length - 1; i >= 0; i--, j++) {
               reversed[j] = string[i]; // assign the i-th character of the input string to the j-th position of the output string
           }
           reversed[j] = '\0'; // add the null terminating character at the end of the output string
           if(strcmp(string, reversed) == 0)
               return 1;
           else
               return 0;
       }
   }
}

int main() {
   char string[100];
   printf("Enter a string:\n");
   scanf("%[^\n]", string);
   printf("Input string is: %s\n", string);
   if(palindrome(string)) {
       printf("It's a palindrome!\n");
   }
   else {
       printf("It's not a palindrome, but let's see what the reversed string looks like...\n");
       reverse(string);
   }
   return 0;
}