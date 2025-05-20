//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of attributes and records
#define MAX_ATTRIBUTES 100
#define MAX_RECORDS 1000

// Define the data structure for a record
typedef struct {
    float attributes[MAX_ATTRIBUTES];
    int label;
} Record;

// Define the data structure for a data set
typedef struct {
    Record records[MAX_RECORDS];
    int numAttributes;
    int numRecords;
} DataSet;

// Load a data set from a file
DataSet* loadDataSet(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the number of attributes and records
    int numAttributes, numRecords;
    fscanf(file, "%d %d", &numAttributes, &numRecords);

    // Allocate memory for the data set
    DataSet* dataSet = (DataSet*)malloc(sizeof(DataSet));
    dataSet->numAttributes = numAttributes;
    dataSet->numRecords = numRecords;

    // Read the records
    for (int i = 0; i < numRecords; i++) {
        // Read the attributes
        for (int j = 0; j < numAttributes; j++) {
            fscanf(file, "%f", &dataSet->records[i].attributes[j]);
        }

        // Read the label
        fscanf(file, "%d", &dataSet->records[i].label);
    }

    // Close the file
    fclose(file);

    // Return the data set
    return dataSet;
}

// Print a data set
void printDataSet(DataSet* dataSet) {
    // Print the number of attributes and records
    printf("Number of attributes: %d\n", dataSet->numAttributes);
    printf("Number of records: %d\n", dataSet->numRecords);

    // Print the records
    for (int i = 0; i < dataSet->numRecords; i++) {
        // Print the attributes
        for (int j = 0; j < dataSet->numAttributes; j++) {
            printf("%f ", dataSet->records[i].attributes[j]);
        }

        // Print the label
        printf("%d\n", dataSet->records[i].label);
    }
}

// Main function
int main() {
    // Load the data set
    DataSet* dataSet = loadDataSet("data.txt");

    // Print the data set
    printDataSet(dataSet);

    // Free the memory allocated for the data set
    free(dataSet);

    return 0;
}