//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

//This is an amazing program that sorts an integer array in ascending order using the bubble sort algorithm!

int main(){
    
    printf("Welcome to the Sorting Spectacular Program!\n");
    
    //Let's get the size of the array from the user
    
    int size, i, j;
    
    printf("Enter the size of the array that needs sorting: ");
    scanf("%d", &size);
    
    //Let's create the array
    
    int* arr = (int*) malloc(size * sizeof(int));
    
    printf("Enter the elements of the array: \n");
    
    //Let's get the elements of the array from the user
    
    for(i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    
    //Let's start the sorting process
    
    printf("The Sorting Begins!\n");
    
    //print the unsorted array
    
    printf("Unsorted Array: ");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    //Let's use the Bubble sort algorithm to sort the array
    
    int temp;
    
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                //swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    //print the sorted array
    
    printf("Sorted Array: ");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Sorting Spectacular Program has come to an end! Thank you for using our program. Have a nice day!\n");
    
    //free the dynamically allocated memory
    
    free(arr);
    
    return 0;
}