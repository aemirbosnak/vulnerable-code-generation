//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100
#define MAX_NUM_VALS 10
#define MAX_NUM_STEPS 1000
#define MAX_NUM_CALORIES 1000

typedef struct {
    char name[MAX_STR_LEN];
    int steps[MAX_NUM_STEPS];
    int calories[MAX_NUM_STEPS];
} User;

int main() {
    User user;
    int i, j, k, l;
    char input[MAX_STR_LEN];
    char name[MAX_STR_LEN];
    int num_steps, num_calories;
    int num_vals;
    int step_count;
    int calorie_count;
    int valid_input = 0;

    // Initialize user
    user.steps[0] = 0;
    user.calories[0] = 0;

    // Get user name
    printf("Enter your name: ");
    fgets(input, MAX_STR_LEN, stdin);
    strcpy(user.name, input);
    strtok(user.name, "\n");

    // Get number of steps and calories
    printf("Enter the number of steps: ");
    fgets(input, MAX_STR_LEN, stdin);
    sscanf(input, "%d", &num_steps);
    printf("Enter the number of calories: ");
    fgets(input, MAX_STR_LEN, stdin);
    sscanf(input, "%d", &num_calories);

    // Get number of values to input
    printf("Enter the number of values to input: ");
    fgets(input, MAX_STR_LEN, stdin);
    sscanf(input, "%d", &num_vals);

    // Get steps and calories for each value
    for (i = 0; i < num_vals; i++) {
        valid_input = 0;
        while (!valid_input) {
            printf("Enter step count: ");
            fgets(input, MAX_STR_LEN, stdin);
            sscanf(input, "%d", &step_count);
            if (step_count < 0 || step_count > MAX_NUM_STEPS) {
                printf("Invalid step count. Please enter a number between 0 and %d: ", MAX_NUM_STEPS - 1);
            } else {
                valid_input = 1;
            }
        }
        valid_input = 0;
        while (!valid_input) {
            printf("Enter calorie count: ");
            fgets(input, MAX_STR_LEN, stdin);
            sscanf(input, "%d", &calorie_count);
            if (calorie_count < 0 || calorie_count > MAX_NUM_CALORIES) {
                printf("Invalid calorie count. Please enter a number between 0 and %d: ", MAX_NUM_CALORIES - 1);
            } else {
                valid_input = 1;
            }
        }
        user.steps[i] = step_count;
        user.calories[i] = calorie_count;
    }

    // Print summary
    printf("\nSummary:\n");
    printf("Name: %s\n", user.name);
    printf("Number of steps: %d\n", num_steps);
    printf("Number of calories: %d\n", num_calories);
    printf("Number of values: %d\n", num_vals);
    for (i = 0; i < num_vals; i++) {
        printf("Value %d: %d steps, %d calories\n", i + 1, user.steps[i], user.calories[i]);
    }

    return 0;
}