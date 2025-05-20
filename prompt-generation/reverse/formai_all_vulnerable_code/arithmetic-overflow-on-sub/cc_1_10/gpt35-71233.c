//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num_iterations = 10000000, i;
    double avg_time = 0;

    printf("Welcome to the Jousting Benchmark!\n");
    printf("You will witness the speed and power of two warriors in this battle of valour!\n");

    // Setting up the two knights
    double knight_1_speed = 2.8, knight_2_speed = 2.6;
    double knight_1_power = 5.1, knight_2_power = 4.9;
    double knight_1_armor = 3.5, knight_2_armor = 4.0;

    // Starting the jousting competition
    printf("\nLet the jousting begin!\n");

    for (i = 0; i < num_iterations; i++) {

        // Randomly selecting a winner
        int winner = (rand() % 2) + 1;

        // Adding the time taken for each iteration
        clock_t start_time = clock();

        // Calculating the damage inflicted by each knight
        double knight_1_damage = knight_1_speed * knight_1_power / knight_2_armor;
        double knight_2_damage = knight_2_speed * knight_2_power / knight_1_armor;

        if (knight_1_damage > knight_2_damage) {
            printf("Knight 1 is the winner!\n");
        } else {
            printf("Knight 2 is the winner!\n");
        }

        clock_t end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        avg_time += time_taken;
    }

    avg_time /= num_iterations;

    printf("\nResults:\n");
    printf("Number of iterations: %d\n", num_iterations);
    printf("Average time taken: %lf seconds\n", avg_time);
    printf("Thank you for attending the Jousting Benchmark!\n");

    return 0;
}