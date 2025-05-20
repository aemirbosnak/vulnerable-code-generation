//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_INVASION_PROBABILITY 0.0001
#define TOTAL_DAYS_IN_YEAR 365
#define MAX_NUMBER_OF_ALIENS 100

int main() {
    int number_of_aliens = 0;
    int days_without_invasion = 0;
    float probability_of_invasion = 1;
    float alien_invasion_probability = ALIEN_INVASION_PROBABILITY;
    float days_since_last_invasion = 0;
    float days_without_invasion_probability = (1 - alien_invasion_probability);
    time_t current_time;
    struct tm *time_info;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will calculate the probability of an alien invasion in the next year.\n");
    printf("Please enter the number of days you want to simulate (minimum 1): ");
    scanf("%d", &days_without_invasion);

    while (days_without_invasion < 1) {
        printf("Invalid input. Please enter a number greater than or equal to 1: ");
        scanf("%d", &days_without_invasion);
    }

    printf("Simulating %d days...\n", days_without_invasion);

    for (int i = 0; i < days_without_invasion; i++) {
        current_time = time(NULL);
        time_info = localtime(&current_time);

        if (i == 0) {
            printf("Day 1: No invasion yet.\n");
        } else if (i % TOTAL_DAYS_IN_YEAR == 0) {
            printf("Day %d: Still no invasion. The probability of an invasion in the next year is %.2f%%.\n", i, probability_of_invasion * 100);
        } else if (rand() % 100 < alien_invasion_probability * 100) {
            number_of_aliens++;
            printf("Day %d: Invasion! %d aliens have landed on Earth.\n", i, number_of_aliens);
            probability_of_invasion = 1;
            days_since_last_invasion = 0;
        } else {
            days_since_last_invasion++;
            probability_of_invasion = days_since_last_invasion * days_without_invasion_probability;
        }

        if (number_of_aliens >= MAX_NUMBER_OF_ALIENS) {
            break;
        }
    }

    return 0;
}