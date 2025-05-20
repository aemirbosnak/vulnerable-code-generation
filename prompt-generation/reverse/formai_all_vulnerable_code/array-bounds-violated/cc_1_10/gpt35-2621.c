//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

/* This function converts a string into all uppercase */
void toUpperCase(char *str) { 
   while(*str) {
      if(*str >= 'a' && *str <= 'z') {
         *str = (*str - 'a') + 'A'; // converting lowercase to uppercase
      }
      str++;
   }
}

/* This function reverses a string */
void reverseString(char *str) { 
   size_t len = strlen(str);
   int i, j;

   for(i = 0, j = len-1; i < j; i++, j--) { // swapping characters from start to end
      char temp = str[i];
      str[i] = str[j];
      str[j] = temp;
   }
}

int main() {
   char str[100];

   /* Asking user for input */
   printf("Enter a string: ");
   scanf("%s", str);

   /* Converting the string to uppercase */
   toUpperCase(str);
   printf("Uppercase string: %s\n", str);

   /* Reversing the string */
   reverseString(str);
   printf("Reversed string: %s\n", str);

   /* Finding the middle character in the string */
   int len = strlen(str);
   int mid = len / 2;
   char middleChar;
   if(len % 2 == 0) { // if the length of the string is even
      middleChar = str[mid-1];
   }
   else { // if the length of the string is odd
      middleChar = str[mid];
   }
   printf("Middle character in the string: %c\n", middleChar);

   /* Finding the number of vowels in the string */
   int vowelCount = 0;
   for(int i = 0; i < len; i++) {
      char ch = str[i];
      if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
         vowelCount++;
      }
   }
   printf("Number of vowels in the string: %d\n", vowelCount);

   /* Removing all the consonants from the string */
   char result[100];
   int index = 0;
   for(int i = 0; i < len; i++) {
      char ch = str[i];
      if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
         result[index++] = ch;
      }
   }
   printf("String with only vowels: %s\n", result);

   return 0;
}