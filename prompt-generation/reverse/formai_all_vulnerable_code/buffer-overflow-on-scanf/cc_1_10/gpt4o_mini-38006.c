//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_RESISTORS 10

// Structure to hold the details of each resistor
typedef struct {
    double resistance; // resistance in ohms
    double voltage;    // voltage across the resistor
} Resistor;

// Structure to pass arguments to the thread function
typedef struct {
    Resistor *resistor;
    double current; // current in amperes
} ThreadArg;

// Thread function to compute voltage across the resistor
void *calculate_voltage(void *arg) {
    ThreadArg *threadArg = (ThreadArg *)arg;
    Resistor *resistor = threadArg->resistor;
    
    // V = I * R
    resistor->voltage = threadArg->current * resistor->resistance;
    pthread_exit(NULL);
}

// Function to create resistors and calculate their voltages
void simulate_circuit(double current, Resistor resistors[], int num_resistors) {
    pthread_t threads[MAX_RESISTORS];
    ThreadArg threadArgs[MAX_RESISTORS];
    
    // Creating threads for each resistor
    for (int i = 0; i < num_resistors; i++) {
        threadArgs[i].resistor = &resistors[i];
        threadArgs[i].current = current;
        pthread_create(&threads[i], NULL, calculate_voltage, (void *)&threadArgs[i]);
    }
    
    // Ensuring all threads complete
    for (int i = 0; i < num_resistors; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print results
    printf("Total Current: %.2f A\n", current);
    for (int i = 0; i < num_resistors; i++) {
        printf("Resistor %d: %.2f Ohms, Voltage: %.2f V\n", i + 1, resistors[i].resistance, resistors[i].voltage);
    }
}

int main() {
    Resistor resistors[MAX_RESISTORS];
    int num_resistors;

    printf("Enter the number of resistors (max %d): ", MAX_RESISTORS);
    scanf("%d", &num_resistors);
    
    if (num_resistors > MAX_RESISTORS) {
        printf("Exceeds maximum limit of %d resistors.\n", MAX_RESISTORS);
        return EXIT_FAILURE;
    }

    // Take resistance values as input
    for (int i = 0; i < num_resistors; i++) {
        printf("Enter resistance for resistor %d (Ohms): ", i + 1);
        scanf("%lf", &resistors[i].resistance);
        resistors[i].voltage = 0.0; // initialize voltage
    }

    double current;
    printf("Enter total current flowing through the circuit (Amperes): ");
    scanf("%lf", &current);

    // Simulate the circuit
    simulate_circuit(current, resistors, num_resistors);
    
    return EXIT_SUCCESS;
}