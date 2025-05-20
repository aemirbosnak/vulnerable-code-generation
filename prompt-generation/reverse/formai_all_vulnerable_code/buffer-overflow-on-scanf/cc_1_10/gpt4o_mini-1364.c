//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct {
    int id;
    char name[50];
} Element;

void initialize_elements(Element elements[], int count);
void print_elements(const Element elements[], int count);
int linear_search(const Element elements[], int count, int search_id);
int binary_search(const Element elements[], int count, int search_id);
void sort_elements(Element elements[], int count);

int main() {
    Element elements[MAX_ELEMENTS];
    int count, search_id, position;
    char choice;

    printf("Enter the number of elements (max %d): ", MAX_ELEMENTS);
    scanf("%d", &count);

    if(count < 1 || count > MAX_ELEMENTS) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_ELEMENTS);
        return 1;
    }

    initialize_elements(elements, count);
    printf("Original List of Elements:\n");
    print_elements(elements, count);

    printf("\nWould you like to search for an element? (y/n): ");
    scanf(" %c", &choice);
    
    while (choice == 'y' || choice == 'Y') {
        printf("Enter the ID you wish to search for: ");
        scanf("%d", &search_id);

        position = linear_search(elements, count, search_id);
        if (position != -1) {
            printf("Linear Search: Found element with ID %d at position %d.\n", search_id, position);
        } else {
            printf("Linear Search: Element with ID %d not found.\n", search_id);
        }

        sort_elements(elements, count);
        position = binary_search(elements, count, search_id);
        if (position != -1) {
            printf("Binary Search: Found element with ID %d at position %d.\n", search_id, position);
        } else {
            printf("Binary Search: Element with ID %d not found.\n", search_id);
        }

        printf("\nWould you like to search for another element? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Exiting the program. Thank you!\n");
    return 0;
}

void initialize_elements(Element elements[], int count) {
    for (int i = 0; i < count; i++) {
        elements[i].id = i + 1; // Assign ID starting from 1
        snprintf(elements[i].name, sizeof(elements[i].name), "Element_%d", elements[i].id);
    }
}

void print_elements(const Element elements[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", elements[i].id, elements[i].name);
    }
}

int linear_search(const Element elements[], int count, int search_id) {
    for (int i = 0; i < count; i++) {
        if (elements[i].id == search_id) {
            return i; // Return the position if found
        }
    }
    return -1; // Element not found
}

int binary_search(const Element elements[], int count, int search_id) {
    int left = 0, right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (elements[mid].id == search_id) {
            return mid; // Return the position if found
        }

        if (elements[mid].id < search_id) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

void sort_elements(Element elements[], int count) {
    // Simple bubble sort for demonstration purposes
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (elements[j].id > elements[j + 1].id) {
                Element temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}