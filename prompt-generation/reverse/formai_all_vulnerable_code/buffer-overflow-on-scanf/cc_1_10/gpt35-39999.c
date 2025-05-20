//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize RNG with current time
    int green_duration, yellow_duration, red_duration, num_rounds;
    int green_total = 0, yellow_total = 0, red_total = 0;

    printf("Enter the duration of green light (in seconds): ");
    scanf("%d", &green_duration);
    printf("Enter the duration of yellow light (in seconds): ");
    scanf("%d", &yellow_duration);
    printf("Enter the duration of red light (in seconds): ");
    scanf("%d", &red_duration);
    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);

    printf("\nStarting...\n\n");

    for (int i = 1; i <= num_rounds; i++) {
        printf("Round %d: \n", i);

        // Green light
        printf("Green light for %d seconds.\n", green_duration);
        green_total += green_duration;
        int random_car_count = rand() % 10 + 1;
        
        if (random_car_count > 5) {
            printf("Number of cars passing through green light: %d (above the average).\n", random_car_count);
        } else {
            printf("Number of cars passing through green light: %d (below the average).\n", random_car_count);
        }

        // Yellow light
        printf("Yellow light for %d seconds.\n", yellow_duration);
        yellow_total += yellow_duration;
        
        // Red light
        printf("Red light for %d seconds.\n", red_duration);
        red_total += red_duration;

        printf("\n");
    }

    printf("Statistics:\n");
    printf("Total time spent on green light: %d seconds.\n", green_total);
    printf("Average time spent on green light: %0.2f seconds.\n", (float)green_total / num_rounds);
    printf("Total time spent on yellow light: %d seconds.\n", yellow_total);
    printf("Average time spent on yellow light: %0.2f seconds.\n", (float)yellow_total / num_rounds);
    printf("Total time spent on red light: %d seconds.\n", red_total);
    printf("Average time spent on red light: %0.2f seconds.\n", (float)red_total / num_rounds);

    return 0;
}