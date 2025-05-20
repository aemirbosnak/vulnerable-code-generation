//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[50];
    int age;
    float height;
    float weight;
};

struct fitness_stats {
    float max_benchpress;
    float max_deadlift;
    float max_squat;
    float avg_miles_run;
};

int main() {
    struct user user1;
    struct fitness_stats fitness1;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", user1.name);

    printf("Please enter your age: ");
    scanf("%d", &user1.age);

    printf("Please enter your height in inches: ");
    scanf("%f", &user1.height);

    printf("Please enter your weight in pounds: ");
    scanf("%f", &user1.weight);

    printf("\nWelcome, %s!\n", user1.name);
    printf("Your stats:\n");
    printf("Age: %d\n", user1.age);
    printf("Height: %.2f inches\n", user1.height);
    printf("Weight: %.2f pounds\n\n", user1.weight);

    printf("Please enter your maximum bench press weight: ");
    scanf("%f", &fitness1.max_benchpress);

    printf("Please enter your maximum deadlift weight: ");
    scanf("%f", &fitness1.max_deadlift);

    printf("Please enter your maximum squat weight: ");
    scanf("%f", &fitness1.max_squat);

    printf("Please enter your average miles run per week: ");
    scanf("%f", &fitness1.avg_miles_run);

    printf("\nYour Fitness Stats:\n");
    printf("Maximum Bench Press: %.2f pounds\n", fitness1.max_benchpress);
    printf("Maximum Deadlift: %.2f pounds\n", fitness1.max_deadlift);
    printf("Maximum Squat: %.2f pounds\n", fitness1.max_squat);
    printf("Average Miles Run Per Week: %.2f miles\n\n", fitness1.avg_miles_run);

    return 0;
}