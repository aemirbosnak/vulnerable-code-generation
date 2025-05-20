//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type; // 'R' for Resistor, 'V' for Voltage Source
    float value; // Resistance in Ohms or Voltage in Volts
} Component;

typedef struct {
    Component *components;
    int size;
    int capacity;
} Circuit;

// Function prototypes
Circuit* createCircuit(int capacity);
void addComponent(Circuit *circuit, char type, float value);
void freeCircuit(Circuit *circuit);
float calculateTotalResistance(Circuit *circuit);
void printCircuit(Circuit *circuit);
void saveCircuitToFile(Circuit *circuit, const char *filename);
void loadCircuitFromFile(Circuit *circuit, const char *filename);

int main() {
    Circuit *circuit = createCircuit(5);
    int choice = 0;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Voltage Source\n");
        printf("3. Calculate Total Resistance\n");
        printf("4. Print Circuit\n");
        printf("5. Save Circuit to File\n");
        printf("6. Load Circuit from File\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float resistance;
                printf("Enter resistance in Ohms: ");
                scanf("%f", &resistance);
                addComponent(circuit, 'R', resistance);
                break;
            }
            case 2: {
                float voltage;
                printf("Enter voltage in Volts: ");
                scanf("%f", &voltage);
                addComponent(circuit, 'V', voltage);
                break;
            }
            case 3: {
                float totalResistance = calculateTotalResistance(circuit);
                printf("Total Resistance in Series Circuit: %.2f Ohms\n", totalResistance);
                break;
            }
            case 4: {
                printCircuit(circuit);
                break;
            }
            case 5: {
                char filename[100];
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveCircuitToFile(circuit, filename);
                break;
            }
            case 6: {
                char filename[100];
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadCircuitFromFile(circuit, filename);
                break;
            }
            case 0:
                freeCircuit(circuit);
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

Circuit* createCircuit(int capacity) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->components = malloc(sizeof(Component) * capacity);
    circuit->size = 0;
    circuit->capacity = capacity;
    return circuit;
}

void addComponent(Circuit *circuit, char type, float value) {
    if (circuit->size >= circuit->capacity) {
        circuit->capacity *= 2;
        circuit->components = realloc(circuit->components, sizeof(Component) * circuit->capacity);
    }
    circuit->components[circuit->size].type = type;
    circuit->components[circuit->size].value = value;
    circuit->size++;
}

void freeCircuit(Circuit *circuit) {
    free(circuit->components);
    free(circuit);
}

float calculateTotalResistance(Circuit *circuit) {
    float totalResistance = 0.0;
    for (int i = 0; i < circuit->size; i++) {
        if (circuit->components[i].type == 'R') {
            totalResistance += circuit->components[i].value;
        }
    }
    return totalResistance;
}

void printCircuit(Circuit *circuit) {
    printf("Circuit Components:\n");
    for (int i = 0; i < circuit->size; i++) {
        if (circuit->components[i].type == 'R') {
            printf("Resistor: %.2f Ohms\n", circuit->components[i].value);
        } else if (circuit->components[i].type == 'V') {
            printf("Voltage Source: %.2f Volts\n", circuit->components[i].value);
        }
    }
}

void saveCircuitToFile(Circuit *circuit, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < circuit->size; i++) {
        fprintf(file, "%c %.2f\n", circuit->components[i].type, circuit->components[i].value);
    }
    fclose(file);
    printf("Circuit saved to %s\n", filename);
}

void loadCircuitFromFile(Circuit *circuit, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file for reading");
        return;
    }
    circuit->size = 0; // Reset size
    while (fscanf(file, " %c %f", &circuit->components[circuit->size].type, &circuit->components[circuit->size].value) == 2) {
        addComponent(circuit, circuit->components[circuit->size].type, circuit->components[circuit->size].value);
    }
    fclose(file);
    printf("Circuit loaded from %s\n", filename);
}