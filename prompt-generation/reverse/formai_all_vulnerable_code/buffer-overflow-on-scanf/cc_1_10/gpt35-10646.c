//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c);

int main(){
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2, i , j;

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    int matrix[len1+1][len2+1];

    for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++){
            if(i == 0){
                matrix[i][j] = j;
            }
            else if(j == 0){
                matrix[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                matrix[i][j] = 1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
            }
        }
    }

    printf("\nThe Levenshtein Distance between '%s' and '%s' is %d\n", str1, str2, matrix[len1][len2]);

    return 0;
}

int min(int a, int b, int c){
    if(a <= b && a <= c){
        return a;
    }
    else if(b <= a && b <= c){
        return b;
    }
    else{
        return c;
    }
}