//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a person's details
typedef struct {
    int id;
    char name[100];
} Person;

// Function to perform binary search on an array of Person structures
int binary_search(Person persons[], int size, int id) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (persons[mid].id == id) {
            return mid; // Return the index of the found person
        }
        if (persons[mid].id < id) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // ID not found
}

// Function to compare two Persons for sorting
int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personA->id - personB->id; // Sort by ID
}

// Function to print the details of a person
void print_person(Person p) {
    printf("ID: %d, Name: %s\n", p.id, p.name);
}

// Main function to demonstrate the binary search algorithm
int main() {
    int n, i, idToSearch, searchResult;
    
    // Example: Input number of persons
    printf("Enter the number of persons: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for persons
    Person *persons = (Person *)malloc(n * sizeof(Person));
    
    // Input persons details
    for (i = 0; i < n; i++) {
        printf("Enter ID and Name for person %d: ", i + 1);
        scanf("%d %s", &persons[i].id, persons[i].name);
    }
    
    // Sort the persons array based on IDs
    qsort(persons, n, sizeof(Person), compare);
    
    // Display the sorted persons
    printf("\nSorted Persons by ID:\n");
    for (i = 0; i < n; i++) {
        print_person(persons[i]);
    }
    
    // Input ID to search
    printf("Enter ID to search: ");
    scanf("%d", &idToSearch);

    // Perform binary search using the sorted array
    searchResult = binary_search(persons, n, idToSearch);
    
    // Check the search result and print the outcome
    if (searchResult != -1) {
        printf("Person found: ");
        print_person(persons[searchResult]);
    } else {
        printf("Person with ID %d not found.\n", idToSearch);
    }
    
    // Free allocated memory
    free(persons);
    
    return 0;
}