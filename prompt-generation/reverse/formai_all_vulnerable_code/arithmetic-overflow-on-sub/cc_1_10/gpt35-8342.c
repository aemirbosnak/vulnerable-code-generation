//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Global variables
int *arr;
int n;
int key;
bool found = false;

void* search(void* arg) {
    int start_index = *((int*) arg);
    int end_index = start_index + n/4;
    
    for(int i=start_index; i<end_index; i++){
        if(arr[i] == key){
            found = true;
            return NULL;
        }
    }
    return NULL;
}

int main() {
    // Taking input from user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocating memory to the array
    arr = (int*) malloc(sizeof(int) * n);

    // Populating the array with random values between 0-99
    srand(time(0));
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100;
    }

    // Displaying the unsorted array
    printf("\nUnsorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array (Bubble Sort)
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Displaying the sorted array
    printf("\nSorted Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Taking the search key as input
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);

    // Creating four threads for asynchronous searching
    pthread_t tid[4];
    int indices[4] = {0, n/4, n/2, 3*n/4};

    for(int i=0; i<4; i++){
        pthread_create(&tid[i], NULL, &search, &indices[i]);
    }

    // Waiting for the threads to finish
    for(int i=0; i<4; i++){
        pthread_join(tid[i], NULL);
    }

    // Displaying the search result
    if(found){
        printf("\n%d is present in the array.", key);
    }
    else{
        printf("\n%d is not present in the array.", key);
    }

    // Freeing the allocated memory
    free(arr);

    return 0;
}