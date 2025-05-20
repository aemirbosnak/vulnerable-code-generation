//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// function to calculate minimum of three numbers
int min(int a, int b, int c){
    int min_val = a;
    if(b<min_val){
        min_val = b;
    }
    if(c<min_val){
        min_val = c;
    }
    return min_val;
}

// function to calculate Levenshtein Distance
int levenshtein_distance(char* str_1, char* str_2, int m, int n){
    int i, j, cost;
    int matrix[m+1][n+1];

    // initializing matrix
    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++){
            if(i==0){
                matrix[i][j] = j;
            }
            else if(j==0){
                matrix[i][j] = i;
            }
            else if(str_1[i-1] == str_2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                cost = 1;
                matrix[i][j] = min(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
            }
        }
    }

    // returning final result
    return matrix[m][n];
}

int main(){
    char str_1[100], str_2[100];

    printf("Enter first string: ");
    scanf("%s", str_1);

    printf("Enter second string: ");
    scanf("%s", str_2);

    int m = strlen(str_1);
    int n = strlen(str_2);
    int result = levenshtein_distance(str_1, str_2, m, n);

    printf("Levenshtein Distance between %s and %s is %d", str_1, str_2, result);

    return 0;
}