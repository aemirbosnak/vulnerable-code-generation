//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 2000

int main() {
   char original_string[MAX_CHARACTERS]; // original string
   char compressed_string[MAX_CHARACTERS]; // compressed string
   int frequency[MAX_CHARACTERS]; // characters frequency array
   int compressed_frequency[MAX_CHARACTERS]; // compressed characters frequency array
   int i, j, k, l, flag, compressed_length, original_length;
        
   printf("Enter the original string: ");
   fgets(original_string, MAX_CHARACTERS, stdin);
   original_length = strlen(original_string);

   for (i = 0; i < original_length; i++) {
       flag = 0;
       for (j = 0; j < i; j++) {
           if (original_string[i] == original_string[j]) {
               flag = 1;
               frequency[j]++;
               break;
           }
       }
       if (!flag) {
            frequency[i] = 1;
            compressed_string[k++] = original_string[i];
       }
   }

   compressed_length = k;

   for (i = 0; i < compressed_length; i++) {
       compressed_frequency[i] = frequency[i];
       for (j = i+1; j < compressed_length; j++) {
           if (compressed_string[i] == compressed_string[j]) {
               compressed_frequency[i] += frequency[j];
               for (k = j; k < compressed_length-1; k++) {
                    compressed_string[k] = compressed_string[k+1];
                    compressed_frequency[k] = compressed_frequency[k+1];
               }
               compressed_length--;
            }
       }
   }
          
   printf("\nOriginal String: %s", original_string);

   printf("\nCompressed String: ");
   for (i = 0; i < compressed_length; i++) {
       printf("%c", compressed_string[i]);
   }

   printf("\nCompressed String Length: %d", compressed_length);

   printf("\nCharacter\tFrequency in Original String\tFrequency in Compressed String\n");
   for (i = 0; i < compressed_length; i++) {
       printf("%c\t\t\t%d\t\t\t\t%d\n", compressed_string[i], frequency[i], compressed_frequency[i]);
   }
   return 0;
}