//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>

// Function prototypes
void displayMenu();
void recordExercise(char exerciseName[], int reps, float weight);
void viewStats();
void resetStats();

// Global variables
int totalPushups = 0;
int totalSquats = 0;
float totalWeightLifted = 0.0;

int main() {
    int choice;
    char exerciseName[20];
    int reps;
    float weight;

    printf("Welcome to the C Fitness Tracker!\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the exercise: ");
                scanf("%s", exerciseName);
                printf("Enter the number of reps: ");
                scanf("%d", &reps);
                printf("Enter the weight lifted (in kg): ");
                scanf("%f", &weight);
                recordExercise(exerciseName, reps, weight);
                break;
            case 2:
                viewStats();
                break;
            case 3:
                resetStats();
                break;
            case 4:
                printf("Thank you for using the C Fitness Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nMAIN MENU\n");
    printf("1. Record exercise\n");
    printf("2. View statistics\n");
    printf("3. Reset statistics\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

void recordExercise(char exerciseName[], int reps, float weight) {
    if (strcmp(exerciseName, "Pushups") == 0) {
        totalPushups += reps;
        totalWeightLifted += weight;
    } else if (strcmp(exerciseName, "Squats") == 0) {
        totalSquats += reps;
        totalWeightLifted += weight;
    } else {
        printf("Exercise not supported. Please record Pushups or Squats only.\n");
    }
}

void viewStats() {
    printf("\nSTATISTICS\n");
    printf("Total Pushups: %d\n", totalPushups);
    printf("Total Squats: %d\n", totalSquats);
    printf("Total weight lifted: %.2f kg\n", totalWeightLifted);
}

void resetStats() {
    printf("Are you sure you want to reset your statistics? (Y/N): ");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        totalPushups = 0;
        totalSquats = 0;
        totalWeightLifted = 0.0;
        printf("Stats reset successfully!\n");
    } else {
        printf("Stats not reset.\n");
    }
}