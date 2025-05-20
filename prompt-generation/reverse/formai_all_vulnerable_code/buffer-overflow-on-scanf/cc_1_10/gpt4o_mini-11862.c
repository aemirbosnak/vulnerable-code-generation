//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Component {
    char type[20]; // type of the component (Resistor, Capacitor, Inductor)
    float value;   // value of the component
    struct Component* next; // pointer to the next component in the list
} Component;

Component* head = NULL;

// Function to create a new component
Component* createComponent(char* type, float value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    if (!newComponent) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newComponent->type, type);
    newComponent->value = value;
    newComponent->next = NULL;
    return newComponent;
}

// Function to add a component to the circuit
void addComponent(char* type, float value) {
    Component* newComponent = createComponent(type, value);
    if (head == NULL) {
        head = newComponent;
    } else {
        Component* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newComponent;
    }
    printf("Added %s with value: %f\n", type, value);
}

// Function to calculate equivalent resistance
float calculateEquivalentResistance() {
    float totalResistance = 0.0;
    Component* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->type, "Resistor") == 0) {
            totalResistance += temp->value; // add resistance for series
        }
        temp = temp->next;
    }
    return totalResistance;
}

// Function to display all components in the circuit
void displayComponents() {
    if (head == NULL) {
        printf("Circuit is empty!\n");
        return;
    }
    Component* temp = head;
    printf("Current Circuit Components:\n");
    while (temp != NULL) {
        printf(" - %s: %f\n", temp->type, temp->value);
        temp = temp->next;
    }
}

// Function to free the allocated memory
void freeComponents() {
    Component* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;
    char type[20];
    float value;

    while (1) {
        printf("\nWelcome to the Circuit Simulator!\n");
        printf("1. Add Resistor\n2. Add Capacitor\n3. Add Inductor\n4. View Components\n5. Calculate Equivalent Resistance\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance value: ");
                scanf("%f", &value);
                addComponent("Resistor", value);
                break;
            case 2:
                printf("Enter capacitance value: ");
                scanf("%f", &value);
                addComponent("Capacitor", value);
                break;
            case 3:
                printf("Enter inductance value: ");
                scanf("%f", &value);
                addComponent("Inductor", value);
                break;
            case 4:
                displayComponents();
                break;
            case 5:
                printf("Equivalence Resistance: %f\n", calculateEquivalentResistance());
                break;
            case 6:
                freeComponents();
                printf("Exiting Simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}