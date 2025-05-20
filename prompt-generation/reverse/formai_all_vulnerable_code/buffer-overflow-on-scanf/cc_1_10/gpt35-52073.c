//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>

struct FitnessData {
    int steps;
    float distance;
    float calories;
    int heartrate;
};

void initFitnessData(struct FitnessData *fdata) {
    fdata->steps = 0;
    fdata->distance = 0.0;
    fdata->calories = 0.0;
    fdata->heartrate = 0;
}

void updateFitnessData(struct FitnessData *fdata, int steps, float distance, float calories, int heartrate) {
    fdata->steps += steps;
    fdata->distance += distance;
    fdata->calories += calories;
    fdata->heartrate = heartrate;
}

void displayFitnessData(struct FitnessData fdata) {
    printf("Steps: %d\n", fdata.steps);
    printf("Distance: %.2f km\n", fdata.distance);
    printf("Calories: %.2f kcal\n", fdata.calories);
    printf("Heart rate: %d bpm\n", fdata.heartrate);
}

int main() {
    struct FitnessData fdata;
    int choice;
    int steps;
    float distance;
    float calories;
    int heartrate;

    initFitnessData(&fdata);

    do {
        printf("\nMENU\n");
        printf("1. Enter new fitness data\n");
        printf("2. Display current fitness data\n");
        printf("3. Reset fitness data\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                printf("Enter distance (km): ");
                scanf("%f", &distance);
                printf("Enter calories: ");
                scanf("%f", &calories);
                printf("Enter heart rate: ");
                scanf("%d", &heartrate);
                updateFitnessData(&fdata, steps, distance, calories, heartrate);
                break;
            case 2:
                displayFitnessData(fdata);
                break;
            case 3:
                initFitnessData(&fdata);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}