//Falcon-180B DATASET v1.0 Category: Sorting ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to store data
typedef struct {
    int data;
    char name[50];
} Person;

// Function to compare two Person structs
int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->data < personB->data) {
        return -1;
    } else if (personA->data > personB->data) {
        return 1;
    } else {
        return 0;
    }
}

// Function to sort an array of Person structs
void sort(Person *array, int size) {
    qsort(array, size, sizeof(Person), compare);
}

// Function to print an array of Person structs
void printArray(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d - %s\n", array[i].data, array[i].name);
    }
}

// Main function
int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    Person *array = (Person *)malloc(size * sizeof(Person));

    // Get data from the user and store it in the array
    for (int i = 0; i < size; i++) {
        printf("Enter the data for person %d: ", i + 1);
        scanf("%d", &array[i].data);

        printf("Enter the name for person %d: ", i + 1);
        scanf("%s", array[i].name);
    }

    // Sort the array
    sort(array, size);

    // Print the sorted array
    printf("\nSorted array:\n");
    printArray(array, size);

    // Free the memory allocated for the array
    free(array);

    return 0;
}