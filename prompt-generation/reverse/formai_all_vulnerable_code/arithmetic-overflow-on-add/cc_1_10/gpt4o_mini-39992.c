//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS_IN_WEEK 7

typedef struct {
    int steps[DAYS_IN_WEEK];
    int calories[DAYS_IN_WEEK];
    float exercise_time[DAYS_IN_WEEK]; // in hours
} FitnessData;

void initialize_data(FitnessData *data) {
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        data->steps[i] = 0;
        data->calories[i] = 0;
        data->exercise_time[i] = 0.0;
    }
}

void record_activity(FitnessData *data, int day) {
    int steps, calories;
    float exercise_time;
    
    printf("Enter steps for day %d: ", day + 1);
    scanf("%d", &steps);
    printf("Enter calories burned for day %d: ", day + 1);
    scanf("%d", &calories);
    printf("Enter exercise time (in hours) for day %d: ", day + 1);
    scanf("%f", &exercise_time);
    
    data->steps[day] += steps;
    data->calories[day] += calories;
    data->exercise_time[day] += exercise_time;
    
    printf("Activity recorded for day %d\n", day + 1);
}

void display_summary(const FitnessData *data) {
    printf("\nWeekly Fitness Summary:\n");
    printf("Day\tSteps\tCalories\tExercise Time (hrs)\n");
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        printf("%d\t%d\t%d\t\t%.2f\n", i + 1, data->steps[i], data->calories[i], data->exercise_time[i]);
    }
}

void reset_data(FitnessData *data) {
    initialize_data(data);
    printf("Fitness data has been reset.\n");
}

int main() {
    FitnessData myFitnessData;
    initialize_data(&myFitnessData);
    
    int choice, day;
    
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Record Activity\n");
        printf("2. View Weekly Summary\n");
        printf("3. Reset Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the day of the week (1-7): ");
                scanf("%d", &day);
                if (day < 1 || day > 7) {
                    printf("Invalid day! Please enter a number between 1 and 7.\n");
                } else {
                    record_activity(&myFitnessData, day - 1);
                }
                break;
            case 2:
                display_summary(&myFitnessData);
                break;
            case 3:
                reset_data(&myFitnessData);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Keep moving!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    
    return 0;
}