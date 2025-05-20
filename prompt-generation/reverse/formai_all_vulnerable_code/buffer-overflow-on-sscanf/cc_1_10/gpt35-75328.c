//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 50
#define MAX_ARRAY_SIZE 100

void cleanUp(int** array, int size){
    for(int i = 0; i < size; i++){
        free(array[i]);
    }
    free(array);
}

int main(){
    int** array = calloc(MAX_ARRAY_SIZE, sizeof(int*));
    if(array == NULL){
        fprintf(stderr, "Error: Unable to allocate memory for array\n");
        exit(EXIT_FAILURE);
    }

    char input[MAX_INPUT_LENGTH];
    int numArrays = 0;
    int currentArraySize;
    int currentElement;

    printf("Enter number of arrays to generate: ");
    if(fgets(input, MAX_INPUT_LENGTH, stdin) == NULL){
        fprintf(stderr, "Error reading input: %s\n", strerror(errno));
        cleanUp(array, numArrays);
        exit(EXIT_FAILURE);
    }
    if(sscanf(input, "%d", &numArrays) != 1){
        fprintf(stderr, "Invalid input: must be integer\n");
        cleanUp(array, numArrays);
        exit(EXIT_FAILURE);
    }

    if(numArrays < 1 || numArrays > MAX_ARRAY_SIZE){
        fprintf(stderr, "Invalid input: number of arrays must be between 1 and %d\n", MAX_ARRAY_SIZE);
        cleanUp(array, numArrays);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < numArrays; i++){
        printf("Enter size of array %d: ", i+1);
        if(fgets(input, MAX_INPUT_LENGTH, stdin) == NULL){
            fprintf(stderr, "Error reading input: %s\n", strerror(errno));
            cleanUp(array, numArrays);
            exit(EXIT_FAILURE);
        }
        if(sscanf(input, "%d", &currentArraySize) != 1){
            fprintf(stderr, "Invalid input: must be integer\n");
            cleanUp(array, numArrays);
            exit(EXIT_FAILURE);
        }
        if(currentArraySize < 1){
            fprintf(stderr, "Invalid input: array size must be greater than 0\n");
            cleanUp(array, numArrays);
            exit(EXIT_FAILURE);
        }

        array[i] = calloc(currentArraySize, sizeof(int));
        if(array[i] == NULL){
            fprintf(stderr, "Error: Unable to allocate memory for array %d\n", i+1);
            cleanUp(array, numArrays);
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < currentArraySize; j++){
            printf("Enter element %d for array %d: ", j+1, i+1);
            if(fgets(input, MAX_INPUT_LENGTH, stdin) == NULL){
                fprintf(stderr, "Error reading input: %s\n", strerror(errno));
                cleanUp(array, numArrays);
                exit(EXIT_FAILURE);
            }
            if(sscanf(input, "%d", &currentElement) != 1){
                fprintf(stderr, "Invalid input: must be integer\n");
                cleanUp(array, numArrays);
                exit(EXIT_FAILURE);
            }
            array[i][j] = currentElement;
        }
    }

    printf("The arrays are:\n");
    for(int i = 0; i < numArrays; i++){
        printf("Array %d:", i+1);
        for(int j = 0; j < sizeof(array[i])/sizeof(int); j++){
            printf(" %d", array[i][j]);
        }
        printf("\n");
    }

    cleanUp(array, numArrays);
    return 0;
}