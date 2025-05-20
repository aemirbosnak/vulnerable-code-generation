//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clearScreen() {
    printf("\e[1;1H\e[2J");
}

void sleepFor(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main() {
    int limit;
    printf("Enter the number of terms: ");
    scanf("%d", &limit);
    printf("\n");

    long long int a   = 0;
    long long int b   = 1;
    long long int c   = 0;
    long long int arr[limit];

    for(int i = 0; i < limit; i++) {
        arr[i]  = a;
        c       = a + b;
        a       = b;
        b       = c;
    }

    clearScreen();

    for(int i = 0; i < limit; i++) {
        printf("Term %d : %lld\n", i+1, arr[i]);

        if(i == 0) {
            sleepFor(500);
        } else if(i < 10) {
            sleepFor(200);
        } else if(i < 20) {
            sleepFor(100);
        } else {
            sleepFor(50);
        }

        clearScreen();
    }

    return EXIT_SUCCESS;
}