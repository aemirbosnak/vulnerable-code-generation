//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a circuit component
typedef struct Component {
    char type;      // 'R' for Resistor, 'V' for Voltage Source
    float value;    // Resistance in ohms or Voltage in volts
    struct Component* next; // Pointer to the next component
} Component;

// Function to create a new component and return its pointer
Component* createComponent(char type, float value) {
    Component* newComponent = (Component*)malloc(sizeof(Component));
    newComponent->type = type;
    newComponent->value = value;
    newComponent->next = NULL;
    return newComponent;
}

// Function to add a component to the end of the circuit
void addComponent(Component** head, char type, float value) {
    Component* newComponent = createComponent(type, value);
    if (*head == NULL) {
        *head = newComponent;
    } else {
        Component* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newComponent;
    }
}

// Function to calculate total resistance for series connection
float totalResistance(Component* head) {
    float total = 0;
    while (head != NULL) {
        if (head->type == 'R') {
            total += head->value;
        }
        head = head->next;
    }
    return total;
}

// Function to calculate total current in the circuit
float totalCurrent(Component* head, float voltage) {
    float resistance = totalResistance(head);
    if (resistance == 0) {
        printf("Infinite current! Your circuit's a short circuit!!!\n");
        return -1;
    }
    return voltage / resistance;
}

// Function to display the circuit components
void displayCircuit(Component* head) {
    printf("Circuit Components:\n");
    while (head != NULL) {
        if (head->type == 'R') {
            printf("Resistor: %.2f Ohms\n", head->value);
        } else if (head->type == 'V') {
            printf("Voltage Source: %.2f Volts\n", head->value);
        }
        head = head->next;
    }
}

int main() {
    Component* circuit = NULL; 
    float voltage;

    // Shockingly! Let's build our circuit
    printf("Welcome to the Shock Circuit Simulator!\n");

    printf("Enter the voltage source (in Volts): ");
    scanf("%f", &voltage);
    addComponent(&circuit, 'V', voltage);

    int numResistors;
    printf("How many resistors do you want to add? ");
    scanf("%d", &numResistors);
    
    for (int i = 0; i < numResistors; i++) {
        float resistance;
        printf("Enter resistance for Resistor %d (in Ohms): ", i + 1);
        scanf("%f", &resistance);
        addComponent(&circuit, 'R', resistance);
    }

    // Display circuit components
    displayCircuit(circuit);

    // Calculate total resistance and current
    float resistance = totalResistance(circuit);
    float current = totalCurrent(circuit, voltage);

    if (current != -1) {
        printf("\nTotal Resistance: %.2f Ohms\n", resistance);
        printf("Total Current flowing through the circuit: %.2f Amperes\n", current);
    }

    // Cleanup resources
    Component* temp;
    while (circuit != NULL) {
        temp = circuit;
        circuit = circuit->next;
        free(temp);
    }

    printf("Circuit simulation complete! Stay shocked!\n");
    return 0;
}