//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DAYS 30

typedef struct {
    int steps;
    double distance;
} DayData;

void calculate_calories(double weight, double height, double activity_level) {
    double BMR, calories;

    BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * activity_level);
    calories = BMR * activity_level;

    printf("Calories burned: %.2f\n", calories);
}

int main() {
    DayData days[MAX_DAYS];
    int i, days_used = 0, steps_today = 0, total_steps = 0;
    double distance_today = 0.0, total_distance = 0.0, weight, height, activity_level;

    while (1) {
        printf("\nWelcome to Fitness Tracker!\n");
        printf("1. Record new day\n");
        printf("2. Display statistics\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Enter steps taken today: ");
                scanf("%d", &steps_today);
                printf("Enter distance traveled today (in km): ");
                scanf("%lf", &distance_today);
                days[days_used].steps = steps_today;
                days[days_used].distance = distance_today;
                total_steps += steps_today;
                total_distance += distance_today;
                days_used++;

                if (days_used >= MAX_DAYS) {
                    printf("Maximum number of days reached. Please delete old data to record new.\n");
                    break;
                }

                printf("Data recorded successfully.\n");
                calculate_calories(70.0, 1.70, 1.5); // Example user input

                break;

            case 2:
                if (days_used < 1) {
                    printf("No data available.\n");
                    break;
                }

                printf("\nStatistics for the last %d days:\n", days_used);
                printf("Average steps per day: %.2f\n", total_steps / days_used);
                printf("Total steps: %d\n", total_steps);
                printf("Average distance per day: %.2f km\n", total_distance / days_used);
                printf("Total distance: %.2f km\n", total_distance);

                break;

            case 3:
                printf("Exiting Fitness Tracker...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}