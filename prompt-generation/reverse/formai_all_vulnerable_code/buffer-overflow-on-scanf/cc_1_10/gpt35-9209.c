//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *word1, char *word2) {
    
    int m = strlen(word1);
    int n = strlen(word2);
 
    int array[m+1][n+1];
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            
            if (i == 0) {
                array[i][j] = j;
            }
            else if (j == 0) {
                array[i][j] = i;
            }
            else if (word1[i-1] == word2[j-1]) {
                array[i][j] = array[i-1][j-1];
            }
            else {
                array[i][j] = 1 + min(array[i][j-1], array[i-1][j], array[i-1][j-1]);
            }
        }
    }
 
    return array[m][n];
}

int main() {

    char word1[100], word2[100];
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);
    
    printf("Levenshtein Distance between '%s' and '%s' is %d\n", word1, word2, levenshtein_distance(word1,word2));
    
    return 0;
}