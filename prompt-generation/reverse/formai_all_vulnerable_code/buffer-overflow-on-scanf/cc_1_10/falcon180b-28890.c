//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct workout {
    char exercise[50];
    int sets;
    int reps;
    float weight;
    int duration;
    int calories;
};

void add_workout(struct workout *workout_list, int size, int index) {
    printf("Enter exercise name: ");
    scanf("%s", workout_list[index].exercise);
    printf("Enter number of sets: ");
    scanf("%d", &workout_list[index].sets);
    printf("Enter number of reps: ");
    scanf("%d", &workout_list[index].reps);
    printf("Enter weight (in lbs): ");
    scanf("%f", &workout_list[index].weight);
    printf("Enter duration (in minutes): ");
    scanf("%d", &workout_list[index].duration);
    workout_list[index].calories = (workout_list[index].weight * workout_list[index].duration / 60.0) * 8.0;
    printf("Calories burned: %d\n", workout_list[index].calories);
}

void view_workout(struct workout *workout_list, int size, int index) {
    printf("Exercise: %s\n", workout_list[index].exercise);
    printf("Sets: %d\n", workout_list[index].sets);
    printf("Reps: %d\n", workout_list[index].reps);
    printf("Weight (in lbs): %f\n", workout_list[index].weight);
    printf("Duration (in minutes): %d\n", workout_list[index].duration);
    printf("Calories burned: %d\n\n", workout_list[index].calories);
}

void track_workout(struct workout *workout_list, int size, int index) {
    int choice;
    do {
        printf("1. Add workout\n2. View workout\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_workout(workout_list, size, index);
                break;
            case 2:
                view_workout(workout_list, size, index);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);
}

int main() {
    int size = 10;
    struct workout workout_list[size];
    int index = 0;
    track_workout(workout_list, size, index);
    return 0;
}