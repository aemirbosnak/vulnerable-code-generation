//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int levenshtein_distance(char* s1, char* s2, int m, int n){
    int** distances = (int **)malloc((m+1) * sizeof(int*));
    for(int i=0; i<=m; i++){
        distances[i] = (int *)malloc((n+1) * sizeof(int));
    }
    for(int i=0;i<=m;i++){
        distances[i][0] = i;
    }
    for(int i=0;i<=n;i++){
        distances[0][i] = i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                distances[i][j] = min(distances[i-1][j]+1, distances[i][j-1]+1, distances[i-1][j-1]);
            }
            else{
                distances[i][j] = min(distances[i-1][j]+1, distances[i][j-1]+1, distances[i-1][j-1]+1);
            }
        }
    }
    return distances[m][n];
}

int main(){
    char s1[100], s2[100];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);
    int distance = levenshtein_distance(s1, s2, m, n);
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, distance);
    return 0;
}