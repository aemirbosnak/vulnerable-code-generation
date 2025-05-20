//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_TIME 60

struct workout {
    int duration;
    int calories;
};

int main() {
    int choice;
    int num_workouts = 0;
    struct workout workouts[MAX_WORKOUTS];
    int total_calories = 0;

    printf("Welcome to the Happy Fitness Tracker!\n");
    printf("We're so glad you're here to get fit and have fun!\n");
    printf("What would you like to do today?\n");
    printf("1. Add a workout\n");
    printf("2. View workouts\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    while(choice!= 3) {
        switch(choice) {
            case 1:
                if(num_workouts >= MAX_WORKOUTS) {
                    printf("Sorry, you've reached the maximum number of workouts for today!\n");
                } else {
                    printf("Great choice! Let's add a workout.\n");
                    printf("How long did you exercise? (in minutes)\n");
                    scanf("%d", &workouts[num_workouts].duration);
                    printf("How many calories did you burn?\n");
                    scanf("%d", &workouts[num_workouts].calories);
                    total_calories += workouts[num_workouts].calories;
                    num_workouts++;
                }
                break;
            case 2:
                printf("Awesome! Let's take a look at your workouts for the day.\n");
                printf("You've burned a total of %d calories!\n", total_calories);
                for(int i = 0; i < num_workouts; i++) {
                    printf("Workout %d: %d minutes, %d calories\n", i+1, workouts[i].duration, workouts[i].calories);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("What would you like to do now?\n");
        printf("1. Add a workout\n");
        printf("2. View workouts\n");
        printf("3. Quit\n");

        scanf("%d", &choice);
    }

    printf("Thanks for using the Happy Fitness Tracker! Have a great day!\n");

    return 0;
}