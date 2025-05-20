//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance;
    struct Resistor *next;
} Resistor;

typedef enum {
    SERIES,
    PARALLEL
} CircuitType;

float calculateResistance(Resistor *head, CircuitType type);
void addResistor(Resistor **head, float resistance);
void freeResistors(Resistor *head);
void displayResistors(Resistor *head);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    Resistor *head = NULL;
    CircuitType type = SERIES;
    int option;
    float resistance;

    while (1) {
        printf("\n=== Circuit Simulator ===\n");
        printf("1. Add Resistor\n");
        printf("2. Set Circuit Type (0 for Series, 1 for Parallel)\n");
        printf("3. Calculate Total Resistance\n");
        printf("4. Display Resistors\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter resistance value (Ohms): ");
                scanf("%f", &resistance);
                addResistor(&head, resistance);
                break;
            case 2:
                printf("Set circuit type (0 for Series, 1 for Parallel): ");
                int t;
                scanf("%d", &t);
                type = (t == 0) ? SERIES : PARALLEL;
                break;
            case 3:
                if (head == NULL) {
                    printf("No resistors in the circuit.\n");
                } else {
                    float totalResistance = calculateResistance(head, type);
                    if (type == SERIES) {
                        printf("Total Resistance (Series): %.2f Ohms\n", totalResistance);
                    } else {
                        printf("Total Resistance (Parallel): %.2f Ohms\n", totalResistance);
                    }
                }
                break;
            case 4:
                displayResistors(head);
                break;
            case 5:
                freeResistors(head);
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
}

void addResistor(Resistor **head, float resistance) {
    Resistor *newResistor = (Resistor *)malloc(sizeof(Resistor));
    newResistor->resistance = resistance;
    newResistor->next = *head;
    *head = newResistor;
}

void freeResistors(Resistor *head) {
    if (head == NULL) return;
    freeResistors(head->next);
    free(head);
}

void displayResistors(Resistor *head) {
    if (head == NULL) {
        printf("No resistors in the circuit.\n");
        return;
    }
    printf("Resistor values (Ohms): ");
    while (head != NULL) {
        printf("%.2f ", head->resistance);
        head = head->next;
    }
    printf("\n");
}

float calculateResistance(Resistor *head, CircuitType type) {
    if (head == NULL) return 0.0;

    if (type == SERIES) {
        // In series, R_total = R1 + R2 + ... + Rn
        return head->resistance + calculateResistance(head->next, type);
    } else {
        // In parallel, R_total = 1 / (1/R1 + 1/R2 + ... + 1/Rn)
        float totalReciprocal = 0.0;
        while (head != NULL) {
            if (head->resistance != 0) {
                totalReciprocal += 1 / head->resistance;
            }
            head = head->next;
        }
        return (totalReciprocal == 0) ? 0 : 1 / totalReciprocal;
    }
}