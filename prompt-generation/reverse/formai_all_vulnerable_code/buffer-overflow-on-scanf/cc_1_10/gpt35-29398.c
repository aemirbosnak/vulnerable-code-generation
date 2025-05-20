//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void displayError(int errorCode){
    switch(errorCode){
        case 1:
            printf("Error code 1: Invalid input!\n");
            break;
        case 2:
            printf("Error code 2: Unable to open file!\n");
            break;
        case 3:
            printf("Error code 3: Memory allocation failed!\n");
            break;
        default:
            printf("Unknown error occurred!\n");
    }
}

int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if(age < 0 || age > 120){
        displayError(1);
        exit(EXIT_FAILURE);
    }

    FILE *filePointer;
    char *fileName = "sample.txt";
    filePointer = fopen(fileName, "r");
    if(filePointer == NULL){
        displayError(2);
        exit(EXIT_FAILURE);
    }

    int *arr = (int*) malloc(100 * sizeof(int));
    if(arr == NULL){
        displayError(3);
        exit(EXIT_FAILURE);
    }

    printf("No error found, program executed successfully!\n");

    //Some code

    free(arr);
    fclose(filePointer);
    return 0;
}