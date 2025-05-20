//Falcon-180B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of elements that can be sorted
#define MAX_SIZE 100

// Define the structure of each element to be sorted
typedef struct {
    int id;
    char name[50];
    int age;
    float score;
} Person;

// Function to generate random data for each element
void generate_data(Person *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i].id = rand() % 1000;
        sprintf(arr[i].name, "Person %d", arr[i].id);
        arr[i].age = rand() % 100;
        arr[i].score = rand() % 100;
    }
}

// Function to display the current state of the array
void display_array(Person *arr, int size) {
    printf("Current state of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Score: %.2f\n", arr[i].id, arr[i].name, arr[i].age, arr[i].score);
    }
}

// Function to swap two elements in the array
void swap(Person *arr, int i, int j) {
    Person temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to perform bubble sort on the array
void bubble_sort(Person *arr, int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i].score < arr[i + 1].score) {
                swap(arr, i, i + 1);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    Person arr[MAX_SIZE];
    int size;

    // Ask the user for the size of the array
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Generate random data for the array
    generate_data(arr, size);

    // Display the current state of the array
    display_array(arr, size);

    // Perform bubble sort on the array
    bubble_sort(arr, size);

    // Display the sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Score: %.2f\n", arr[i].id, arr[i].name, arr[i].age, arr[i].score);
    }

    return 0;
}