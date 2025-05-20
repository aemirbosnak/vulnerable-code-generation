//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_USER_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 60 * 60 * 24 // 1 day

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
    int calories;
} Workout;

typedef struct {
    char name[MAX_USER_NAME_LENGTH];
    int age;
    int weight;
    int height;
} User;

void print_workout(Workout *workout) {
    printf("Name: %s\n", workout->name);
    printf("Duration: %d seconds\n", workout->duration);
    printf("Calories burned: %d\n\n", workout->calories);
}

void print_user(User *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d lbs\n", user->weight);
    printf("Height: %d inches\n\n", user->height);
}

int main() {
    User user;
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    printf("Welcome to the Fitness Tracker!\n\n");
    printf("Please enter your name:\n");
    scanf("%s", user.name);
    printf("Please enter your age:\n");
    scanf("%d", &user.age);
    printf("Please enter your weight:\n");
    scanf("%d", &user.weight);
    printf("Please enter your height:\n");
    scanf("%d", &user.height);

    while (num_workouts < MAX_WORKOUTS) {
        printf("\nDo you want to add a workout? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Please enter the name of the workout:\n");
            scanf("%s", workouts[num_workouts].name);
            printf("Please enter the duration of the workout in seconds:\n");
            scanf("%d", &workouts[num_workouts].duration);
            printf("Please enter the number of calories burned during the workout:\n");
            scanf("%d", &workouts[num_workouts].calories);
            num_workouts++;
        } else {
            break;
        }
    }

    printf("\nWorkouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        print_workout(&workouts[i]);
    }

    printf("\nUser info:\n");
    print_user(&user);

    return 0;
}