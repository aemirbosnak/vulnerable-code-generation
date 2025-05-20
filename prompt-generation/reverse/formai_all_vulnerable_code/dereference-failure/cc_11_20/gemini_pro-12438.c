//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N 1000000000
#define P 0.000000001
#define S 1
#define F 0

int main() {
    int i, j, k;
    double p, q;
    bool **a;
    
    a = (bool **)malloc(N * sizeof(bool *));
    for (i = 0; i < N; i++) {
        a[i] = (bool *)malloc(N * sizeof(bool));
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = false;
        }
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                if (a[i][j] && a[j][k]) {
                    a[i][k] = true;
                }
            }
        }
    }
    
    p = 0.0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (a[i][j]) {
                p += P;
            }
        }
    }
    
    q = 1.0 - p;
    
    printf("The probability of an alien invasion is %f.\n", p);
    printf("The probability of no alien invasion is %f.\n", q);
    
    return 0;
}