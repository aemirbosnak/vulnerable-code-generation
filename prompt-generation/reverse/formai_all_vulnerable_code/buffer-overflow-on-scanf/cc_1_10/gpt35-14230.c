//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int x, int y, int z) {
   if(x < y && x < z) {
      return x;
   } 
   else if(y < x && y < z) {
      return y;
   } 
   else {
      return z;
   }
}

int levenshtein_distance(char *s1, char *s2) {
   int s1_length = strlen(s1);
   int s2_length = strlen(s2);
   int i, j, distance[s1_length + 1][s2_length + 1];
   for(i = 0; i <= s1_length; i++) {
      for(j = 0; j <= s2_length; j++) {
         if(i == 0) {
            distance[i][j] = j;
         } 
         else if(j == 0) {
            distance[i][j] = i;
         } 
         else if(s1[i - 1] == s2[j - 1]) {
            distance[i][j] = distance[i - 1][j - 1];
         } 
         else {
            distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]); 
         }
      }
   }
   return distance[s1_length][s2_length];
}

int main() {
   printf("Hi there!\n");
   printf("I am a cheerful program that will help you calculate the Levenshtein Distance between two strings.\n");
   char s1[20], s2[20];
   printf("Please enter the first string: ");
   scanf("%s", s1);
   printf("Please enter the second string: ");
   scanf("%s", s2);
   printf("The Levenshtein Distance between %s and %s is: %d\n", s1, s2, levenshtein_distance(s1, s2));
   printf("Thank you for using me! Have a great day!\n");
   return 0;
}