//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements to be read from the input file
#define MAX_INPUT_LENGTH 1000

// Struct to store data from each line of the input file
struct Data {
    int id;
    char name[50];
    int age;
    float weight;
};

// Function to read data from the input file and store it in the Data struct
void readData(struct Data *data, int *numElements) {
    // Open the input file
    FILE *inputFile = fopen("input.txt", "r");

    // Check if the file could be opened
    if (inputFile == NULL) {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    // Read each line of the input file and store it in the Data struct
    int i = 0;
    while (fscanf(inputFile, "%d %s %d %f", &(data[i].id), data[i].name, 
                  &(data[i].age), &(data[i].weight)) != EOF) {
        i++;
        if (i == MAX_INPUT_LENGTH) {
            printf("Error: Maximum number of elements exceeded\n");
            exit(1);
        }
    }

    // Close the input file
    fclose(inputFile);

    // Store the number of elements read from the file
    *numElements = i;
}

// Function to print the data stored in the Data struct
void printData(struct Data *data, int numElements) {
    printf("ID\tName\t\tAge\tWeight\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", data[i].id, data[i].name, 
               data[i].age, data[i].weight);
    }
}

int main() {
    // Declare a Data struct and the number of elements to be read from the input file
    struct Data data[MAX_INPUT_LENGTH];
    int numElements;

    // Read the data from the input file
    readData(data, &numElements);

    // Print the data
    printf("Data read from input file:\n");
    printData(data, numElements);

    return 0;
}