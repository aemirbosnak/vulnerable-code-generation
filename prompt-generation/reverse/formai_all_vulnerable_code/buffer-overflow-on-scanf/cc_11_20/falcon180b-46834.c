//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

int main() {
    int numbers[MAX_NUMBERS];
    int num_of_numbers;
    int sum = 0;
    int avg;
    int max = 0;
    int min = 1000000;
    int count = 0;
    int mode = 0;
    int frequency = 0;

    printf("Enter the number of integers: ");
    scanf("%d", &num_of_numbers);

    if (num_of_numbers < 1 || num_of_numbers > MAX_NUMBERS) {
        printf("Invalid number of integers.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < num_of_numbers; i++) {
        numbers[i] = rand() % 100;
        sum += numbers[i];
    }

    avg = sum / num_of_numbers;

    printf("The sum of %d integers is: %d\n", num_of_numbers, sum);
    printf("The average of %d integers is: %.2f\n", num_of_numbers, avg);

    for (int i = 0; i < num_of_numbers; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("The maximum number is: %d\n", max);
    printf("The minimum number is: %d\n", min);

    for (int i = 0; i < num_of_numbers; i++) {
        if (numbers[i] == max) {
            count++;
        }
    }

    frequency = count / num_of_numbers;

    printf("The frequency of the maximum number is: %.2f\n", frequency);

    for (int i = 0; i < num_of_numbers; i++) {
        if (numbers[i] == min) {
            count++;
        }
    }

    frequency = count / num_of_numbers;

    printf("The frequency of the minimum number is: %.2f\n", frequency);

    for (int i = 0; i < num_of_numbers; i++) {
        if (numbers[i] == max) {
            mode = numbers[i];
        }
    }

    printf("The mode of the maximum number is: %d\n", mode);

    return 0;
}