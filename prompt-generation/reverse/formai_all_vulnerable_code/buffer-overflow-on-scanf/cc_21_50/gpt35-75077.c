//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 31
#define MAX_WORKOUTS 3

int main() {

    int days[MAX_DAYS] = {0}; // Array to store each day's workout
    int workouts[MAX_WORKOUTS] = {0, 0, 0}; // Array to store total count of each workout type
    int input;
    int dayCount = 0; // Count the number of days tracked
    int workoutCount = 0; // Count the number of workouts tracked

    printf("Welcome to the C Fitness Tracker!\n\n");

    printf("Please select an option below:\n");
    printf("(1) Add a workout for today\n");
    printf("(2) View workout history\n");
    printf("(3) View workout stats\n");
    printf("(4) Quit\n\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input) {
            case 1: // Add a workout for today
                if(dayCount >= MAX_DAYS) {
                    printf("Sorry, you have already tracked the maximum number of days. Please choose another option.\n\n");
                } else {
                    printf("Please enter the number of workouts completed today (up to 3): ");
                    scanf("%d", &workouts[dayCount]);
                    while(workouts[dayCount] > MAX_WORKOUTS) { // Validate input
                        printf("You have entered too many workouts. Please enter a number up to 3: ");
                        scanf("%d", &workouts[dayCount]);
                    }

                    printf("Workout types: (1) Cardio (2) Strength (3) Flexibility\n");
                    for(int i = 0; i < workouts[dayCount]; i++) {
                        int workoutType;
                        printf("Enter workout #%d type: ", i + 1);
                        scanf("%d", &workoutType);

                        while(workoutType < 1 || workoutType > 3) { // Validate input
                            printf("Invalid input. Please enter a number between 1 and 3: ");
                            scanf("%d", &workoutType);
                        }

                        days[workoutCount++] = workoutType;
                    }

                    dayCount++;
                    printf("Workout added for today! Thank you for tracking.\n\n");
                }
                break;
            case 2: // View workout history
                if(dayCount == 0) {
                    printf("You have not tracked any workouts yet.\n\n");
                } else {
                    printf("Workout history:\n");
                    for(int i = 0; i < dayCount; i++) {
                        printf("Day %d: %d workouts\n", i + 1, workouts[i]);
                        printf("Workout types: ");
                        for(int j = 0; j < workouts[i]; j++) {
                            switch(days[j + i*MAX_DAYS]) {
                                case 1:
                                    printf("Cardio ");
                                    break;
                                case 2:
                                    printf("Strength ");
                                    break;
                                case 3:
                                    printf("Flexibility ");
                                    break;
                            }
                        }
                        printf("\n");
                    }
                    printf("\n");
                }

                break;
            case 3: // View workout stats
                if(dayCount == 0) {
                    printf("You have not tracked any workouts yet.\n\n");
                } else {
                    int cardio = 0, strength = 0, flexibility = 0;
                    for(int i = 0; i < dayCount; i++) {
                        for(int j = 0; j < workouts[i]; j++) {
                            switch(days[j + i*MAX_DAYS]) {
                                case 1:
                                    cardio++;
                                    break;
                                case 2:
                                    strength++;
                                    break;
                                case 3:
                                    flexibility++;
                                    break;
                            }
                        }
                    }

                    printf("Total workouts tracked: %d\n", workoutCount);
                    printf("Total cardio workouts: %d\n", cardio);
                    printf("Total strength workouts: %d\n", strength);
                    printf("Total flexibility workouts: %d\n\n", flexibility);
                }

                break;
            case 4: // Quit
                printf("Thank you for using the C Fitness Tracker! Goodbye.\n\n");
                break;
            default:
                printf("Invalid input. Please try again.\n\n");
                break;
        }

        if(input != 4) {
            printf("Please select another option.\n");
            printf("(1) Add a workout for today\n");
            printf("(2) View workout history\n");
            printf("(3) View workout stats\n");
            printf("(4) Quit\n\n");
        }

    } while(input != 4);

    return 0;
}