//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_WORKOUTS 5

struct {
    char name[50];
    int age;
    int weight;
    int height;
} user;

struct {
    char name[50];
    int calories;
    int duration;
    time_t timestamp;
} workout[MAX_WORKOUTS];

void init() {
    user.age = 0;
    user.weight = 0;
    user.height = 0;

    for (int i = 0; i < MAX_WORKOUTS; i++) {
        workout[i].calories = 0;
        workout[i].duration = 0;
        workout[i].timestamp = 0;
    }
}

void display_user_info() {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %d\n", user.weight);
    printf("Height: %d\n", user.height);
}

void display_workout_info() {
    printf("Workout Name\tCalories\tDuration\tTimestamp\n");
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        if (workout[i].calories > 0) {
            printf("%s\t%d\t%d\t%ld\n", workout[i].name, workout[i].calories, workout[i].duration, workout[i].timestamp);
        }
    }
}

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workout[MAX_WORKOUTS - 1].name);

    printf("Enter calories burned: ");
    scanf("%d", &workout[MAX_WORKOUTS - 1].calories);

    printf("Enter duration (in seconds): ");
    scanf("%d", &workout[MAX_WORKOUTS - 1].duration);

    time(&workout[MAX_WORKOUTS - 1].timestamp);
}

int main() {
    init();

    while (1) {
        printf("Enter 1 to add a workout\n");
        printf("Enter 2 to display user info\n");
        printf("Enter 3 to display workout info\n");
        printf("Enter 0 to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_user_info();
                break;
            case 3:
                display_workout_info();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}