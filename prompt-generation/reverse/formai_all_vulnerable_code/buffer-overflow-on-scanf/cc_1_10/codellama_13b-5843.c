//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_WORKOUTS 100

typedef struct {
    char name[32];
    int age;
    int height;
    int weight;
    int activity_level;
    int workout_count;
    int workout_length;
    int workout_distance;
    int workout_calories;
    int workout_time;
} User;

typedef struct {
    char name[32];
    int duration;
    int distance;
    int calories;
} Workout;

void print_user(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %d\n", user->height);
    printf("Weight: %d\n", user->weight);
    printf("Activity Level: %d\n", user->activity_level);
    printf("Workout Count: %d\n", user->workout_count);
    printf("Workout Length: %d\n", user->workout_length);
    printf("Workout Distance: %d\n", user->workout_distance);
    printf("Workout Calories: %d\n", user->workout_calories);
    printf("Workout Time: %d\n", user->workout_time);
}

void print_workout(Workout* workout) {
    printf("Name: %s\n", workout->name);
    printf("Duration: %d\n", workout->duration);
    printf("Distance: %d\n", workout->distance);
    printf("Calories: %d\n", workout->calories);
}

void add_workout(User* user, Workout* workout) {
    user->workout_count++;
    user->workout_length += workout->duration;
    user->workout_distance += workout->distance;
    user->workout_calories += workout->calories;
    user->workout_time += workout->duration;
}

void remove_workout(User* user, Workout* workout) {
    user->workout_count--;
    user->workout_length -= workout->duration;
    user->workout_distance -= workout->distance;
    user->workout_calories -= workout->calories;
    user->workout_time -= workout->duration;
}

int main() {
    User users[MAX_USERS];
    Workout workouts[MAX_WORKOUTS];

    int user_count = 0;
    int workout_count = 0;

    printf("Fitness Tracker\n");

    while (1) {
        printf("Enter command: ");
        char command[32];
        scanf("%s", command);

        if (strcmp(command, "add_user") == 0) {
            User user;
            printf("Enter name: ");
            scanf("%s", user.name);
            printf("Enter age: ");
            scanf("%d", &user.age);
            printf("Enter height: ");
            scanf("%d", &user.height);
            printf("Enter weight: ");
            scanf("%d", &user.weight);
            printf("Enter activity level: ");
            scanf("%d", &user.activity_level);
            users[user_count++] = user;
            printf("User added\n");
        } else if (strcmp(command, "print_user") == 0) {
            int index;
            printf("Enter index: ");
            scanf("%d", &index);
            print_user(&users[index]);
        } else if (strcmp(command, "add_workout") == 0) {
            Workout workout;
            printf("Enter name: ");
            scanf("%s", workout.name);
            printf("Enter duration: ");
            scanf("%d", &workout.duration);
            printf("Enter distance: ");
            scanf("%d", &workout.distance);
            printf("Enter calories: ");
            scanf("%d", &workout.calories);
            workouts[workout_count++] = workout;
            printf("Workout added\n");
        } else if (strcmp(command, "print_workout") == 0) {
            int index;
            printf("Enter index: ");
            scanf("%d", &index);
            print_workout(&workouts[index]);
        } else if (strcmp(command, "add_workout_to_user") == 0) {
            int user_index;
            printf("Enter user index: ");
            scanf("%d", &user_index);
            int workout_index;
            printf("Enter workout index: ");
            scanf("%d", &workout_index);
            add_workout(&users[user_index], &workouts[workout_index]);
            printf("Workout added to user\n");
        } else if (strcmp(command, "remove_workout_from_user") == 0) {
            int user_index;
            printf("Enter user index: ");
            scanf("%d", &user_index);
            int workout_index;
            printf("Enter workout index: ");
            scanf("%d", &workout_index);
            remove_workout(&users[user_index], &workouts[workout_index]);
            printf("Workout removed from user\n");
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}