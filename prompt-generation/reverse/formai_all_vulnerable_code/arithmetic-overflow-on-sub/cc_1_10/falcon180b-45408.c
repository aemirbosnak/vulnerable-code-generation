//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENSORS 4
#define INTERVAL 5
#define THRESHOLD 30

int main(void) {
    int sensors[SENSORS] = {0};
    int i, j;
    time_t start_time, end_time;
    double temp, avg_temp;

    srand(time(NULL));

    for (i = 0; i < SENSORS; i++) {
        sensors[i] = rand() % 50 + 20; // generate random temperature between 20 and 70 degrees Celsius
    }

    printf("Sensor readings:\n");
    for (i = 0; i < SENSORS; i++) {
        printf("Sensor %d: %d degrees Celsius\n", i + 1, sensors[i]);
    }

    while (1) {
        for (i = 0; i < SENSORS; i++) {
            temp = sensors[i] + rand() % 5 - 2; // add some noise to the temperature readings
            if (temp > THRESHOLD) {
                printf("Warning: Sensor %d temperature is above threshold (%d degrees Celsius)\n", i + 1, temp);
            }
        }

        avg_temp = 0;
        for (i = 0; i < SENSORS; i++) {
            avg_temp += sensors[i];
        }
        avg_temp /= SENSORS;

        printf("Average temperature: %.2f degrees Celsius\n", avg_temp);

        time(&start_time);
        for (i = 0; i < SENSORS; i++) {
            for (j = 0; j < 10; j++) {
                temp = sensors[i] + rand() % 5 - 2; // generate 10 random temperature readings within 2 degrees of the actual temperature
                printf("%.2f\t", temp);
            }
            printf("\n");
        }
        time(&end_time);
        printf("Time elapsed: %ld seconds\n", end_time - start_time);

        sleep(INTERVAL);
    }

    return 0;
}