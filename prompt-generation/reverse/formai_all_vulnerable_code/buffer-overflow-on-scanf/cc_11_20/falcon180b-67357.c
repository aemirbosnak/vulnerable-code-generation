//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 50
#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 1000

struct workout {
    char name[50];
    int duration;
    int calories;
};

struct exercise {
    char name[50];
    int duration;
    int calories;
};

struct step {
    int count;
    int distance;
    int calories;
};

struct distance {
    int count;
    int distance;
    int calories;
};

struct calorie {
    int count;
    int calories;
};

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;
    int choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add Workout\n");
        printf("2. Remove Workout\n");
        printf("3. View Workouts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_workouts >= MAX_WORKOUTS) {
                    printf("Cannot add more workouts.\n");
                } else {
                    printf("Enter workout name: ");
                    scanf("%s", workouts[num_workouts].name);
                    printf("Enter workout duration (in minutes): ");
                    scanf("%d", &workouts[num_workouts].duration);
                    printf("Enter workout calories burned: ");
                    scanf("%d", &workouts[num_workouts].calories);
                    num_workouts++;
                }
                break;
            case 2:
                if(num_workouts == 0) {
                    printf("No workouts to remove.\n");
                } else {
                    printf("Enter workout index to remove: ");
                    int index;
                    scanf("%d", &index);
                    if(index >= 0 && index < num_workouts) {
                        num_workouts--;
                        for(int i=index; i<num_workouts; i++) {
                            workouts[i] = workouts[i+1];
                        }
                    } else {
                        printf("Invalid workout index.\n");
                    }
                }
                break;
            case 3:
                if(num_workouts == 0) {
                    printf("No workouts to view.\n");
                } else {
                    printf("Workout List:\n");
                    for(int i=0; i<num_workouts; i++) {
                        printf("%s\n", workouts[i].name);
                    }
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}