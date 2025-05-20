//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for storing fitness data
typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
    int calories;
    time_t timestamp;
} FitnessData;

// Function for calculating BMI
float calculateBMI(float height, float weight) {
    float bmi = weight / (height * height);
    return bmi;
}

// Function for calculating calories burned based on steps
int calculateCalories(int steps) {
    int calories = steps * 5;
    return calories;
}

// Function for printing fitness data
void printFitnessData(FitnessData data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Height: %f\n", data.height);
    printf("Weight: %f\n", data.weight);
    printf("BMI: %f\n", data.bmi);
    printf("Steps: %d\n", data.steps);
    printf("Calories burned: %d\n", data.calories);
    printf("Timestamp: %s\n", ctime(&data.timestamp));
}

// Function for getting user input for fitness data
void getFitnessData(FitnessData* data) {
    printf("Enter your name: ");
    scanf("%s", data->name);

    printf("Enter your age: ");
    scanf("%d", &data->age);

    printf("Enter your height: ");
    scanf("%f", &data->height);

    printf("Enter your weight: ");
    scanf("%f", &data->weight);

    data->bmi = calculateBMI(data->height, data->weight);
    data->steps = 0;
    data->calories = 0;

    time_t now = time(NULL);
    data->timestamp = now;
}

// Function for updating fitness data with new steps and calories
void updateFitnessData(FitnessData* data, int steps) {
    data->steps += steps;
    data->calories = calculateCalories(data->steps);
}

// Main function
int main() {
    FitnessData data;
    getFitnessData(&data);

    int choice;
    do {
        printf("\n1. Update steps\n2. Print fitness data\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the number of steps: ");
                scanf("%d", &data.steps);
                updateFitnessData(&data, data.steps);
                break;
            case 2:
                printFitnessData(data);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}