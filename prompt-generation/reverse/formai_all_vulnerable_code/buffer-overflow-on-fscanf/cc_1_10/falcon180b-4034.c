//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define structure for fitness data
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} FitnessData;

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi;
    bmi = weight / (height * height);
    return bmi;
}

// Function to display fitness data
void displayFitnessData(FitnessData data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Weight: %f\n", data.weight);
    printf("Height: %f\n", data.height);
    printf("BMI: %f\n", data.bmi);
}

// Function to read fitness data from file
FitnessData readFitnessData(char filename[50]) {
    FILE *fp;
    FitnessData data;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%s", data.name);
    fscanf(fp, "%d", &data.age);
    fscanf(fp, "%f", &data.weight);
    fscanf(fp, "%f", &data.height);
    data.bmi = calculateBMI(data.weight, data.height);

    fclose(fp);
    return data;
}

// Function to write fitness data to file
void writeFitnessData(char filename[50], FitnessData data) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(fp, "%s\n", data.name);
    fprintf(fp, "%d\n", data.age);
    fprintf(fp, "%f\n", data.weight);
    fprintf(fp, "%f\n", data.height);
    fprintf(fp, "%f\n", data.bmi);

    fclose(fp);
}

// Function to update fitness data
void updateFitnessData(FitnessData data) {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    data = readFitnessData(filename);

    printf("Enter new weight: ");
    scanf("%f", &data.weight);
    data.bmi = calculateBMI(data.weight, data.height);

    writeFitnessData(filename, data);
}

// Main function
int main() {
    FitnessData data;

    data = readFitnessData("fitness.txt");
    displayFitnessData(data);

    updateFitnessData(data);

    return 0;
}