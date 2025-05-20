//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\nCircuit Simulator\n");
    printf("1. Calculate total resistance in series\n");
    printf("2. Calculate total resistance in parallel\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

double calculateSeries(double resistors[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += resistors[i];
    }
    return total;
}

double calculateParallel(double resistors[], int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        if (resistors[i] != 0) {
            total += 1.0 / resistors[i];
        } else {
            printf("Warning: A resistor value cannot be zero in parallel calculation.\n");
        }
    }
    if (total > 0) {
        return 1.0 / total;
    } else {
        return 0; // Avoid division by zero, returns 0 if all resistors are zero or invalid.
    }
}

int main() {
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Exiting the simulator. Goodbye!\n");
            break;
        }

        printf("Enter the number of resistors: ");
        int count;
        scanf("%d", &count);

        if (count <= 0) {
            printf("Number of resistors must be greater than zero.\n");
            continue;
        }

        double *resistors = (double *)malloc(count * sizeof(double));
        if (resistors == NULL) {
            printf("Memory allocation failed. Exiting.. \n");
            return 1;
        }

        printf("Enter the resistor values (in Ohms):\n");
        for (int i = 0; i < count; i++) {
            printf("Resistor %d: ", i + 1);
            scanf("%lf", &resistors[i]);
        }

        double totalResistance;
        switch (choice) {
            case 1:
                totalResistance = calculateSeries(resistors, count);
                printf("Total resistance in series: %.2f Ohms\n", totalResistance);
                break;
            case 2:
                totalResistance = calculateParallel(resistors, count);
                printf("Total resistance in parallel: %.2f Ohms\n", totalResistance);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        free(resistors);
    }

    return 0;
}