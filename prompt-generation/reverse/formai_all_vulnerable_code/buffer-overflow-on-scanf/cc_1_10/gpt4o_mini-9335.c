//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 100

typedef struct {
    char name[20];
    float resistance; // in ohms
} Resistor;

typedef struct {
    float current; // in Amperes
    Resistor resistors[MAX_COMPONENTS];
    int resistor_count;
} Circuit;

// Function prototypes
void add_resistor(Circuit *circuit, const char *name, float resistance);
void calculate_voltage(const Circuit *circuit);
void display_circuit(const Circuit *circuit);

int main() {
    Circuit circuit = {0};
    int choice;
    
    printf("Welcome to the Classical Circuit Simulator!\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1. Add Resistor\n");
        printf("2. Set Current Source\n");
        printf("3. Calculate Voltage across Resistors\n");
        printf("4. Display Circuit\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[20];
                float resistance;
                printf("Enter the resistor name: ");
                scanf("%s", name);
                printf("Enter the resistance in ohms: ");
                if(scanf("%f", &resistance) != 1 || resistance <= 0) {
                    printf("Invalid resistance value. Please try again.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    break; // Exit the case
                }
                add_resistor(&circuit, name, resistance);
                break;
            }
            case 2: {
                printf("Enter the current in Amperes: ");
                float current;
                if(scanf("%f", &current) != 1 || current < 0) {
                    printf("Invalid current value. Please try again.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    break;
                }
                circuit.current = current;
                break;
            }
            case 3:
                calculate_voltage(&circuit);
                break;
            case 4:
                display_circuit(&circuit);
                break;
            case 5:
                printf("Exiting the simulator.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void add_resistor(Circuit *circuit, const char *name, float resistance) {
    if (circuit->resistor_count < MAX_COMPONENTS) {
        Resistor new_resistor;
        snprintf(new_resistor.name, sizeof(new_resistor.name), "%s", name);
        new_resistor.resistance = resistance;

        circuit->resistors[circuit->resistor_count++] = new_resistor;
        printf("Resistor '%s' added with resistance %.2f ohms.\n", name, resistance);
    } else {
        printf("Maximum number of resistors reached. Cannot add more.\n");
    }
}

void calculate_voltage(const Circuit *circuit) {
    if (circuit->resistor_count == 0) {
        printf("No resistors in circuit to calculate voltage.\n");
        return;
    }

    for (int i = 0; i < circuit->resistor_count; i++) {
        float voltage = circuit->current * circuit->resistors[i].resistance;
        printf("Voltage across resistor '%s': %.2f V\n", circuit->resistors[i].name, voltage);
    }
}

void display_circuit(const Circuit *circuit) {
    printf("\nCircuit Details:\n");
    printf("Current Source: %.2f A\n", circuit->current);
    for (int i = 0; i < circuit->resistor_count; i++) {
        printf("Resistor %d: Name: %s, Resistance: %.2f ohms\n", i + 1, circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
}