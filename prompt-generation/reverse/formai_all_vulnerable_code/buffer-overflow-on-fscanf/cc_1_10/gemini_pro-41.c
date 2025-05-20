//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of attributes and instances in the dataset
#define MAX_ATTRIBUTES 10
#define MAX_INSTANCES 100

// Define the data structure to represent an attribute
typedef struct {
    char name[50];
    int type; // 0 for numeric, 1 for categorical
    int num_values; // number of possible values for categorical attributes
    char values[MAX_ATTRIBUTES][50]; // possible values for categorical attributes
} Attribute;

// Define the data structure to represent an instance
typedef struct {
    double values[MAX_ATTRIBUTES]; // values of the attributes for this instance
} Instance;

// Define the data structure to represent a dataset
typedef struct {
    Attribute attributes[MAX_ATTRIBUTES];
    Instance instances[MAX_INSTANCES];
    int num_attributes;
    int num_instances;
} Dataset;

// Function to read a dataset from a file
Dataset* read_dataset(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the number of attributes and instances
    int num_attributes, num_instances;
    fscanf(file, "%d %d\n", &num_attributes, &num_instances);

    // Create a new dataset
    Dataset* dataset = (Dataset*) malloc(sizeof(Dataset));
    dataset->num_attributes = num_attributes;
    dataset->num_instances = num_instances;

    // Read the attributes
    for (int i = 0; i < num_attributes; i++) {
        fscanf(file, "%s %d", dataset->attributes[i].name, &dataset->attributes[i].type);
        if (dataset->attributes[i].type == 1) {
            fscanf(file, "%d", &dataset->attributes[i].num_values);
            for (int j = 0; j < dataset->attributes[i].num_values; j++) {
                fscanf(file, "%s", dataset->attributes[i].values[j]);
            }
        }
    }

    // Read the instances
    for (int i = 0; i < num_instances; i++) {
        for (int j = 0; j < num_attributes; j++) {
            fscanf(file, "%lf", &dataset->instances[i].values[j]);
        }
    }

    // Close the file
    fclose(file);

    return dataset;
}

// Function to write a dataset to a file
void write_dataset(Dataset* dataset, char* filename) {
    // Open the file
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write the number of attributes and instances
    fprintf(file, "%d %d\n", dataset->num_attributes, dataset->num_instances);

    // Write the attributes
    for (int i = 0; i < dataset->num_attributes; i++) {
        fprintf(file, "%s %d", dataset->attributes[i].name, dataset->attributes[i].type);
        if (dataset->attributes[i].type == 1) {
            fprintf(file, " %d", dataset->attributes[i].num_values);
            for (int j = 0; j < dataset->attributes[i].num_values; j++) {
                fprintf(file, " %s", dataset->attributes[i].values[j]);
            }
        }
        fprintf(file, "\n");
    }

    // Write the instances
    for (int i = 0; i < dataset->num_instances; i++) {
        for (int j = 0; j < dataset->num_attributes; j++) {
            fprintf(file, "%.2f ", dataset->instances[i].values[j]);
        }
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);
}

// Function to print a dataset
void print_dataset(Dataset* dataset) {
    // Print the number of attributes and instances
    printf("Number of attributes: %d\n", dataset->num_attributes);
    printf("Number of instances: %d\n", dataset->num_instances);

    // Print the attributes
    printf("Attributes:\n");
    for (int i = 0; i < dataset->num_attributes; i++) {
        printf("%s ", dataset->attributes[i].name);
        if (dataset->attributes[i].type == 0) {
            printf("(numeric)");
        } else {
            printf("(categorical)");
            printf(" Values: ");
            for (int j = 0; j < dataset->attributes[i].num_values; j++) {
                printf("%s ", dataset->attributes[i].values[j]);
            }
        }
        printf("\n");
    }

    // Print the instances
    printf("Instances:\n");
    for (int i = 0; i < dataset->num_instances; i++) {
        for (int j = 0; j < dataset->num_attributes; j++) {
            printf("%.2f ", dataset->instances[i].values[j]);
        }
        printf("\n");
    }
}

// Function to main
int main() {
    // Read the dataset from a file
    Dataset* dataset = read_dataset("data.txt");

    // Print the dataset
    print_dataset(dataset);

    // Write the dataset to a file
    write_dataset(dataset, "data_out.txt");

    // Free the memory allocated for the dataset
    free(dataset);

    return 0;
}