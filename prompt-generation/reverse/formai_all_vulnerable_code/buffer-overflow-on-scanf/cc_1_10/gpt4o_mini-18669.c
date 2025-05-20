//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    double resistance; // Resistance in Ohms
    struct Resistor *next; // Pointer to the next resistor
} Resistor;

// Function to create a new resistor
Resistor* create_resistor(double resistance) {
    Resistor *new_resistor = (Resistor *)malloc(sizeof(Resistor));
    new_resistor->resistance = resistance;
    new_resistor->next = NULL;
    return new_resistor;
}

// Function to add a resistor to the end of the list
void add_resistor(Resistor **head, double resistance) {
    Resistor *new_resistor = create_resistor(resistance);
    if (*head == NULL) {
        *head = new_resistor;
    } else {
        Resistor *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_resistor;
    }
}

// Function to calculate total resistance in series
double calculate_total_resistance(Resistor *head) {
    double total_resistance = 0.0;
    while (head != NULL) {
        total_resistance += head->resistance;
        head = head->next;
    }
    return total_resistance;
}

// Function to calculate current through the circuit using Ohm's law
double calculate_current(double voltage, double total_resistance) {
    return voltage / total_resistance;
}

// Function to free the resistor list
void free_resistors(Resistor *head) {
    Resistor *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to display resistors
void display_resistors(Resistor *head) {
    printf("Resistors in the circuit:\n");
    while (head != NULL) {
        printf("Resistance: %.2f Ohms\n", head->resistance);
        head = head->next;
    }
}

int main() {
    Resistor *circuit = NULL;
    double voltage, resistance, total_resistance, current;

    printf("Welcome to the Circuit Simulator!\n");

    // Input voltage of the circuit
    printf("Enter the voltage (in Volts): ");
    scanf("%lf", &voltage);

    // Adding resistors to the circuit
    char choice;
    do {
        printf("Enter resistance of resistor (in Ohms): ");
        scanf("%lf", &resistance);
        add_resistor(&circuit, resistance);
        
        printf("Do you want to add another resistor? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    // Displaying current resistors
    display_resistors(circuit);
    
    // Calculating total resistance
    total_resistance = calculate_total_resistance(circuit);
    printf("Total Resistance in the circuit: %.2f Ohms\n", total_resistance);

    // Calculating current
    current = calculate_current(voltage, total_resistance);
    printf("Current flowing through the circuit: %.2f Amperes\n", current);

    // Free the resistor list
    free_resistors(circuit);

    printf("Thank you for using the Circuit Simulator!\n");
    return 0;
}