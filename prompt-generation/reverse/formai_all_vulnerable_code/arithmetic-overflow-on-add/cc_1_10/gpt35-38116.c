//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibonacciSequenceVisualizer(int n){

    int i, j, temp, limit;
 
    printf("\nFibonacci Sequence up to %d : \n", n);

    limit = n + 1;

    int* array = (int*)malloc(limit * sizeof(int));

    memset(array, 0, limit * sizeof(int));

    array[0] = 0;
    array[1] = 1;

    for(i = 2; i <= limit; i++){

        array[i] = array[i - 1] + array[i - 2];
 
    }

    for(i = 0; i <= limit; i++){

        temp = array[i];

        for(j = 0; j < temp; j++){

            printf("O");

        }

        printf("\n");
 
    }
}

int main(){

    int n;

    printf("Enter an integer to generate the Fibonacci Sequence : ");

    scanf("%d", &n);

    fibonacciSequenceVisualizer(n);

    return 0;
}