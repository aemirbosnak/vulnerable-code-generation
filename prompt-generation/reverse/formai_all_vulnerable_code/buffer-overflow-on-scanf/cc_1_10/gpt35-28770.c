//FormAI DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temp;
    float total = 0;
    float average;
    int count = 0;
    float min = 100;
    float max = -100;

    while (1) {
        printf("Enter temperature in Celsius (-100 to 100): ");
        scanf("%f", &temp);

        if (temp < -100 || temp > 100) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (temp == -999) {
            break;
        }

        count++;

        if (temp < min) {
            min = temp;
        }

        if (temp > max) {
            max = temp;
        }

        total += temp;
    }

    if (count == 0) {
        printf("No temperatures entered.\n");
        return 0;
    }

    average = total / count;

    printf("\nTotal number of temperatures entered: %d\n", count);
    printf("Minimum temperature entered: %.2f Celsius\n", min);
    printf("Maximum temperature entered: %.2f Celsius\n", max);
    printf("Average temperature entered: %.2f Celsius\n", average);

    return 0;
}