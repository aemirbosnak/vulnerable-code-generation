//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Exercise {
    char name[50];
    int calories;
};

void displayMenu() {
    printf("\nWelcome to the Fitness Tracker!\n");
    printf("1. Add Exercise\n");
    printf("2. View Total Calories\n");
    printf("3. Exit\n");
}

int calculateTotalCalories(struct Exercise exercises[], int currIndex) {
    if (currIndex == 0) {
        return 0;
    } else {
        return exercises[currIndex-1].calories + calculateTotalCalories(exercises, currIndex-1);
    }
}

void addExercise(struct Exercise exercises[], int currIndex) {
    printf("Enter Exercise Name: ");
    scanf("%s", exercises[currIndex].name);
    printf("Enter Exercise Calories: ");
    scanf("%d", &exercises[currIndex].calories);
    printf("Exercise Added Successfully!\n");
}

int main() {
    int choice;
    int currIndex = 0;
    struct Exercise exercises[10];
    displayMenu();
    do {
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (currIndex == 10) {
                    printf("Limit Reached! Cannot Add More Exercises.\n");
                } else {
                    addExercise(exercises, currIndex);
                    currIndex++;
                }
                break;
            case 2:
                printf("Total Calories Burned: %d\n", calculateTotalCalories(exercises, currIndex));
                break;
            case 3:
                printf("Exiting the Program. Hope You Had a Good Workout!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 3);

    return 0;
}