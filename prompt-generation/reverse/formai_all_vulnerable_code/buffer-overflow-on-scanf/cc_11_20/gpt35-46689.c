//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
#include<stdio.h>

int main() {

   int a[5][5], b[5][5], mult[5][5], r1, c1, r2, c2, i, j, k;

   printf("Enter rows and column for first matrix: ");
   scanf("%d %d", &r1, &c1);

   printf("Enter rows and column for second matrix: ");
   scanf("%d %d",&r2, &c2);

   // If column of first matrix in not equal to row of second matrix,
   // ask the user to enter the size again.
   while (c1 != r2) {
       printf("Error! column of first matrix not equal to row of second.\n");
       printf("Enter rows and column for first matrix: ");
       scanf("%d %d", &r1, &c1);
       printf("Enter rows and column for second matrix: ");
       scanf("%d %d",&r2, &c2);
   }

   // Get elements of first matrix.
   printf("\nEnter elements of matrix 1:\n");
   for (i = 0; i < r1; ++i)
       for (j = 0; j < c1; ++j) {
           printf("Enter element a%d%d: ", i + 1, j + 1);
           scanf("%d", &a[i][j]);
       }

   // Get elements of second matrix.
   printf("\nEnter elements of matrix 2:\n");
   for (i = 0; i < r2; ++i)
       for (j = 0; j < c2; ++j) {
           printf("Enter element b%d%d: ", i + 1, j + 1);
           scanf("%d", &b[i][j]);
       }

   // Initializing elements of mult to 0.
   for (i = 0; i < r1; ++i)
       for (j = 0; j < c2; ++j) {
           mult[i][j] = 0;
       }

   // Multiplying matrices a and b and storing in array mult.
   for (i = 0; i < r1; ++i)
       for (j = 0; j < c2; ++j)
           for (k = 0; k < c1; ++k) {
               mult[i][j] += a[i][k] * b[k][j];
           }

   // Displaying the multiplication of two matrices.
   printf("\nOutput Matrix:\n");
   for (i = 0; i < r1; ++i)
       for (j = 0; j < c2; ++j) {
           printf("%d  ", mult[i][j]);
           if (j == c2 - 1) {
               printf("\n\n");
           }
       }

   return 0;
}