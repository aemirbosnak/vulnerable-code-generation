//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>

// Function to search for the given element in an array
int search(int *arr, int size, int element) {
    int i = 0;
    int j = size - 1;
    int count = 0;

    // Divide the array into two parts and search in the appropriate part
    while(i <= j) {
        int mid = (i + j) / 2;
        count++;

        if(arr[mid] == element) {
            printf("Element found after %d tries\n", count);
            return mid;
        }
        else if(arr[mid] > element) j = mid - 1;
        else i = mid + 1;
    }

    // If the element is not found
    printf("Element not found after %d tries\n", count);
    return -1;
}

// Function for multiplayer mode
void multiplayer(int *arr, int size) {
    int choice, element, i;

    while(1) {
        printf("\n---Multiplayer Mode---\n");
        printf("1. Enter element to search\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter element to search: ");
            scanf("%d", &element);

            // Search for the element in the array
            int index = search(arr, size, element);

            if(index != -1) {
                printf("\nCongratulations!! Player %d won the game.\n", index+1);
                return;
            }
        }
        else if(choice == 2) {
            return;
        }
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }
}

// Main function
int main() {
    int size, i;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter elements of the array:\n");
    for(i = 0; i < size; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    multiplayer(arr, size);

    return 0;
}