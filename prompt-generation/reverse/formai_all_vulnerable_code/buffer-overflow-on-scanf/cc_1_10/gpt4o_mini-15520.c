//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 5
#define SIZE_INCREMENT 5

typedef struct {
    char **data;
    int size;
    int capacity;
} StringArray;

// Function to initialize the StringArray
StringArray* create_string_array(int initial_capacity) {
    StringArray* arr = (StringArray*)malloc(sizeof(StringArray));
    arr->capacity = initial_capacity > 0 ? initial_capacity : DEFAULT_SIZE;
    arr->size = 0;
    arr->data = (char**)malloc(arr->capacity * sizeof(char*));
    return arr;
}

// Function to add a string to the StringArray
void add_string(StringArray* arr, const char* str) {
    if (arr->size >= arr->capacity) {
        arr->capacity += SIZE_INCREMENT;
        arr->data = (char**)realloc(arr->data, arr->capacity * sizeof(char*));
        if (arr->data == NULL) {
            printf("Memory allocation failed during reallocation!\n");
            exit(EXIT_FAILURE);
        }
    }
    arr->data[arr->size] = (char*)malloc((strlen(str) + 1) * sizeof(char));
    strcpy(arr->data[arr->size], str);
    arr->size++;
}

// Function to print all strings in the StringArray
void print_strings(StringArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d: %s\n", i, arr->data[i]);
    }
}

// Function to free the memory used by StringArray
void free_string_array(StringArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]); // Free each individual string
    }
    free(arr->data); // Free the array of pointers
    free(arr); // Free the StringArray structure
}

// Function to remove a string from StringArray
void remove_string(StringArray* arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds!\n");
        return;
    }
    free(arr->data[index]); // Free the string memory
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1]; // Shift elements to the left
    }
    arr->size--;
    arr->data[arr->size] = NULL; // Optional: nullify the last pointer
}

// Function to sort strings in ascending order
void sort_strings(StringArray* arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (strcmp(arr->data[j], arr->data[j + 1]) > 0) {
                // Swap pointers
                char* temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int main() {
    StringArray* myStrings = create_string_array(0);
    int choice;
    char buffer[100];

    do {
        printf("\nMenu:\n");
        printf("1. Add a string\n");
        printf("2. Print all strings\n");
        printf("3. Remove a string\n");
        printf("4. Sort strings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
                add_string(myStrings, buffer);
                break;
            case 2:
                print_strings(myStrings);
                break;
            case 3:
                printf("Enter index of the string to remove: ");
                int index;
                scanf("%d", &index);
                remove_string(myStrings, index);
                break;
            case 4:
                sort_strings(myStrings);
                printf("Strings sorted.\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    free_string_array(myStrings);
    return 0;
}