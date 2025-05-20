//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum limit for brushes
#define MAX_BRUSHES 10

// Structure to represent a Brush
typedef struct {
    char color[20];
    int strength;
} Brush;

// Function to create a new brush
Brush* createBrush(const char* color, int strength) {
    Brush* newBrush = (Brush*)malloc(sizeof(Brush));
    if (newBrush == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new brush.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newBrush->color, color, sizeof(newBrush->color) - 1);
    newBrush->color[sizeof(newBrush->color) - 1] = '\0'; // Ensure null termination
    newBrush->strength = strength;
    return newBrush;
}

// Function to free a brush
void freeBrush(Brush* brush) {
    free(brush);
}

// Function to display a brush
void displayBrush(const Brush* brush) {
    printf("Brush Color: %s, Strength: %d\n", brush->color, brush->strength);
}

// Function to add a brush to the array
void addBrush(Brush* brushes[], int* count) {
    if (*count >= MAX_BRUSHES) {
        printf("Cannot add more brushes! Maximum limit reached.\n");
        return;
    }

    char color[20];
    int strength = 0;

    printf("Enter brush color: ");
    scanf("%19s", color);
    printf("Enter brush strength (1-10): ");
    scanf("%d", &strength);

    if (strength < 1 || strength > 10) {
        printf("Invalid strength! Please enter a value between 1 and 10.\n");
        return;
    }

    brushes[*count] = createBrush(color, strength);
    (*count)++;
    printf("Brush added successfully!\n");
}

// Function to list all brushes
void listBrushes(Brush* brushes[], int count) {
    if (count == 0) {
        printf("No brushes to display.\n");
        return;
    }
    printf("Listing all brushes:\n");
    for (int i = 0; i < count; i++) {
        printf("Brush %d: ", i + 1);
        displayBrush(brushes[i]);
    }
}

// Function to free all brushes
void freeAllBrushes(Brush* brushes[], int count) {
    for (int i = 0; i < count; i++) {
        freeBrush(brushes[i]);
    }
}

int main() {
    Brush* brushes[MAX_BRUSHES];
    int count = 0;
    int choice;

    do {
        printf("\n--- Brush Management Menu ---\n");
        printf("1. Add a Brush\n");
        printf("2. List Brushes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBrush(brushes, &count);
                break;
            case 2:
                listBrushes(brushes, count);
                break;
            case 3:
                printf("Exiting the program. Freeing allocated memory.\n");
                freeAllBrushes(brushes, count);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}