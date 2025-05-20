//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include <stdio.h>
#include <string.h>

// function to calculate the minimum of three numbers
int min(int a, int b, int c) {
   if (a <= b && a <= c) return a;
   else if (b <= a && b <= c) return b;
   else return c;
}

// function to calculate the Levenshtein Distance
int levenshtein_distance(char* word1, char* word2) {
   int n = strlen(word1);
   int m = strlen(word2);
   int distance[n+1][m+1];

   // fill the first row and column with 0 to n and 0 to m respectively
   for (int i = 0; i <= n; i++) distance[i][0] = i;
   for (int j = 0; j <= m; j++) distance[0][j] = j;

   // loop through each character of the words
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         // if the characters are same then there is no cost
         int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;

         // calculate the minimum distance
         int delete = distance[i-1][j] + 1;
         int insert = distance[i][j-1] + 1;
         int substitute = distance[i-1][j-1] + cost;
         distance[i][j] = min(delete, insert, substitute);
      }
   }

   // return the distance between the words
   return distance[n][m];
}

int main() {
   char word1[100], word2[100];
   printf("Enter the first word: ");
   scanf("%s", &word1);
   printf("Enter the second word: ");
   scanf("%s", &word2);

   int distance = levenshtein_distance(word1, word2);
   printf("The Levenshtein Distance between %s and %s is %d.\n", word1, word2, distance);

   return 0;
}