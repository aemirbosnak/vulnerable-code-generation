//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void handleError(int errorCode) {
    switch(errorCode) {
        case 1:
            printf("Error: Invalid input!\n");
            break;
        case 2:
            printf("Error: Out of memory!\n");
            break;
        default:
            printf("Unknown error has occurred!\n");
            break;
    }
}

int main() {
    int input;
    int *numberArray;

    printf("Enter the size of the number array: ");
    if(scanf("%d", &input) != 1) {
        handleError(1);
        exit(EXIT_FAILURE);
    }

    numberArray = (int*) malloc(input*sizeof(int));
    if(numberArray == NULL) {
        handleError(2);
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<input; i++) {
        printf("Enter a number: ");
        if(scanf("%d", &numberArray[i]) != 1) {
            handleError(1);
            exit(EXIT_FAILURE);
        }
    }

    printf("The input array is: ");
    for(int i=0; i<input; i++) {
        printf("%d ", numberArray[i]);
    }
    printf("\n");

    free(numberArray);
    return 0;
}