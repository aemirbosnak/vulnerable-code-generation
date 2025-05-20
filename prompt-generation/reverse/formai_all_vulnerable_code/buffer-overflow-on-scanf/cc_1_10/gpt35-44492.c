//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// function prototypes
void input(int**, int);
void calcAvg(int*, int);
void display(int*, int);

int main() {
    int size, *tempArr = NULL;
    bool flag = true; // for re-run the program

    while(flag) {
        printf("Enter the number of temperatures you want to enter: ");
        scanf("%d", &size);

        if(size <= 0) {
            printf("\nPlease enter a valid size!\n");
            continue;
        }

        input(&tempArr, size); // function call to take inputs
        calcAvg(tempArr, size); // function call to perform calculations
        display(tempArr, size); // function call to output the results

        // Freeing the memory
        free(tempArr);
        tempArr = NULL;

        // Asking user, if they want to run the program again 
        printf("\nDo you want to re-run the program (Y/N)? ");
        char option;
        scanf(" %c", &option);
        if(option == 'Y' || option == 'y')
            continue;
        else
            flag = false;
    } 

    return 0;
}

// function definitions

void input(int** arr, int size) {
    (*arr) = (int*) malloc(sizeof(int) * size);
    printf("Enter %d temperatures: ", size);
    for(int i=0; i<size; i++) {
        scanf("%d", (*arr)+i);
    }
}

void calcAvg(int* arr, int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += *(arr+i);
    }
    printf("\nAverage temperature is: %.2f\n", (float)sum/size);
}

void display(int* arr, int size) {
    printf("\nTemperatures Entered: ");
    for(int i=0; i<size; i++) {
        printf("%d ", *(arr+i));
    }
}