//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_WORKOUTS 10

struct workout{
    char name[50];
    int duration;
    int calories;
};

void addWorkout(struct workout *workouts, int numWorkouts){
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[numWorkouts].duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);

    numWorkouts++;
}

void displayWorkouts(struct workout *workouts, int numWorkouts){
    printf("\nWorkout Log:\n");
    printf("Name\tDuration\tCalories\n");

    for(int i=0; i<numWorkouts; i++){
        printf("%s\t%d\t\t%d\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

int main(){
    struct workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;

    while(1){
        printf("\n1. Add Workout\n2. Display Workouts\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(numWorkouts >= MAX_WORKOUTS){
                    printf("Maximum number of workouts reached.\n");
                }else{
                    addWorkout(workouts, numWorkouts);
                }
                break;

            case 2:
                displayWorkouts(workouts, numWorkouts);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}