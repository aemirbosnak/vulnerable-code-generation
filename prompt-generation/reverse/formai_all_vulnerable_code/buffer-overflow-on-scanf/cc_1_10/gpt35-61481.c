//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to print the array
void printArray(int arr[], int size)
{
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");
}

//function for bubble sort
void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            //if previous number is greater, swap it with the current number
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                printf("oops! %d and %d swapped\n", arr[j], arr[j+1]);
            }
        }
        printf("Uh oh! Another pass complete.\n");
        printArray(arr, size);
    }
    printf("Hooray! Bubble sort complete!\n");
    printArray(arr, size);
}

//function for insertion sort
void insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        //while previous number is greater, move it ahead of the current number
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
            printf("%d moved ahead of %d \n", arr[j+1], key);
        }
        arr[j+1] = key;
        printf("yay! %d inserted at the correct position\n", key);
        printArray(arr, size);
    }
    printf("Hooray! Insertion sort complete!\n");
    printArray(arr, size);
}

//main program
int main()
{
    int size, choice, i;
    printf("Hello there! I am your sorting bot! Give me an array to sort\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements for the array: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Great! Now select which sorting technique you want me to use\n\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    switch(choice) {
        case 1:
            printf("Awesome! Let me use my bubble powers to sort this array\n\n");
            bubbleSort(arr, size);
            break;
        case 2:
            printf("Great! Let me use my insertion powers to sort this array\n\n");
            insertionSort(arr, size);
            break;
        default:
            printf("Oops! That's not a valid choice. Please try again later.\n");
            break;
    }
    printf("\nThank you for using my sorting services! See you soon!\n");
    return 0;
}