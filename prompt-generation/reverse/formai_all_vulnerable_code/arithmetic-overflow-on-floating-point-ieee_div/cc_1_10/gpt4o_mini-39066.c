//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance;
    struct Resistor* next;
} Resistor;

// Function to create a new resistor
Resistor* createResistor(float resistance) {
    Resistor* newResistor = (Resistor*)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = NULL;
    return newResistor;
}

// Function to add a resistor to the end of the linked list
void addResistor(Resistor** head, float resistance) {
    Resistor* newResistor = createResistor(resistance);
    if (*head == NULL) {
        *head = newResistor;
    } else {
        Resistor* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newResistor;
    }
}

// Function to calculate total resistance in series
float totalResistanceSeries(Resistor* head) {
    float total = 0.0;
    Resistor* temp = head;
    while (temp != NULL) {
        total += temp->resistance;
        temp = temp->next;
    }
    return total;
}

// Function to calculate total resistance in parallel
float totalResistanceParallel(Resistor* head) {
    float total = 0.0;
    Resistor* temp = head;
    while (temp != NULL) {
        total += 1.0 / temp->resistance;
        temp = temp->next;
    }
    return 1.0 / total;
}

// Function to free the resistor linked list
void freeResistors(Resistor* head) {
    Resistor* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Resistor* seriesResistors = NULL;
    Resistor* parallelResistors = NULL;
    int choice;
    float resistance;

    printf("Circuit Simulator\n");
    printf("1. Add Resistor to Series\n");
    printf("2. Add Resistor to Parallel\n");
    printf("3. Calculate Total Resistance\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter resistance of the resistor in ohms: ");
                scanf("%f", &resistance);
                addResistor(&seriesResistors, resistance);
                printf("Resistor added to series.\n");
                break;
            case 2:
                printf("Enter resistance of the resistor in ohms: ");
                scanf("%f", &resistance);
                addResistor(&parallelResistors, resistance);
                printf("Resistor added to parallel.\n");
                break;
            case 3:
                printf("Total Resistance in Series: %.2f ohms\n", totalResistanceSeries(seriesResistors));
                printf("Total Resistance in Parallel: %.2f ohms\n", totalResistanceParallel(parallelResistors));
                break;
            case 4:
                freeResistors(seriesResistors);
                freeResistors(parallelResistors);
                printf("Exiting the simulator.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}