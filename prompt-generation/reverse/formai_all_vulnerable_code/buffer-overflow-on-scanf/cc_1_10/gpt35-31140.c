//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int x, int y, int z) {
   if(x < y) {
      if(x < z) {
         return x;
      } else {
         return z;
      }
   } else {
      if(y < z) {
         return y;
      } else {
         return z;
      }
   }
}

int levenshteinDistance(char *s1, char *s2, int len_s1, int len_s2) {
   int cost = 0;
   int matrix[len_s1 + 1][len_s2 + 1];
   for(int i = 0; i <= len_s1; i++) {
      matrix[i][0] = i;
   }

   for(int j = 0; j <= len_s2; j++) {
      matrix[0][j] = j;
   }

   for(int i = 1; i <= len_s1; i++) {
      for(int j = 1; j <= len_s2; j++) {
         if(s1[i - 1] == s2[j - 1]) {
            cost = 0;
         } else {
            cost = 1;
         }

         matrix[i][j] = min(matrix[i - 1][j] + 1,
                              matrix[i][j - 1] + 1,
                              matrix[i - 1][j - 1] + cost);
      }
   }

   return matrix[len_s1][len_s2];
}

int main() {
   char str1[50], str2[50];
   int distance;

   printf("Enter string 1: ");
   scanf("%s", str1);

   printf("Enter string 2: ");
   scanf("%s", str2);

   distance = levenshteinDistance(str1, str2, strlen(str1), strlen(str2));
   printf("\nLevenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

   return 0;
}