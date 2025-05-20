//Falcon-180B DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>

#define MAX_SIZE 100

void read_data(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// Function to display the array elements
void display(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array in ascending order
void sort_array(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to search for an element in the array
int search(int arr[], int size, int element) {
    for(int i=0; i<size; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    read_data(arr, size);
    display(arr, size);
    sort_array(arr, size);
    printf("Enter the element to search for: ");
    int element = scanf("%d", &element);
    int index = search(arr, size, element);
    if(index == -1) {
        printf("Element not found.\n");
    }
    else {
        printf("Element found at index %d.\n", index);
    }
    return 0;
}