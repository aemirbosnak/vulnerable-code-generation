//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_ELEMENTS 100

//Defining the element types
#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3
#define VOLTAGE_SOURCE 4
#define CURRENT_SOURCE 5

//Defining the element structure
struct Element {
    int type; //Type of the element
    int n1, n2; //Nodes connected to the element
    double value; //Value of the element
};

//Function to read the circuit data
int read_circuit_data(struct Element circuit[]) {

    int num_elements, i;

    printf("Enter the number of circuit elements: ");
    scanf("%d", &num_elements);

    if (num_elements > MAX_ELEMENTS) {
        printf("Error: Too many circuit elements. Maximum allowed is %d\n", MAX_ELEMENTS);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_elements; i++) {
        printf("\nEnter element %d data\n", i+1);
        printf("Type: ");
        scanf("%d", &circuit[i].type);
        printf("Value: ");
        scanf("%lf", &circuit[i].value);
        printf("Connects nodes: ");
        scanf("%d %d", &circuit[i].n1, &circuit[i].n2);
    }

    return num_elements;
}

//Function to print the circuit data
void print_circuit_data(struct Element circuit[], int num_elements) {

    int i;

    printf("\nCircuit Data:\n");

    for (i = 0; i < num_elements; i++) {
        printf("Element %d:\nType: ", i+1);
        switch (circuit[i].type) {
            case RESISTOR:
                printf("Resistor\n");
                break;
            case CAPACITOR:
                printf("Capacitor\n");
                break;
            case INDUCTOR:
                printf("Inductor\n");
                break;
            case VOLTAGE_SOURCE:
                printf("Voltage Source\n");
                break;
            case CURRENT_SOURCE:
                printf("Current Source\n");
                break;
        }
        printf("Value: %lf\n", circuit[i].value);
        printf("Connected Nodes: %d %d\n", circuit[i].n1, circuit[i].n2);
    }
}

//Main function
int main() {
    int i;

    struct Element circuit[MAX_ELEMENTS];
    int num_elements = read_circuit_data(circuit);

    print_circuit_data(circuit, num_elements);

    return 0;
}