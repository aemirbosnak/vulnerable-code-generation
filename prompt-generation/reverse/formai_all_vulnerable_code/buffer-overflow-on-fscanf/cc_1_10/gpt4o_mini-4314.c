//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int steps;
    float calories;
    char exercise[50];
} FitnessData;

void inputFitnessData(FitnessData *data);
void displayFitnessData(FitnessData data);
void saveDataToFile(FitnessData data);
void loadDataFromFile(FitnessData *data);
void displayMenu();

int main() {
    FitnessData data = {0, 0.0, ""};
    int choice;

    loadDataFromFile(&data);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputFitnessData(&data);
                break;
            case 2:
                displayFitnessData(data);
                break;
            case 3:
                saveDataToFile(data);
                break;
            case 4:
                loadDataFromFile(&data);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void inputFitnessData(FitnessData *data) {
    printf("Enter steps: ");
    scanf("%d", &data->steps);
    printf("Enter calories burned: ");
    scanf("%f", &data->calories);
    printf("Enter type of exercise: ");
    scanf(" %[^\n]", data->exercise); // Read string with spaces
}

void displayFitnessData(FitnessData data) {
    printf("\nFitness Data:\n");
    printf("Steps: %d\n", data.steps);
    printf("Calories burned: %.2f\n", data.calories);
    printf("Type of exercise: %s\n", data.exercise);
}

void saveDataToFile(FitnessData data) {
    FILE *file = fopen("fitness_data.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Steps: %d\n", data.steps);
    fprintf(file, "Calories burned: %.2f\n", data.calories);
    fprintf(file, "Type of exercise: %s\n", data.exercise);
    fclose(file);
    printf("Data saved to fitness_data.txt\n");
}

void loadDataFromFile(FitnessData *data) {
    FILE *file = fopen("fitness_data.txt", "r");
    if (!file) {
        printf("No saved data found. Starting fresh.\n");
        return;
    }
    fscanf(file, "Steps: %d\n", &data->steps);
    fscanf(file, "Calories burned: %f\n", &data->calories);
    fscanf(file, "Type of exercise: %[^\n]\n", data->exercise);
    fclose(file);
    printf("Data loaded from fitness_data.txt\n");
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Input Fitness Data\n");
    printf("2. Display Fitness Data\n");
    printf("3. Save Data to File\n");
    printf("4. Load Data from File\n");
    printf("5. Exit\n");
}