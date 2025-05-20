//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP -100

int main() {
    int i, j;
    char c;
    float temp[MAX_TEMP];
    float avg_temp = 0;
    float max_temp = MIN_TEMP;
    float min_temp = MAX_TEMP;
    time_t start_time, end_time;
    double elapsed_time;
    int count = 0;

    printf("Welcome to the Artistic Temperature Monitor!\n");
    printf("Press Enter to start monitoring...\n");
    scanf("%c", &c);

    time(&start_time);

    while (1) {
        printf("Enter the current temperature (Celsius): ");
        scanf("%f", &temp[count]);

        if (temp[count] > MAX_TEMP) {
            printf("Invalid temperature!\n");
            continue;
        }

        if (temp[count] < MIN_TEMP) {
            printf("Invalid temperature!\n");
            continue;
        }

        if (count == MAX_TEMP - 1) {
            count = 0;
        } else {
            count++;
        }

        if (temp[count] > max_temp) {
            max_temp = temp[count];
        }

        if (temp[count] < min_temp) {
            min_temp = temp[count];
        }

        avg_temp += temp[count];
    }

    elapsed_time = difftime(time(NULL), start_time);
    printf("Monitoring stopped after %lf seconds.\n", elapsed_time);
    printf("Average temperature: %.2f\n", avg_temp / count);
    printf("Maximum temperature: %.2f\n", max_temp);
    printf("Minimum temperature: %.2f\n", min_temp);

    return 0;
}