//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 100

int main() {
    int temps[MAX_TEMP] = {0};
    int temp_count = 0;
    int current_temp = 0;
    int sum = 0;
    int i = 0;

    printf("Enter 0 to stop entering temperatures\n");

    while (temp_count < MAX_TEMP) {
        printf("Enter a temperature: ");
        scanf("%d", &current_temp);

        if (current_temp == 0) {
            break;
        }

        temps[temp_count++] = current_temp;
        sum += current_temp;
    }

    printf("\n");

    if (temp_count == 0) {
        printf("No temperatures entered.\n");
        exit(0);
    }

    printf("Temperatures entered:\n");

    for (i = 0; i < temp_count; i++) {
        printf("%d ", temps[i]);
    }

    printf("\n");

    double avg = (double) sum / (double) temp_count;

    printf("Average temperature: %.2lf\n", avg);

    int above_avg_count = 0;

    for (i = 0; i < temp_count; i++) {
        if (temps[i] > avg) {
            above_avg_count++;
        }
    }

    printf("Number of temperatures above average: %d\n", above_avg_count);

    int below_avg_count = 0;

    for (i = 0; i < temp_count; i++) {
        if (temps[i] < avg) {
            below_avg_count++;
        }
    }

    printf("Number of temperatures below average: %d\n", below_avg_count);

    return 0;
}