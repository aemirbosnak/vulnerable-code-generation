//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for multi-variable data
typedef struct {
    int id;
    char name[50];
    float value;
} Data;

// Function to initialize the data array
void initializeData(Data *dataArray, int size) {
    for (int i = 0; i < size; i++) {
        dataArray[i].id = i + 1;
        sprintf(dataArray[i].name, "DataItem_%d", dataArray[i].id);
        dataArray[i].value = (float)(rand() % 100) + ((float)(rand() % 100) / 100);
    }
}

// Function to display the data
void displayData(Data *dataArray, int size) {
    printf("ID\tName\t\tValue\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", dataArray[i].id, dataArray[i].name, dataArray[i].value);
    }
}

// Function to search for data by the name
int searchDataByName(Data *dataArray, int size, const char *nameToFind) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dataArray[i].name, nameToFind) == 0) {
            return i; // Return the index of found data
        }
    }
    return -1; // Not found
}

// Function to search for data by the value
int searchDataByValue(Data *dataArray, int size, float valueToFind) {
    for (int i = 0; i < size; i++) {
        if (dataArray[i].value == valueToFind) {
            return i; // Return the index of found data
        }
    }
    return -1; // Not found
}

// Main function
int main() {
    int dataSize = 10; // Size of the data array
    Data *dataArray = (Data *)malloc(dataSize * sizeof(Data)); // Allocate memory for data

    if (!dataArray) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Initialize and display the data
    initializeData(dataArray, dataSize);
    displayData(dataArray, dataSize);
    
    // Search by name
    char nameToSearch[50];
    printf("\nEnter the name to search: ");
    scanf("%s", nameToSearch);
    int resultByName = searchDataByName(dataArray, dataSize, nameToSearch);

    if (resultByName != -1) {
        printf("Found %s with ID %d and Value %.2f\n", 
                dataArray[resultByName].name, 
                dataArray[resultByName].id, 
                dataArray[resultByName].value);
    } else {
        printf("No data item found with the name %s\n", nameToSearch);
    }

    // Search by value
    float valueToSearch;
    printf("\nEnter the value to search: ");
    scanf("%f", &valueToSearch);
    int resultByValue = searchDataByValue(dataArray, dataSize, valueToSearch);

    if (resultByValue != -1) {
        printf("Found value %.2f with ID %d and name %s\n", 
                dataArray[resultByValue].value, 
                dataArray[resultByValue].id, 
                dataArray[resultByValue].name);
    } else {
        printf("No data item found with the value %.2f\n", valueToSearch);
    }

    // Free allocated memory
    free(dataArray);
    return EXIT_SUCCESS;
}