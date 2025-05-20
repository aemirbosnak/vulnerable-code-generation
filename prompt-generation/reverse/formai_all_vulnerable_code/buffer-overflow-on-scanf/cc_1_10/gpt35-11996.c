//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// function to find minimum between three numbers
int min(int a, int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

// function to calculate Levenshtein distance between two strings
int levenshteinDistance(char *str1, char *str2, int len1, int len2){
    int matrix[len1+1][len2+1];
    int i,j;

    // initializing the first row and column of the matrix
    for(i=0; i<=len1; i++){
        matrix[i][0] = i;
    }
    for(j=0; j<=len2; j++){
        matrix[0][j] = j;
    }

    // filling up the matrix using dynamic programming
    for(i=1; i<=len1; i++){
        for(j=1; j<=len2; j++){
            if(str1[i-1] == str2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                matrix[i][j] = 1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
            }
        }
    }

    // returning the final distance
    return matrix[len1][len2];
}

int main(){
    char str1[100], str2[100];
    int len1, len2;

    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    int distance = levenshteinDistance(str1, str2, len1, len2);

    printf("Levenshtein Distance between %s and %s is %d", str1, str2, distance);

    return 0;
}