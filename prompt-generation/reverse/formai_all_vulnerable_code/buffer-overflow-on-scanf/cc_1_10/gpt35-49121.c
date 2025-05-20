//FormAI DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    
    srand(time(NULL));
    
    int n = 10;
    int arr[n];
    
    printf("Shape shifting sorting program\n");
    printf("--------------------------------\n");
    printf("Please enter a number between 1 and 3:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Bubble Sort selected.\n");
            printf("Generating random array...\n");
            for(int i=0; i<n; i++) {
                arr[i] = rand()%100 + 1;
            }
            printf("Original array: ");
            printArray(arr, n);
            printf("Sorting array...\n");
            bubbleSort(arr, n);
            printf("Sorted array: ");
            printArray(arr, n);
            break;
        case 2:
            printf("Selection Sort selected.\n");
            printf("Generating random array...\n");
            for(int i=0; i<n; i++) {
                arr[i] = rand()%100 + 1;
            }
            printf("Original array: ");
            printArray(arr, n);
            printf("Sorting array...\n");
            selectionSort(arr, n);
            printf("Sorted array: ");
            printArray(arr, n);
            break;
        case 3:
            printf("Insertion Sort selected.\n");
            printf("Generating random array...\n");
            for(int i=0; i<n; i++) {
                arr[i] = rand()%100 + 1;
            }
            printf("Original array: ");
            printArray(arr, n);
            printf("Sorting array...\n");
            insertionSort(arr, n);
            printf("Sorted array: ");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice entered.\n");
            break;
    }
    
    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for(i=0; i<n-1; i++) {
        minIndex = i;
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, j, temp;
    for(i=1; i<n; i++) {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}