//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure to hold the magic list of numbers
typedef struct MagicList {
    int *numbers;    // Pointer to dynamically allocated array
    int size;        // Current size of the list
    int capacity;    // Maximum capacity of the list
} MagicList;

// Function prototypes
MagicList* createMagicList(int capacity);
void addNumber(MagicList *list, int number);
void deleteNumber(MagicList *list, int index);
void displayNumbers(MagicList *list);
void freeMagicList(MagicList *list);

int main() {
    printf("🎉 Welcome to the Magic Number Manager! 🎉\n");

    int initialCapacity = 2;
    MagicList *list = createMagicList(initialCapacity);
    if (!list) {
        fprintf(stderr, "Failed to create magic list!\n");
        return EXIT_FAILURE;
    }

    int choice, number;

    do {
        printf("\nMenu:\n");
        printf("1. Add a number\n");
        printf("2. Delete a number\n");
        printf("3. Display all numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to add: ");
                scanf("%d", &number);
                addNumber(list, number);
                break;

            case 2:
                printf("Enter the index to delete: ");
                scanf("%d", &number);
                deleteNumber(list, number);
                break;

            case 3:
                displayNumbers(list);
                break;

            case 4:
                printf("Exiting the Magic Number Manager! Goodbye! 🌟\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeMagicList(list);
    return EXIT_SUCCESS;
}

// Function to create a magic list
MagicList* createMagicList(int capacity) {
    MagicList *list = (MagicList*) malloc(sizeof(MagicList));
    if (!list) {
        return NULL;
    }
    list->numbers = (int*) malloc(capacity * sizeof(int));
    if (!list->numbers) {
        free(list);
        return NULL;
    }
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Function to add a number to the magic list
void addNumber(MagicList *list, int number) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->numbers = (int*) realloc(list->numbers, list->capacity * sizeof(int));
        if (!list->numbers) {
            fprintf(stderr, "Failed to reallocate memory!\n");
            return;
        }
    }
    list->numbers[list->size] = number;
    list->size++;
    printf("✨ Number %d added! Current size: %d\n", number, list->size);
}

// Function to delete a number from the magic list by index
void deleteNumber(MagicList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("⚠️ Invalid index! Unable to delete.\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->numbers[i] = list->numbers[i + 1];
    }
    list->size--;
    printf("🔮 Number at index %d deleted! Current size: %d\n", index, list->size);
}

// Function to display all numbers in the magic list
void displayNumbers(MagicList *list) {
    if (list->size == 0) {
        printf("😢 The magic list is empty!\n");
        return;
    }
    printf("🌈 Current numbers in the magic list:\n");
    for (int i = 0; i < list->size; i++) {
        printf(" [%d]: %d\n", i, list->numbers[i]);
    }
}

// Function to free allocated memory for the magic list
void freeMagicList(MagicList *list) {
    free(list->numbers);
    free(list);
    printf("💨 All resources freed! See you next time!\n");
}