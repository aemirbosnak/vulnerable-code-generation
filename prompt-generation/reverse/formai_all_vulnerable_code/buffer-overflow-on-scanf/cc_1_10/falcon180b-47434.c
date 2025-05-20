//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements in the array
#define MAX_ELEMS 1000000

// Define the structure of each element in the array
typedef struct {
    int value;
    int index;
} Element;

// Define the array of elements
Element arr[MAX_ELEMS];

// Define the function to insert an element into the array
void insert(int value) {
    int i = 0;
    while (i < MAX_ELEMS && arr[i].value!= value) {
        i++;
    }
    if (i == MAX_ELEMS) {
        printf("Error: Maximum number of elements reached!\n");
        return;
    }
    arr[i].value = value;
    arr[i].index = i;
}

// Define the function to search for an element in the array
int search(int value) {
    int i = 0;
    while (i < MAX_ELEMS && arr[i].value!= value) {
        i++;
    }
    if (i == MAX_ELEMS) {
        printf("Error: Element not found!\n");
        return -1;
    }
    return arr[i].index;
}

// Define the main function
int main() {
    int choice, value;
    while (1) {
        printf("Enter 1 to insert an element\n");
        printf("Enter 2 to search for an element\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(value);
        }
        else if (choice == 2) {
            printf("Enter the value to search for: ");
            scanf("%d", &value);
            int index = search(value);
            if (index == -1) {
                printf("Element not found!\n");
            }
            else {
                printf("Element found at index %d!\n", index);
            }
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}