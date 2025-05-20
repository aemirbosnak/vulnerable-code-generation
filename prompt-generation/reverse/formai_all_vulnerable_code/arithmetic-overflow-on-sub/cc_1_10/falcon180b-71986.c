//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories;
} workout;

workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    char input[100];
    printf("Enter workout name: ");
    fgets(input, 100, stdin);
    strcpy(workouts[num_workouts].name, input);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[num_workouts].duration);
    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);
    num_workouts++;
}

void display_workout(int index) {
    printf("\nWorkout %d:\n", index+1);
    printf("Name: %s\n", workouts[index].name);
    printf("Duration: %d minutes\n", workouts[index].duration);
    printf("Calories burned: %d\n", workouts[index].calories);
}

void display_all_workouts() {
    printf("\nAll Workouts:\n");
    for(int i=0; i<num_workouts; i++) {
        display_workout(i);
    }
}

void delete_workout(int index) {
    if(index >= 0 && index < num_workouts) {
        num_workouts--;
        for(int i=index; i<num_workouts; i++) {
            strcpy(workouts[i].name, workouts[i+1].name);
            workouts[i].duration = workouts[i+1].duration;
            workouts[i].calories = workouts[i+1].calories;
        }
    } else {
        printf("Invalid workout index.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Display all workouts\n");
        printf("3. Delete workout\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_all_workouts();
                break;
            case 3:
                printf("Enter workout index to delete: ");
                int index;
                scanf("%d", &index);
                delete_workout(index-1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}