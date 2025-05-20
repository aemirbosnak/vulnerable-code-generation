//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>

int main() {

   int n, first = 0, second = 1, next, i;

   printf("Oh Romeo, Romeo! Wherefore art thou Romeo?\n");
   printf("Please enter the number of terms for the Fibonacci sequence:\n");
   scanf("%d",&n);

   printf("My sweet Juliet, let the sequence be:\n");

   for (i = 0; i < n; i++) {

      if (i <= 1)
         next = i;
      else {
         next = first + second;
         first = second;
         second = next;
      }

      printf("%d\n",next);
   }

   printf("O Romeo, Romeo! Wherefore art thou Romeo?\n");
   printf("See how fair my Fibonacci sequence is.\n");
   printf("Alack, there is more to show!\n");

   int row, j, num = 0;

   printf("Enter the number of rows to show the Fibonacci sequence visually:\n");
   scanf("%d",&row);

   printf("Forsooth, here is the visual Fibonacci sequence:\n");

   for (i = 0; i < row; i++) {
      for (j = 0; j <= i; j++) {
         printf("%d ", num);
         next = first + second;
         first = second;
         second = next;
         num = next;
      }
      printf("\n");
   }

   printf("Ah, my dear Juliet. Didst thou like my visual Fibonacci sequence?\n");
   printf("I hope to make thee happy with my code.\n");
   printf("But soft! What light through yonder window breaks?\n");

   return 0;
}