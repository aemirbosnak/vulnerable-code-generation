//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int)); //allocating memory for integer array 

    if(arr == NULL){
        printf("Memory allocation failed!");
        exit(0);
    }

    //populating the array
    for(int i=0; i<n; i++){
        *(arr+i) = i+1;
    }

    //displaying the array
    printf("The elements of array are: ");
    for(int i=0; i<n; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");

    //resizing the array
    int* temp = (int*) realloc(arr, 2*n * sizeof(int)); //doubling the size of array

    if(temp != NULL){ //realloc returns NULL if it fails
        arr = temp;

        //populating the rest of the array with even numbers
        for(int i=n; i<2*n; i++){
            *(arr+i) = 2*(i-n+1);
        }

        //displaying the resized array
        printf("The elements of resized array are: ");
        for(int i=0; i<2*n; i++){
            printf("%d ", *(arr+i));
        }
        printf("\n");

        free(arr); //releasing dynamic memory
    }
    else{
        printf("Memory reallocation failed!");
        free(arr); //releasing dynamic memory
        exit(0);
    }

    return 0;
}