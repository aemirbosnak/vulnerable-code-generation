//FormAI DATASET v1.0 Category: Computer Biology ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A program that accepts user input and performs a DNA analysis */

int main() {
   char dna[50];
   int length;
   int i;
   int a_count = 0;
   int t_count = 0;
   int c_count = 0;
   int g_count = 0;

   /* prompt user for input */
   printf("Enter a DNA sequence of up to 50 characters: ");
   scanf("%s", dna);

   length = strlen(dna);

   /* count the number of each nucleotide */
   for(i = 0; i < length; i++) {
      switch(dna[i]) {
         case 'A':
         case 'a':
            a_count++;
            break;
         case 'T':
         case 't':
            t_count++;
            break;
         case 'C':
         case 'c':
            c_count++;
            break;
         case 'G':
         case 'g':
            g_count++;
            break;
         default:
            printf("Invalid nucleotide: %c", dna[i]);
            return 0;
      }
   }

   /* print totals */
   printf("Total A's: %d\n", a_count);
   printf("Total T's: %d\n", t_count);
   printf("Total C's: %d\n", c_count);
   printf("Total G's: %d\n", g_count);

   /* calculate GC content */
   float gc_percent = ((float)c_count + g_count) / length * 100;
   printf("GC content: %.2f%%\n", gc_percent);

   /* check for palindrome */
   int is_palindrome = 1;
   for(i = 0; i < length / 2; i++) {
      if(dna[i] != dna[length - i - 1]) {
         is_palindrome = 0;
         break;
      }
   }
   if(is_palindrome) {
      printf("The DNA sequence is a palindrome\n");
   } else {
      printf("The DNA sequence is not a palindrome\n");
   }

   return 0;
}