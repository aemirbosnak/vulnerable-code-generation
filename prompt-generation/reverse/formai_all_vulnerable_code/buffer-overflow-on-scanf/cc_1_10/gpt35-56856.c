//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

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

int levenshtein(char *word1, char* word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    int dp[len1+1][len2+1];
    
    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 || j==0){
                dp[i][j] = i+j;
            } else if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                );
            }
        }
    }
    
    return dp[len1][len2];
}

int main(){
    char word1[MAXLEN];
    char word2[MAXLEN];
    
    printf("Enter first word: ");
    scanf("%s", word1);
    
    printf("\nEnter second word: ");
    scanf("%s", word2);
    
    int distance = levenshtein(word1, word2);
    
    printf("\nLevenshtein Distance: %d\n", distance);
    
    return 0;
}