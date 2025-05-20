//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c){
    if(a < b){
        if(a < c)
            return a;
        else
            return c;
    }
    else{
        if(b < c)
            return b;
        else
            return c;
    }
}

int main(){
    char first[100], second[100];
    int m, n, i, j, LD[101][101];
    
    printf("Enter first string: ");
    scanf("%s", first);
    
    printf("Enter second string: ");
    scanf("%s", second);
    
    m = strlen(first);
    n = strlen(second);
    
    for(i=0; i<=m; i++)
        LD[i][0] = i;
    
    for(j=0; j<=n; j++)
        LD[0][j] = j;
    
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(first[i-1] == second[j-1])
                LD[i][j] = LD[i-1][j-1];
            else
                LD[i][j] = minimum(LD[i-1][j]+1, LD[i][j-1]+1, LD[i-1][j-1]+1);
        }
    }
    
    printf("Levenshtein Distance = %d", LD[m][n]);
    
    return 0;
}