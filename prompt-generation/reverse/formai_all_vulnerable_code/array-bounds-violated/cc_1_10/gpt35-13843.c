//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This unique compression algorithm will convert a string 
   into a sequence of numbers based on the occurrence 
   of each character in the string */

void compress(char *str) {

   int len = strlen(str);
   int freq[256] = {0};
   int compressed[len];

   printf("\nOriginal String: %s\n", str);

   // Count the frequency of each character in the string
   for (int i = 0; i < len; i++) {
      freq[(int)str[i]]++;
   }

   // Store the frequency of each character in the compressed array
   for (int i = 0; i < len; i++) {
      compressed[i] = freq[(int)str[i]];
   }

   printf("Compressed String: ");

   // Print the compressed string
   for (int i = 0; i < len; i++) {
      printf("%d", compressed[i]);
      if (i != len-1) {
         printf(",");
      }
   }
}

int main() {

   char input[100];

   // Get input from user
   printf("Enter a string to compress: ");
   fgets(input, sizeof(input), stdin);
   input[strcspn(input, "\n")] = 0;

   // Compress the string
   compress(input);

   return 0;
}