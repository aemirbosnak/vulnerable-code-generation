//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: curious
#include <stdio.h>
#include <string.h>

int levenshtein(char *a, char *b){
    int x = strlen(a);
    int y = strlen(b);

    if (x == 0) {
        return y;
    }

    if (y == 0) {
        return x;
    }

    int matrix[x+1][y+1];

    for (int i=0; i<=x; i++) {
        matrix[i][0] = i;
    }

    for (int j=0; j<=y; j++) {
        matrix[0][j] = j;
    }

    for (int i=1; i<=x; i++) {
        for (int j=1; j<=y; j++) {
            int cost;
            if (a[i-1] == b[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = minimum(matrix[i-1][j] + 1,
                                    matrix[i][j-1] + 1,
                                    matrix[i-1][j-1] + cost);
        }
    }

    return matrix[x][y];
}

int minimum(int a, int b, int c){
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }

    if (c < smallest) {
        smallest = c;
    }

    return smallest;
}


int main() {
    char a[100], b[100];
    printf("Enter first word: ");
    scanf("%s", &a);
    printf("Enter second word: ");
    scanf("%s", &b);

    printf("The Levenshtein distance between %s and %s is %d", a, b, levenshtein(a, b));    

    return 0;
}