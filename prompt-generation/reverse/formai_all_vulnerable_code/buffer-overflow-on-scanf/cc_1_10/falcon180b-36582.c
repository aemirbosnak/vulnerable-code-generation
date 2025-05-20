//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0;
    int min_temp = 0;
    int max_temp = 0;
    int temp_avg = 0;
    int num_temps = 0;

    time_t start_time;
    time_t end_time;
    double elapsed_time;

    start_time = time(NULL);

    while (1) {
        printf("Enter temperature (0 to exit): ");
        scanf("%d", &temperature);

        if (temperature == 0) {
            break;
        }

        if (num_temps == 0) {
            min_temp = temperature;
            max_temp = temperature;
        } else {
            if (temperature < min_temp) {
                min_temp = temperature;
            }

            if (temperature > max_temp) {
                max_temp = temperature;
            }
        }

        temp_avg += temperature;
        num_temps++;
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Minimum temperature: %d\n", min_temp);
    printf("Maximum temperature: %d\n", max_temp);
    printf("Average temperature: %d\n", temp_avg / num_temps);
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    return 0;
}