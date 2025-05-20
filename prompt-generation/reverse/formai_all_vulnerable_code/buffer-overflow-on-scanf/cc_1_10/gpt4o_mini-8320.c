//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    int steps;
    float calories;
    float exerciseTime; // in minutes
} ActivityLog;

ActivityLog logs[MAX_ENTRIES];
int logCount = 0;

// Function Prototypes
void addToLog();
void viewLog();
void setGoals();
void viewProgress();

int main() {
    int choice;

    do {
        printf("\n---- Fitness Tracker ----\n");
        printf("1. Add Activity Log\n");
        printf("2. View Activity Log\n");
        printf("3. Set Goals\n");
        printf("4. View Progress\n");
        printf("5. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addToLog();
                break;
            case 2:
                viewLog();
                break;
            case 3:
                setGoals();
                break;
            case 4:
                viewProgress();
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker! Keep moving!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addToLog() {
    if (logCount >= MAX_ENTRIES) {
        printf("Log capacity reached! Cannot add more entries.\n");
        return;
    }
    
    ActivityLog newLog;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newLog.date);
    printf("Enter number of steps: ");
    scanf("%d", &newLog.steps);
    printf("Enter calories burned: ");
    scanf("%f", &newLog.calories);
    printf("Enter time spent exercising (in minutes): ");
    scanf("%f", &newLog.exerciseTime);

    logs[logCount++] = newLog;
    printf("Activity log added for date: %s\n", newLog.date);
}

void viewLog() {
    printf("\n---- Activity Log ----\n");
    if (logCount == 0) {
        printf("No entries found!\n");
        return;
    }

    for (int i = 0; i < logCount; i++) {
        printf("Date: %s, Steps: %d, Calories: %.2f, Exercise Time: %.2f mins\n",
               logs[i].date, logs[i].steps, logs[i].calories, logs[i].exerciseTime);
    }
}

void setGoals() {
    static int stepGoal, calorieGoal, timeGoal;
    printf("Set your daily step goal: ");
    scanf("%d", &stepGoal);
    printf("Set your daily calorie goal: ");
    scanf("%d", &calorieGoal);
    printf("Set your daily exercise time goal (in minutes): ");
    scanf("%d", &timeGoal);
    
    printf("Goals set! Steps: %d, Calories: %d, Exercise Time: %d mins\n",
           stepGoal, calorieGoal, timeGoal);
}

void viewProgress() {
    static int stepGoal = 10000;
    static int calorieGoal = 500;
    static int timeGoal = 30;
    
    printf("\n---- Progress Report ----\n");
    
    int totalSteps = 0;
    float totalCalories = 0;
    float totalExerciseTime = 0;

    for (int i = 0; i < logCount; i++) {
        totalSteps += logs[i].steps;
        totalCalories += logs[i].calories;
        totalExerciseTime += logs[i].exerciseTime;
    }

    printf("Total Steps: %d/%d\n", totalSteps, stepGoal);
    printf("Total Calories: %.2f/%.2f\n", totalCalories, (float) calorieGoal);
    printf("Total Exercise Time: %.2f/%.2f mins\n", totalExerciseTime, (float) timeGoal);

    if (totalSteps >= stepGoal) {
        printf("Congratulations! You've met your step goal!\n");
    } else {
        printf("Keep striving for your step goal!\n");
    }

    if (totalCalories >= calorieGoal) {
        printf("Awesome! You've met your calorie goal!\n");
    } else {
        printf("You're doing great! Keep burning those calories!\n");
    }

    if (totalExerciseTime >= timeGoal) {
        printf("Fantastic! You've met your exercise time goal!\n");
    } else {
        printf("Don't give up! Every minute counts!\n");
    }
}