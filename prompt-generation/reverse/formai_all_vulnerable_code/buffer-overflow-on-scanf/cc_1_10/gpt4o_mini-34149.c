//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our visionary data
typedef struct {
    int id;
    char name[50];
} Data;

void displayData(Data *data, int size) {
    printf("\n--- Data List ---\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s\n", data[i].id, data[i].name);
    }
    printf("-------------------\n");
}

// A linear search function to find a record by id
int linearSearch(Data *data, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (data[i].id == id) {
            return i; // Return the index where the id is found
        }
    }
    return -1; // Return -1 if not found
}

// A binary search function to find a record by id
int binarySearch(Data *data, int size, int id) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (data[mid].id == id) {
            return mid; // Return the index where the id is found
        }
        
        if (data[mid].id < id) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }
    
    return -1; // Return -1 if not found
}

// A function to sort data based on id for efficient binary search
void sortData(Data *data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j].id > data[j + 1].id) {
                // Swap data[j] and data[j + 1]
                Data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    // User input for number of records
    printf("Enter the number of records: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the data
    Data *data = (Data *)malloc(n * sizeof(Data));
    
    // Input data from the user
    for (int i = 0; i < n; i++) {
        printf("Enter ID for record %d: ", i + 1);
        scanf("%d", &data[i].id);
        printf("Enter Name for record %d: ", i + 1);
        scanf("%s", data[i].name);
    }

    // Display the entered data
    displayData(data, n);
    
    // Sort the data for binary search
    sortData(data, n);
    printf("Sorted Data:\n");
    displayData(data, n);

    int searchId;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);

    // Perform search using linear search
    int linearResult = linearSearch(data, n, searchId);
    if (linearResult != -1) {
        printf("Linear Search: Found ID %d at index %d (Name: %s)\n", data[linearResult].id, linearResult, data[linearResult].name);
    } else {
        printf("Linear Search: ID %d not found!\n", searchId);
    }

    // Perform search using binary search
    int binaryResult = binarySearch(data, n, searchId);
    if (binaryResult != -1) {
        printf("Binary Search: Found ID %d at index %d (Name: %s)\n", data[binaryResult].id, binaryResult, data[binaryResult].name);
    } else {
        printf("Binary Search: ID %d not found!\n", searchId);
    }
    
    // Free the dynamically allocated memory
    free(data);
    
    return 0;
}