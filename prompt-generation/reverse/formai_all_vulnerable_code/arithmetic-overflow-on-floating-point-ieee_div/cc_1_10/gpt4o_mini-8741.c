//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    double resistance; // Resistance in ohms
    struct Resistor* next; // Pointer to the next resistor
} Resistor;

// Function to create a new resistor
Resistor* create_resistor(double resistance) {
    Resistor* new_resistor = (Resistor*)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to calculate total resistance in series
double total_resistance_series(Resistor* head) {
    double total = 0.0;
    Resistor* current = head;
    while (current != NULL) {
        total += current->resistance;
        current = current->next;
    }
    return total;
}

// Function to calculate total resistance in parallel
double total_resistance_parallel(Resistor* head) {
    double total = 0.0;
    Resistor* current = head;
    while (current != NULL) {
        total += 1.0 / current->resistance;
        current = current->next;
    }
    return (total > 0) ? (1.0 / total) : 0; // Avoid division by zero
}

// Function to free the resistors linked list
void free_resistors(Resistor* head) {
    Resistor* current = head;
    Resistor* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    int choice;
    Resistor* head = NULL;
    Resistor* tail = NULL;
    double resistance_value;
    char more_resistors;

    printf("Welcome to the Circuit Simulator!\n");
    printf("Choose the configuration type:\n");
    printf("1. Series\n");
    printf("2. Parallel\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Input resistors
    do {
        printf("Enter the resistance value (in ohms): ");
        scanf("%lf", &resistance_value);
        
        Resistor* new_resistor = create_resistor(resistance_value);
        
        if (head == NULL) {
            head = new_resistor; // First resistor
            tail = new_resistor;
        } else {
            tail->next = new_resistor; // Link for the next resistor
            tail = new_resistor; // Move the tail
        }

        printf("Do you want to add another resistor? (y/n): ");
        scanf(" %c", &more_resistors);
    } while (more_resistors == 'y' || more_resistors == 'Y');

    // Calculate total resistance based on chosen configuration
    double total;
    if (choice == 1) {
        total = total_resistance_series(head);
        printf("Total Resistance in Series: %.2f Ohms\n", total);
    } else if (choice == 2) {
        total = total_resistance_parallel(head);
        printf("Total Resistance in Parallel: %.2f Ohms\n", total);
    } else {
        printf("Invalid choice!\n");
    }

    // Free the linked list
    free_resistors(head);
    printf("Thank you for using the Circuit Simulator!\n");
    return 0;
}