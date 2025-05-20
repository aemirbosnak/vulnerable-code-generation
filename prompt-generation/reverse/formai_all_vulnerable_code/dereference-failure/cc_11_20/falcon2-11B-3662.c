//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int i, j, k;
    int* fibo[MAX_SIZE];

    srand(time(NULL));

    for(i = 0; i < MAX_SIZE; i++) {
        fibo[i] = malloc(sizeof(int));
        fibo[i][0] = 0;
        fibo[i][1] = 1;
    }

    for(i = 2; i < MAX_SIZE; i++) {
        fibo[i][0] = fibo[i-1][1];
        fibo[i][1] = fibo[i-1][0] + fibo[i-1][1];
    }

    for(i = 2; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            if(i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i = 2; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            if(i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i = 2; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            if(i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i = 2; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            if(i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i = 2; i < MAX_SIZE; i++) {
        for(j = 0; j < MAX_SIZE; j++) {
            if(i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}