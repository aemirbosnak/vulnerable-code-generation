//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void uniqueCpattern(int n) {
    int i, j, k;
    int pattern[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pattern[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                pattern[i][j] = 1;
            } else if (i == 0 && j == 1) {
                pattern[i][j] = 0;
            } else if (i == 0 && j == 2) {
                pattern[i][j] = 0;
            } else if (i == 1 && j == 0) {
                pattern[i][j] = 0;
            } else if (i == 1 && j == 1) {
                pattern[i][j] = 1;
            } else if (i == 1 && j == 2) {
                pattern[i][j] = 0;
            } else if (i == 2 && j == 0) {
                pattern[i][j] = 0;
            } else if (i == 2 && j == 1) {
                pattern[i][j] = 0;
            } else if (i == 2 && j == 2) {
                pattern[i][j] = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (pattern[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);
    uniqueCpattern(n);
    return 0;
}