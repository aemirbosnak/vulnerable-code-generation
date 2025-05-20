//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ELEMENTS 100
#define MAX_CHARS 100

typedef struct {
    int node1, node2; // Nodes connected by element
    double value; // Value of the element
    char type; // Type of the element
} Element;

int num_elements; // Number of elements in the circuit
Element circuit[MAX_ELEMENTS]; // Array of circuit elements

double calculate_resistance(double value) {
    return value;
}

double calculate_capacitance(double value, double frequency) {
    return 1 / (2*M_PI*frequency*value);
}

double calculate_impedance(double resistance, double capacitance, double frequency) {
    return sqrt(pow(resistance, 2) + pow(1 / (2*M_PI*frequency*capacitance), 2));
}

void parse_line(char *line) {
    char type = toupper(line[0]); // Extract the element type
    int node1, node2; 
    double value;
    sscanf(line+1, "%d %d %lf", &node1, &node2, &value); // Extract the element details
    circuit[num_elements].node1 = node1;
    circuit[num_elements].node2 = node2;
    circuit[num_elements].type = type;
    circuit[num_elements].value = value;
    num_elements++;
}

void read_circuit(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_CHARS];
    if (!file) {
        printf("File not found!\n");
        exit(1);
    }
    while (fgets(line, MAX_CHARS, file)) {
        parse_line(line);
    }
    fclose(file);
}

void print_circuit() {
    int i;
    printf("CIRCUIT\n");
    for (i = 0; i < num_elements; i++) {
        printf("%c %d %d %.2lf\n", circuit[i].type, circuit[i].node1, circuit[i].node2, circuit[i].value);
    }
}

void simulate_circuit(double frequency) {
    int i;
    for (i = 0; i < num_elements; i++) {
        double impedance = 0.0;
        switch (circuit[i].type) {
            case 'R':
                impedance = calculate_resistance(circuit[i].value);
                break;
            case 'C':
                impedance = calculate_capacitance(circuit[i].value, frequency);
                break;
        }
        printf("%c %.2lf\n", circuit[i].type, impedance);
    }
}

int main() {

    read_circuit("circuit.txt");
    print_circuit();
    simulate_circuit(50.0);

    return 0;
}