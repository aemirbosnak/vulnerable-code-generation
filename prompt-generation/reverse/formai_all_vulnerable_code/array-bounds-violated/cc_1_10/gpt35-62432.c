//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>

int main() {
   int numTerms; 
   
   printf("Enter the number of terms in the Fibonacci sequence: ");
   scanf("%d", &numTerms);
   
   int sequence[numTerms];
   
   // initialize the first two terms of the sequence
   sequence[0] = 0;
   sequence[1] = 1;
   
   // generate the rest of the sequence
   for (int i = 2; i < numTerms; i++) {
      sequence[i] = sequence[i-1] + sequence[i-2];
   }
   
   // print out the sequence
   printf("\nFibonacci sequence of %d terms:\n", numTerms);
   for (int i = 0; i < numTerms; i++) {
      printf("%d ", sequence[i]);
   }
   
   // visualize the sequence with an ASCII art bar chart
   printf("\n\nFibonacci sequence visualization:\n");
   int maxVal = sequence[numTerms-1];
   for (int i = 0; i < numTerms; i++) {
      int val = sequence[i];
      
      // calculate the length of the bar and the number of spaces to add before the bar
      int barLength = (float)val / maxVal * 50;
      int numSpaces = 50 - barLength;
      
      // print out the bar chart for this value
      printf("%d: ", val);
      for (int j = 0; j < numSpaces/2; j++) {
         printf(" ");
      }
      for (int j = 0; j < barLength; j++) {
         printf("*");
      }
      for (int j = 0; j < numSpaces - numSpaces/2; j++) {
         printf(" ");
      }
      printf("\n");
   }
   
   return 0;
}