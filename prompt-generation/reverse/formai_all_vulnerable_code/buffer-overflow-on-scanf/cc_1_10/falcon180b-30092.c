//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10

struct workout {
    char name[50];
    time_t start_time;
    time_t end_time;
    int duration;
};

int main() {
    int choice, i;
    struct workout workouts[MAX_WORKOUTS];
    time_t current_time;

    srand(time(NULL));
    current_time = time(NULL);

    printf("Welcome to the Post-Apocalyptic Fitness Tracker!\n");
    printf("What would you like to do?\n");
    printf("1. Start a workout\n");
    printf("2. End a workout\n");
    printf("3. View workout history\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the name of your workout:\n");
            scanf("%s", workouts[0].name);
            workouts[0].start_time = current_time;
            break;
        case 2:
            printf("Enter the name of your workout:\n");
            scanf("%s", workouts[0].name);
            workouts[0].end_time = current_time;
            workouts[0].duration = difftime(workouts[0].end_time, workouts[0].start_time);
            break;
        case 3:
            printf("Workout history:\n");
            for(i=0; i<MAX_WORKOUTS; i++) {
                if(workouts[i].start_time!= 0) {
                    printf("%s: %d seconds\n", workouts[i].name, workouts[i].duration);
                }
            }
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
    }

    return 0;
}