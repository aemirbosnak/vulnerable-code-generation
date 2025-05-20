//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 10

typedef struct {
    char type; // 'R' for resistor, 'S' for series, 'P' for parallel
    float value; // resistance value for resistors
    int count; // number of components in series or parallel
    int components[MAX_COMPONENTS]; // indexes of components in the circuit
} Component;

Component circuit[MAX_COMPONENTS];
int componentCount = 0;

float calculateResistance(int index) {
    if (circuit[index].type == 'R') {
        return circuit[index].value;
    } else if (circuit[index].type == 'S') {
        float total = 0;
        for (int i = 0; i < circuit[index].count; i++) {
            total += calculateResistance(circuit[index].components[i]);
        }
        return total;
    } else if (circuit[index].type == 'P') {
        float total = 0;
        for (int i = 0; i < circuit[index].count; i++) {
            total += 1 / calculateResistance(circuit[index].components[i]);
        }
        return 1 / total;
    }
    return 0;
}

void addResistor() {
    if (componentCount >= MAX_COMPONENTS) {
        printf("Maximum component limit reached!\n");
        return;
    }
    printf("Enter resistance value for Resistor (in Ohms): ");
    scanf("%f", &circuit[componentCount].value);
    circuit[componentCount].type = 'R';
    componentCount++;
    printf("Resistor added at index %d\n\n", componentCount - 1);
}

void addSeries() {
    if (componentCount >= MAX_COMPONENTS) {
        printf("Maximum component limit reached!\n");
        return;
    }
    int n;
    printf("Enter number of components in series: ");
    scanf("%d", &n);
    
    circuit[componentCount].type = 'S';
    circuit[componentCount].count = n;
    
    for (int i = 0; i < n; i++) {
        int index;
        printf("Enter index of component %d: ", i + 1);
        scanf("%d", &index);
        if (index < 0 || index >= componentCount) {
            printf("Invalid component index. Please try again.\n");
            i--; // repeat this iteration
        } else {
            circuit[componentCount].components[i] = index;
        }
    }
    
    componentCount++;
    printf("Series connection added at index %d\n\n", componentCount - 1);
}

void addParallel() {
    if (componentCount >= MAX_COMPONENTS) {
        printf("Maximum component limit reached!\n");
        return;
    }
    int n;
    printf("Enter number of components in parallel: ");
    scanf("%d", &n);
    
    circuit[componentCount].type = 'P';
    circuit[componentCount].count = n;
    
    for (int i = 0; i < n; i++) {
        int index;
        printf("Enter index of component %d: ", i + 1);
        scanf("%d", &index);
        if (index < 0 || index >= componentCount) {
            printf("Invalid component index. Please try again.\n");
            i--; // repeat this iteration
        } else {
            circuit[componentCount].components[i] = index;
        }
    }

    componentCount++;
    printf("Parallel connection added at index %d\n\n", componentCount - 1);
}

void showCircuit() {
    for (int i = 0; i < componentCount; i++) {
        if (circuit[i].type == 'R') {
            printf("Component %d: Resistor, Value: %.2f Ohms\n", i, circuit[i].value);
        } else if (circuit[i].type == 'S') {
            printf("Component %d: Series with %d components\n", i, circuit[i].count);
        } else if (circuit[i].type == 'P') {
            printf("Component %d: Parallel with %d components\n", i, circuit[i].count);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("Circuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Series Connection\n");
        printf("3. Add Parallel Connection\n");
        printf("4. Show Circuit\n");
        printf("5. Calculate Total Resistance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                addResistor();
                break;
            case 2: 
                addSeries();
                break;
            case 3: 
                addParallel();
                break;
            case 4: 
                showCircuit();
                break;
            case 5:
                {

                    int index;
                    printf("Enter index of the component to calculate resistance: ");
                    scanf("%d", &index);
                    if (index >= 0 && index < componentCount) {
                        float totalResistance = calculateResistance(index);
                        printf("Total Resistance for component %d: %.2f Ohms\n", index, totalResistance);
                    } else {
                        printf("Invalid component index.\n");
                    }
                }
                break;
            case 6:
                printf("Exiting the simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 6);
    return 0;
}