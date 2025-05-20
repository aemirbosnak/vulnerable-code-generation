//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int age;
    double height;
    double weight;
    int daily_steps;
    char **exercise_types;
    int num_exercises;
} health_profile;

void print_profile(health_profile profile) {
    printf("Name: %s\n", profile.name);
    printf("Age: %d\n", profile.age);
    printf("Height: %f\n", profile.height);
    printf("Weight: %f\n", profile.weight);
    printf("Daily Steps: %d\n", profile.daily_steps);
    if (profile.num_exercises > 0) {
        printf("Exercises:\n");
        for (int i = 0; i < profile.num_exercises; i++) {
            printf(" - %s\n", profile.exercise_types[i]);
        }
    } else {
        printf("No exercises recorded.\n");
    }
}

void add_exercise(health_profile *profile, char *exercise_type) {
    if (profile->num_exercises == 0) {
        profile->exercise_types = malloc(sizeof(char *) * 1);
    } else {
        profile->exercise_types = realloc(profile->exercise_types, sizeof(char *) * (profile->num_exercises + 1));
    }
    profile->exercise_types[profile->num_exercises] = malloc(sizeof(char) * strlen(exercise_type) + 1);
    strcpy(profile->exercise_types[profile->num_exercises], exercise_type);
    profile->num_exercises++;
}

int main() {
    // Create a new health profile
    health_profile profile;

    // Get the user's name
    printf("Enter your name: ");
    scanf("%s", profile.name);

    // Get the user's age
    printf("Enter your age: ");
    scanf("%d", &profile.age);

    // Get the user's height
    printf("Enter your height in meters: ");
    scanf("%lf", &profile.height);

    // Get the user's weight
    printf("Enter your weight in kilograms: ");
    scanf("%lf", &profile.weight);

    // Get the user's daily steps
    printf("Enter your average daily steps: ");
    scanf("%d", &profile.daily_steps);

    // Get the user's exercise types
    char exercise_type[20];
    printf("Enter your exercise types (enter 'q' to quit): ");
    while (strcmp(exercise_type, "q") != 0) {
        scanf("%s", exercise_type);
        if (strcmp(exercise_type, "q") != 0) {
            add_exercise(&profile, exercise_type);
        }
    }

    // Print the user's health profile
    print_profile(profile);

    return 0;
}