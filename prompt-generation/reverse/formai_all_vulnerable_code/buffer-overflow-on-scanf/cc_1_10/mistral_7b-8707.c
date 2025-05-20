//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

#define ARRAY_SIZE 10

void print_array(int arr[], int size) {
    int i;
    printf("\nArray elements: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int arr[], int size, int value) {
    int low = 0, high = size - 1, mid;
    bool found = false;

    while(!found && low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == value) {
            found = true;
        } else if(arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(!found) {
        return -1;
    } else {
        return mid;
    }
}

int main() {
    int arr[ARRAY_SIZE] = {0};
    int value, index, choice;
    char command[10];

    printf("Welcome to the Secure Binary Search Algorithm!\n");
    printf("This program searches for a specified value in a sorted array using binary search.\n");
    printf("To quit the program at any time, enter 'quit' as a command.\n");

    printf("\nEnter %d integer values to populate the array:\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr, ARRAY_SIZE);

    do {
        printf("\nEnter a value to search for or enter 'quit' to exit: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        value = strtol(command, NULL, 10);

        if(errno == ERANGE || errno == EINVAL) {
            printf("Invalid input. Please enter an integer value.\n");
        } else {
            index = binary_search(arr, ARRAY_SIZE, value);

            if(index == -1) {
                printf("Value not found in the array.\n");
            } else {
                printf("Value found at index %d.\n", index);
            }
        }

        printf("\nDo you want to search for another value? (1 - yes, 0 - no): ");
        scanf("%d", &choice);

    } while(choice);

    printf("\nThank you for using the Secure Binary Search Algorithm. Goodbye!\n");

    return 0;
}