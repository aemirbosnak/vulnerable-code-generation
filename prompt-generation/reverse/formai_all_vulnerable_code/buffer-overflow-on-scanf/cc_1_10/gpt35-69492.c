//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c) {
    if(a <= b && a <= c) {
        return a;
    }
    else if(b <= a && b <= c) {
        return b;
    }
    else {
        return c;
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int n1 = strlen(s1), n2 = strlen(s2);
    
    // Creating a matrix to store the distance values
    int matrix[n1+1][n2+1];
    
    // Filling up the matrix with initial values
    for(int i=0; i<=n1; i++) {
        matrix[i][0] = i;
    }
    for(int j=0; j<=n2; j++) {
        matrix[0][j] = j;
    }
    
    // Updating the matrix with distance values
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                int val_1 = matrix[i-1][j] + 1;
                int val_2 = matrix[i][j-1] + 1;
                int val_3 = matrix[i-1][j-1] + 1;
                matrix[i][j] = min(val_1, val_2, val_3);
            }
        }
    }
    
    return matrix[n1][n2];
}

int main() {
    char s1[100], s2[100];
    
    printf("Enter first string: ");
    scanf("%s", s1);
    
    printf("Enter second string: ");
    scanf("%s", s2);
    
    int distance = levenshtein_distance(s1, s2);
    
    printf("Levenshtein Distance between %s and %s is: %d\n", s1, s2, distance);
    
    return 0;
}