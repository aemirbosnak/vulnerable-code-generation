//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the size of the array
#define SIZE 100

// Define the structure of the elements in the array
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Function to print the elements in the array
void printArray(Person arr[], int n) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", arr[i].id, arr[i].name, arr[i].age);
    }
}

// Function to search for an element in the array
int search(Person arr[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    // Initialize the array
    Person arr[SIZE];
    int n = 0;

    // Read the elements from a file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fscanf(fp, "%d %s %d", &arr[n].id, arr[n].name, &arr[n].age)!= EOF) {
        n++;
    }
    fclose(fp);

    // Print the array
    printArray(arr, n);

    // Search for an element in the array
    int idToSearch = 3;
    int index = search(arr, n, idToSearch);
    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    return 0;
}