//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char owner[MAX_NAME_LENGTH];
    float weight; // in kilograms
    char destination[MAX_NAME_LENGTH];
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int count;
} BaggageHandler;

// Function prototypes
void addBaggage(BaggageHandler *handler);
void checkBaggage(BaggageHandler *handler);
void viewBaggage(const BaggageHandler *handler);
void unloadBaggage(BaggageHandler *handler);
void displayMenu();
void clearInputBuffer();

int main() {
    BaggageHandler handler = { .count = 0 };
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            choice = 0; // Invalid input; go to the loop start again
        }

        switch (choice) {
            case 1:
                addBaggage(&handler);
                break;
            case 2:
                checkBaggage(&handler);
                break;
            case 3:
                viewBaggage(&handler);
                break;
            case 4:
                unloadBaggage(&handler);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nAirport Baggage Handling System\n");
    printf("1. Add Baggage\n");
    printf("2. Check Baggage\n");
    printf("3. View All Baggage\n");
    printf("4. Unload Baggage\n");
    printf("5. Exit\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void addBaggage(BaggageHandler *handler) {
    if (handler->count >= MAX_BAGS) {
        printf("Cannot add more baggage. Maximum limit reached.\n");
        return;
    }

    Baggage newBaggage;

    printf("Enter Baggage ID: ");
    while (scanf("%d", &newBaggage.id) != 1) {
        clearInputBuffer();
        printf("Invalid input. Please enter a valid Baggage ID: ");
    }

    clearInputBuffer(); // Clear the input buffer before reading a string
    printf("Enter Owner Name: ");
    fgets(newBaggage.owner, MAX_NAME_LENGTH, stdin);
    newBaggage.owner[strcspn(newBaggage.owner, "\n")] = '\0'; // Remove newline

    printf("Enter Weight (kg): ");
    while (scanf("%f", &newBaggage.weight) != 1 || newBaggage.weight <= 0) {
        clearInputBuffer();
        printf("Invalid input. Please enter a valid Weight: ");
    }

    clearInputBuffer(); // Clear the input buffer before reading a string
    printf("Enter Destination: ");
    fgets(newBaggage.destination, MAX_NAME_LENGTH, stdin);
    newBaggage.destination[strcspn(newBaggage.destination, "\n")] = '\0';

    handler->bags[handler->count++] = newBaggage;
    printf("Baggage added successfully.\n");
}

void checkBaggage(BaggageHandler *handler) {
    int id, found = 0;
    printf("Enter Baggage ID to check: ");
    while (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid input. Please enter a valid Baggage ID: ");
    }

    for (int i = 0; i < handler->count; i++) {
        if (handler->bags[i].id == id) {
            printf("Baggage Found: ID: %d, Owner: %s, Weight: %.2f kg, Destination: %s\n",
                   handler->bags[i].id, handler->bags[i].owner,
                   handler->bags[i].weight, handler->bags[i].destination);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Baggage with ID %d not found.\n", id);
    }
}

void viewBaggage(const BaggageHandler *handler) {
    if (handler->count == 0) {
        printf("No baggage available to view.\n");
        return;
    }

    printf("\nList of Baggage:\n");
    for (int i = 0; i < handler->count; i++) {
        printf("ID: %d, Owner: %s, Weight: %.2f kg, Destination: %s\n",
               handler->bags[i].id, handler->bags[i].owner,
               handler->bags[i].weight, handler->bags[i].destination);
    }
}

void unloadBaggage(BaggageHandler *handler) {
    int id, found = 0;
    printf("Enter Baggage ID to unload: ");
    while (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("Invalid input. Please enter a valid Baggage ID: ");
    }

    for (int i = 0; i < handler->count; i++) {
        if (handler->bags[i].id == id) {
            found = 1;
            for (int j = i; j < handler->count - 1; j++) {
                handler->bags[j] = handler->bags[j + 1]; // Shift bags left
            }
            handler->count--;
            printf("Baggage ID %d unloaded successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Baggage with ID %d not found.\n", id);
    }
}