//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 1000
#define MIN_TEMP -273.15

int main() {
    char choice;
    int num_temps;
    double temps[MAX_TEMP];
    double min_temp = MAX_TEMP;
    double max_temp = MIN_TEMP;
    double avg_temp = 0;
    double sum_temps = 0;
    double diff;
    int i;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Welcome to the Temperature Monitor!\n");
    printf("This program will monitor the temperature over time.\n");
    printf("You can enter as many temperatures as you want.\n");
    printf("Press 'q' to quit.\n");

    srand(time(NULL));
    start_time = time(NULL);

    while (choice!= 'q') {
        printf("Enter a temperature (in Celsius) or 'q' to quit: ");
        scanf("%lf", &temps[num_temps]);

        if (choice == 'q') {
            break;
        }

        if (num_temps == 0) {
            min_temp = temps[0];
            max_temp = temps[0];
        } else if (temps[num_temps] < min_temp) {
            min_temp = temps[num_temps];
        } else if (temps[num_temps] > max_temp) {
            max_temp = temps[num_temps];
        }

        sum_temps += temps[num_temps];
        num_temps++;

        if (num_temps % 5 == 0) {
            avg_temp = sum_temps / num_temps;
            printf("Average temperature: %.2lf\n", avg_temp);
        }

        if (num_temps > 1) {
            diff = temps[num_temps - 1] - temps[num_temps - 2];
            if (diff > 0) {
                printf("Temperature is increasing.\n");
            } else if (diff < 0) {
                printf("Temperature is decreasing.\n");
            }
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Monitoring complete!\n");
    printf("Minimum temperature: %.2lf\n", min_temp);
    printf("Maximum temperature: %.2lf\n", max_temp);
    printf("Average temperature: %.2lf\n", avg_temp);
    printf("Elapsed time: %ld seconds\n", elapsed_time);

    return 0;
}