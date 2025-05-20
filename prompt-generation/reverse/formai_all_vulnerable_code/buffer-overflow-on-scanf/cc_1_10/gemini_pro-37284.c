//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STEP_GOAL 10000
#define CALORIE_GOAL 2000
#define SLEEP_GOAL 8

typedef struct {
    uint32_t steps;
    uint32_t calories;
    uint32_t sleep;
} fitness_data_t;

void print_header() {
    printf("Ada Lovelace Fitness Tracker\n");
    printf("---------------------------\n");
    printf("| Steps | Calories | Sleep |\n");
    printf("|---|---|---|");
}

void print_data(fitness_data_t data) {
    printf("| %5u | %7u | %4u |\n", data.steps, data.calories, data.sleep);
}

void print_progress(fitness_data_t data) {
    printf("Progress:\n");
    printf("  Steps: %.2f%%\n", (float)data.steps / STEP_GOAL * 100);
    printf("  Calories: %.2f%%\n", (float)data.calories / CALORIE_GOAL * 100);
    printf("  Sleep: %.2f%%\n", (float)data.sleep / SLEEP_GOAL * 100);
}

void print_recommendations(fitness_data_t data) {
    if (data.steps < STEP_GOAL) {
        printf("Recommendation: Increase your daily step count.\n");
    }
    if (data.calories < CALORIE_GOAL) {
        printf("Recommendation: Increase your daily calorie intake.\n");
    }
    if (data.sleep < SLEEP_GOAL) {
        printf("Recommendation: Increase your daily sleep duration.\n");
    }
}

int main() {
    fitness_data_t data = {0, 0, 0};

    // Get user input
    printf("Please enter your fitness data for today:\n");
    printf("Steps: ");
    scanf("%u", &data.steps);
    printf("Calories: ");
    scanf("%u", &data.calories);
    printf("Sleep (hours): ");
    scanf("%u", &data.sleep);

    // Print header
    print_header();

    // Print data
    print_data(data);

    // Print progress
    print_progress(data);

    // Print recommendations
    print_recommendations(data);

    return 0;
}