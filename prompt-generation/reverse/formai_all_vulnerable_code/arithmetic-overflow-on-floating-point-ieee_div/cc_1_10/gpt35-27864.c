//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int R1, R2, R3, C1, C2;
} Circuit;

void read_circuit_parameters(Circuit *);
void calculate_cutoff_frequency(Circuit);
void display_results(double);
int ask_for_retry();

int main() {
    Circuit circuit;
    int retry = 1;
    printf("Welcome to the classical circuit simulator!\n\n");
    while (retry) {
        read_circuit_parameters(&circuit);
        calculate_cutoff_frequency(circuit);
        retry = ask_for_retry();
        printf("\n");
    }
    printf("Thank you for using the classical circuit simulator!\n");
    return 0;
}

void read_circuit_parameters(Circuit *circuit) {
    printf("Enter the values of resistors R1, R2 and R3 (in ohms):\n");
    scanf("%d %d %d", &circuit->R1, &circuit->R2, &circuit->R3);
    printf("Enter the values of capacitors C1 and C2 (in farads):\n");
    scanf("%d %d", &circuit->C1, &circuit->C2);
}

void calculate_cutoff_frequency(Circuit circuit) {
    double f_c = 1 / (2 * 3.14159 * ((circuit.R1 * circuit.R2 * circuit.R3) / ((circuit.R1 + circuit.R2) * (circuit.R2 + circuit.R3)) * ((circuit.C1 + circuit.C2) / (circuit.C1 * circuit.C2))));
    display_results(f_c);
}

void display_results(double f_c) {
    printf("The cutoff frequency of the circuit is %f Hz.\n", f_c);
}

int ask_for_retry() {
    char response;
    while (1) {
        printf("Would you like to calculate the cutoff frequency of another circuit? (y/n)\n");
        scanf(" %c", &response);
        if (response == 'y' || response == 'Y') {
            return 1;
        }
        else if (response == 'n' || response == 'N') {
            return 0;
        }
        else {
            printf("Invalid response. Please enter y or n.\n");
        }
    }
}