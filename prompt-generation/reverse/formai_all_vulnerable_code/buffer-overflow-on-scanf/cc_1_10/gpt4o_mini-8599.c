//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 10
#define MAX_NAME_LENGTH 30

// Function prototypes
void addFruit(char** fruits, int* count);
void displayFruits(char** fruits, int count);
void freeMemory(char** fruits, int count);

int main() {
    char** fruits = (char**)malloc(MAX_FRUITS * sizeof(char*));
    if (fruits == NULL) {
        printf("Oh no! Memory allocation failed! :(\n");
        return 1;
    }

    int count = 0;
    int choice;

    printf("🎉 Welcome to the Fruity Friends List! 🍎🍌🍍\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a fruit\n");
        printf("2. Display fruits\n");
        printf("3. Exit\n");
        
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFruit(fruits, &count);
                break;
            case 2:
                displayFruits(fruits, count);
                break;
            case 3:
                printf("Thank you for playing with fruity friends! 🌈\n");
                freeMemory(fruits, count);
                return 0;
            default:
                printf("Oops! Please choose a valid option.\n");
        }
    }
}

void addFruit(char** fruits, int* count) {
    if (*count < MAX_FRUITS) {
        fruits[*count] = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (fruits[*count] == NULL) {
            printf("Oh no! Memory allocation failed while adding a fruit! :(\n");
            return;
        }
        printf("Enter the name of the fruit: ");
        scanf("%s", fruits[*count]);
        printf("Yay! You added: %s 🍉\n", fruits[*count]);
        (*count)++;
    } else {
        printf("Oops! The fruity friends list is full! 😅\n");
    }
}

void displayFruits(char** fruits, int count) {
    if (count == 0) {
        printf("🥺 No fruits in the list yet! Add some fruity friends! 🍊\n");
    } else {
        printf("Here are your fruity friends:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, fruits[i]);
        }
    }
}

void freeMemory(char** fruits, int count) {
    for (int i = 0; i < count; i++) {
        free(fruits[i]);
    }
    free(fruits);
    printf("All fruity memories are freed! 🌻\n");
}