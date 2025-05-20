//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Struct to represent exercise stats
typedef struct stat {
    int reps;
    int sets;
    float weight;
} stat_t;

// Function to print exercise stats
void print_stat(stat_t s) {
    printf("Reps: %d\nSets: %d\nWeight: %.2f\n", s.reps, s.sets, s.weight);
}

int main() {
    // Initialize stats for the day
    stat_t squat_stat = {10, 3, 185.0};
    stat_t bench_stat = {8, 4, 135.0};
    stat_t deadlift_stat = {5, 5, 225.0};

    char user_input;
    int current_day = 1;
    while (1) {
        // Print menu options
        printf("Day %d: \n", current_day);
        printf("1. Squat - ");
        print_stat(squat_stat);
        printf("2. Bench - ");
        print_stat(bench_stat);
        printf("3. Deadlift - ");
        print_stat(deadlift_stat);
        printf("4. Exit\n");
        printf("Enter an option: ");

        // Get user input
        scanf(" %c", &user_input);

        // Check user input and update stats accordingly
        switch (user_input) {
            case '1':
                printf("Enter number of reps: ");
                scanf("%d", &squat_stat.reps);
                printf("Enter number of sets: ");
                scanf("%d", &squat_stat.sets);
                printf("Enter weight: ");
                scanf("%f", &squat_stat.weight);
                break;
            case '2':
                printf("Enter number of reps: ");
                scanf("%d", &bench_stat.reps);
                printf("Enter number of sets: ");
                scanf("%d", &bench_stat.sets);
                printf("Enter weight: ");
                scanf("%f", &bench_stat.weight);
                break;
            case '3':
                printf("Enter number of reps: ");
                scanf("%d", &deadlift_stat.reps);
                printf("Enter number of sets: ");
                scanf("%d", &deadlift_stat.sets);
                printf("Enter weight: ");
                scanf("%f", &deadlift_stat.weight);
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input. Please enter 1-4.\n");
                break;
        }
        printf("\n");
        current_day++; // Increment day counter
    }

    return 0;
}