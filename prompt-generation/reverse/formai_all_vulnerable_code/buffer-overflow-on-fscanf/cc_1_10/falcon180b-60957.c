//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 1000

// Data structure to hold data from input file
typedef struct {
    int id;
    char name[20];
    float value;
} Data;

// Function to read data from input file and store in array of Data structs
Data* readDataFromFile(char* filename) {
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening input file: %s\n", filename);
        exit(1);
    }

    Data* dataArray = malloc(MAX_DATA_SIZE * sizeof(Data));
    int numData = 0;

    while (fscanf(inputFile, "%d %s %f\n", &dataArray[numData].id, dataArray[numData].name, &dataArray[numData].value)!= EOF) {
        numData++;
    }

    fclose(inputFile);

    return dataArray;
}

// Function to sort data array by ID
void sortDataByID(Data* dataArray, int numData) {
    for (int i = 0; i < numData - 1; i++) {
        for (int j = i + 1; j < numData; j++) {
            if (dataArray[i].id > dataArray[j].id) {
                Data temp = dataArray[i];
                dataArray[i] = dataArray[j];
                dataArray[j] = temp;
            }
        }
    }
}

// Function to print data array to output file
void printDataToFile(Data* dataArray, int numData, char* filename) {
    FILE* outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        printf("Error opening output file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < numData; i++) {
        fprintf(outputFile, "%d %s %f\n", dataArray[i].id, dataArray[i].name, dataArray[i].value);
    }

    fclose(outputFile);
}

// Main function to read data, sort by ID, and print to output file
int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <num_data>\n", argv[0]);
        exit(1);
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];
    int numData = atoi(argv[3]);

    Data* dataArray = readDataFromFile(inputFile);
    sortDataByID(dataArray, numData);
    printDataToFile(dataArray, numData, outputFile);

    free(dataArray);

    return 0;
}