//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
   int min_val = a < b ? a : b;
   min_val = min_val < c ? min_val : c;
   return min_val;
}

int get_levenshtein_distance(char *str1, int len1, char *str2, int len2) {
   int matrix[len1 + 1][len2 + 1];

   for(int i = 0; i <= len1; i++) {
      for(int j = 0; j <= len2; j++) {
         if(i == 0) {
            matrix[i][j] = j;
         }
         else if(j == 0) {
            matrix[i][j] = i;
         }
         else if(str1[i - 1] == str2[j - 1]) {
            matrix[i][j] = matrix[i - 1][j - 1];
         }
         else {
            matrix[i][j] = 1 + min(
               matrix[i][j - 1], // Insert
               matrix[i - 1][j], // Remove
               matrix[i - 1][j - 1]); // Replace
         }
      }
   }

   return matrix[len1][len2];
}

int main() {
   char str1[MAX_LEN];
   char str2[MAX_LEN];

   printf("Enter first string: ");
   scanf("%s", str1);

   printf("Enter second string: ");
   scanf("%s", str2);

   int len1 = strlen(str1);
   int len2 = strlen(str2);

   int distance = get_levenshtein_distance(str1, len1, str2, len2);

   printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

   return 0;
}