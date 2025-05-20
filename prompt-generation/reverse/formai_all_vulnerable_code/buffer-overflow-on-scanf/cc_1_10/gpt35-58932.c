//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include<stdio.h>

// Function to calculate average of a given array of numbers
float getAverage(int arr[], int size){
    int sum = 0;

    // Loop to add up all the numbers in the array
    for(int i=0; i<size; i++){
        sum += arr[i];
    }

    // Calculate and return the average
    return (float)sum/size;
}

// Function to print all even numbers in a given array of numbers
void printEvenNumbers(int arr[], int size){
    printf("Even numbers in the array: ");
    
    // Loop through the array and check if each number is even
    for(int i=0; i<size; i++){
        if(arr[i] % 2 == 0){
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the numbers in the array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    // Call function to calculate average of the array
    float avg = getAverage(arr, size);
    printf("Average of the numbers in the array: %f\n", avg);

    // Call function to print even numbers in the array
    printEvenNumbers(arr, size);

    return 0;
}