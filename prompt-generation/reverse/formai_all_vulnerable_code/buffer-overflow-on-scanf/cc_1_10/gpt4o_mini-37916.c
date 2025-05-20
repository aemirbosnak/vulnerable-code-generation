//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[100];
} Item;

void generateData(Item arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].id = i + 1;
        snprintf(arr[i].name, sizeof(arr[i].name), "Item_%d", i + 1);
    }
}

void displayData(Item arr[], int size) {
    printf("ID\tName\n");
    printf("--\t-----------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\n", arr[i].id, arr[i].name);
    }
}

int linearSearch(Item arr[], int size, int searchId) {
    for (int i = 0; i < size; i++) {
        if (arr[i].id == searchId) {
            return i; // Return the index of the found item
        }
    }
    return -1; // Return -1 if not found
}

int binarySearch(Item arr[], int size, int searchId) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid].id == searchId) {
            return mid; // Return the index of the found item
        } else if (arr[mid].id < searchId) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if not found
}

void sortItems(Item arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void userInterface() {
    Item items[MAX_SIZE];
    int numItems, choice, searchId, result;

    printf("Enter the number of items (up to %d): ", MAX_SIZE);
    scanf("%d", &numItems);
    
    if(numItems > MAX_SIZE || numItems <= 0) {
        printf("Invalid number of items. Exiting...\n");
        return;
    }

    generateData(items, numItems);
    sortItems(items, numItems);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Items\n");
        printf("2. Linear Search by ID\n");
        printf("3. Binary Search by ID\n");
        printf("4. Exit\n");
        
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayData(items, numItems);
                break;

            case 2:
                printf("Enter ID to search (Linear Search): ");
                scanf("%d", &searchId);
                result = linearSearch(items, numItems, searchId);
                if (result != -1) {
                    printf("Item found at index: %d\n", result);
                } else {
                    printf("Item not found!\n");
                }
                break;

            case 3:
                printf("Enter ID to search (Binary Search): ");
                scanf("%d", &searchId);
                result = binarySearch(items, numItems, searchId);
                if (result != -1) {
                    printf("Item found at index: %d\n", result);
                } else {
                    printf("Item not found!\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                return;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    userInterface();
    return 0;
}