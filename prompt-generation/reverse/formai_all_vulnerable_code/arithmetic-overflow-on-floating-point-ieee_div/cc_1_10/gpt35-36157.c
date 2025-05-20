//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

//Defining global constants
#define MAX_CIRCUIT_ELEMENTS 20
#define MAX_FILENAME_LENGTH 30

//Defining Circuit Element struct containing resistance and current
struct CircuitElement {
    float resistance;
    float current;
};

int main() {
    //Defining variables
    int numElements = 0;
    char filename[MAX_FILENAME_LENGTH];
    FILE *fp;
    struct CircuitElement circuitElements[MAX_CIRCUIT_ELEMENTS];
    float totalResistance = 0, totalCurrent = 0;

    //Prompting user for input filename
    printf("Enter the input filename: ");
    scanf("%s", filename);

    //Opening file
    fp = fopen(filename, "r");

    //Checking if file exists
    if(fp == NULL) {
        printf("Error in opening the file. Please try again.\n");
        exit(0);
    }

    //Reading input from file and calculating total resistance and current
    while(!feof(fp) && numElements < MAX_CIRCUIT_ELEMENTS) {
        fscanf(fp, "%f", &circuitElements[numElements].resistance);
        circuitElements[numElements].current = 1/circuitElements[numElements].resistance;
        totalResistance += circuitElements[numElements].resistance;
        totalCurrent += circuitElements[numElements].current;
        numElements++;
    }

    //Closing the file
    fclose(fp);

    //Calculating total resistance and total current after the circuit is complete
    totalCurrent = 1/totalCurrent;
    totalResistance = totalResistance/numElements;

    //Printing the output
    printf("\nTotal resistance of the circuit: %f Ohms", totalResistance);
    printf("\nTotal current flowing through the circuit: %f Amps", totalCurrent);

    return 0;
}