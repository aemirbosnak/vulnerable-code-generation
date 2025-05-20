//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
    char name[100];
    int calories;
    int duration;
};

void printMenu() {
    printf("Welcome to the Shape Shifting Fitness Tracker!\n");
    printf("1. Log Exercise\n");
    printf("2. View Exercise Log\n");
    printf("3. View Total Calories Burned\n");
    printf("4. View Average Calories Burned per Exercise\n");
    printf("5. Exit\n");
}

int main() {
    struct Exercise exerciseLog[10];
    int logCounter = 0;
    int totalCalories = 0;
    int option = 0;
    char temp[100];

    while (option != 5) {
        printMenu();
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the name of the exercise: ");
                scanf("%s", temp);
                strcpy(exerciseLog[logCounter].name, temp);
                printf("Enter the number of calories burned: ");
                scanf("%d", &exerciseLog[logCounter].calories);
                printf("Enter the duration of the exercise (in minutes): ");
                scanf("%d", &exerciseLog[logCounter].duration);
                totalCalories += exerciseLog[logCounter].calories;
                logCounter++;
                break;
            case 2:
                printf("%-30s %-10s %-10s\n", "Exercise Name", "Calories", "Duration");
                for (int i = 0; i < logCounter; i++) {
                    printf("%-30s %-10d %-10d\n", exerciseLog[i].name, exerciseLog[i].calories, exerciseLog[i].duration);
                }
                break;
            case 3:
                printf("Total Calories Burned: %d\n", totalCalories);
                break;
            case 4:
                if (logCounter == 0) {
                    printf("No exercises logged.\n");
                } else {
                    float averageCalories = (float)totalCalories/logCounter;
                    printf("Average Calories Burned per Exercise: %.2f\n", averageCalories);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input. Please try again.\n");
                break;
        }
    }

    return 0;
}