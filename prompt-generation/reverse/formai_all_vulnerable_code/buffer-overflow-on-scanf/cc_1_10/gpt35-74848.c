//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int min(int a, int b, int c){
  int min = a;
  if(b < min){
    min = b;
  }
  if(c < min){
    min = c;
  }
  return min;
}

int levenshtein_distance(char *s1, char *s2){
  int len1 = strlen(s1);
  int len2 = strlen(s2);

  int matrix[len1+1][len2+1];

  for(int i = 0; i <= len1; i++){
    for(int j = 0; j <= len2; j++){
      if(i == 0){
        matrix[i][j] = j;
      }
      else if(j == 0){
        matrix[i][j] = i;
      }
      else{
        int cost = 0;
        if(tolower(s1[i-1]) != tolower(s2[j-1])){
          cost = 1;
        }
        matrix[i][j] = min(matrix[i-1][j] + 1, 
                      matrix[i][j-1] + 1, 
                      matrix[i-1][j-1] + cost);
      }
    }
  }

  return matrix[len1][len2];
}

int main(){
  char s1[100];
  char s2[100];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);

  int distance = levenshtein_distance(s1, s2);
  printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

  return 0;
}