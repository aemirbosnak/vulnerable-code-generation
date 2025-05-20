//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int main(){
    // Greetings for our user
    printf("Welcome to our greedy algorithm example program!\n");
    
    // Receive user input for array size
    int size;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    
    // Dynamically allocate memory for the array
    int *arr = (int*)malloc(size*sizeof(int));
    
    // Initialize array with user input
    printf("Please enter %d elements to initialize the array: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    
    // Sort array in ascending order
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Calculate the sum of all array elements
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    
    // Initialize variables for calculating the minimum and maximum values
    int min = arr[0];
    int max = arr[size-1];
    
    // Print array and its details
    printf("\nArray elements in ascending order: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sum of array elements: %d\n", sum);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    
    // Free memory and exit program
    free(arr);
    return 0;
}