//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50];  // Declare two char arrays to hold strings
   int len1, len2, i, j, res; // Declare variables needed for calculation

   printf("Surprise! Let's calculate the Levenshtein Distance between two strings.\n");

   // Ask user to input first string
   printf("Enter the first string: ");
   scanf("%s", str1);

   // Ask user to input second string
   printf("Enter the second string: ");
   scanf("%s", str2);

   // Calculate lengths of both strings
   len1 = strlen(str1);
   len2 = strlen(str2);
   
   int arr[len1+1][len2+1]; // Declare 2D array to hold distance values

   printf("\nCalculating distance...");

   // Initialize first row and column of array based on the lengths of strings
   for (i = 0; i <= len1; i++)
        arr[i][0] = i;
   for (j = 0; j <= len2; j++)
        arr[0][j] = j;
   
   // Calculate distance values for each position in array
   for (i = 1; i <= len1; i++) {
      for (j = 1; j <= len2; j++) {

         // If letters match, cost is zero
         if (str1[i-1] == str2[j-1])
            arr[i][j] = arr[i-1][j-1];

         // If letters don't match, find minimum cost and add 1
         else
            arr[i][j] = 1 + ( arr[i-1][j] < arr[i][j-1] ? arr[i-1][j] : arr[i][j-1] );
      }
   }

   // The result is the value in the bottom right of the array
   res = arr[len1][len2];

   printf("\nThe Levenshtein Distance between %s and %s is %d.\n", str1, str2, res);

   return 0;
}