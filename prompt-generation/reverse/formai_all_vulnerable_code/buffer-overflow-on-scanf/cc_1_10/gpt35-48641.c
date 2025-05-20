//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct user {
    char name[30];
    int age;
    float weight;
    float height;
};

struct workout {
    int pushups;
    int squats;
    int situps;
    int burpees;
};

struct fitness_tracker {
    struct user user_info;
    struct workout workout_info;
    int total_calories;
};

int calculate_calories_burned(struct fitness_tracker* tracker) {
    int calories = (tracker->workout_info.pushups * 2) + (tracker->workout_info.squats * 3) + (tracker->workout_info.situps * 1.5) + (tracker->workout_info.burpees * 4);
    return calories;
}

int main() {
    struct fitness_tracker tracker;
    printf("Welcome to the C Fitness Tracker!\n");

    printf("Please enter your name: ");
    fgets(tracker.user_info.name, 30, stdin);
    printf("Please enter your age: ");
    scanf("%d", &tracker.user_info.age);
    printf("Please enter your weight (in pounds): ");
    scanf("%f", &tracker.user_info.weight);
    printf("Please enter your height (in inches): ");
    scanf("%f", &tracker.user_info.height);

    printf("\nHello, %s! Let's track your workout for today.\n", tracker.user_info.name);

    printf("Please enter the number of pushups you did: ");
    scanf("%d", &tracker.workout_info.pushups);
    printf("Please enter the number of squats you did: ");
    scanf("%d", &tracker.workout_info.squats);
    printf("Please enter the number of situps you did: ");
    scanf("%d", &tracker.workout_info.situps);
    printf("Please enter the number of burpees you did: ");
    scanf("%d", &tracker.workout_info.burpees);

    tracker.total_calories = calculate_calories_burned(&tracker);

    printf("\nGreat job, %s! You burned %d calories in today's workout.\n", tracker.user_info.name, tracker.total_calories);

    return 0;
}