//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 50
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} Workout;

int main() {
    int choice;
    char username[MAX_NAME_LENGTH];
    int num_workouts = 0;
    Workout workouts[MAX_WORKOUTS];

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", username);

    while(1) {
        printf("\n");
        printf("1. Add a workout\n");
        printf("2. View your workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_workouts == MAX_WORKOUTS) {
                    printf("Sorry, you have reached the maximum number of workouts.\n");
                    break;
                }
                printf("Enter workout name (up to %d characters): ", MAX_NAME_LENGTH);
                scanf("%s", workouts[num_workouts].name);
                printf("Enter workout description (up to %d characters): ", MAX_DESCRIPTION_LENGTH);
                scanf("%s", workouts[num_workouts].description);
                workouts[num_workouts].start_time = time(NULL);
                num_workouts++;
                break;
            case 2:
                if(num_workouts == 0) {
                    printf("You have not added any workouts yet.\n");
                    break;
                }
                printf("\n");
                printf("Workout Name\tDuration\n");
                for(int i = 0; i < num_workouts; i++) {
                    workouts[i].duration = difftime(workouts[i].end_time, workouts[i].start_time);
                    printf("%s\t\t%d seconds\n", workouts[i].name, workouts[i].duration);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}