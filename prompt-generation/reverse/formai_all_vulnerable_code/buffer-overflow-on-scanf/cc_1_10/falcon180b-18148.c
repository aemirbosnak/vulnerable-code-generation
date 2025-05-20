//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 20

int main() {
    //initialize an array of integers
    int numbers[MAX_NUMBERS] = {0};
    int count = 0;

    //prompt the user for input
    printf("Enter up to %d integers (type -1 to stop): ", MAX_NUMBERS);

    //read in integers until the user enters -1
    while (scanf("%d", &numbers[count]) == 1 && numbers[count]!= -1) {
        count++;
    }

    //sort the array in ascending order
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    //calculate the sum, average, and standard deviation of the numbers
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }

    double average = (double) sum / count;

    double squared_diffs_sum = 0;
    for (int i = 0; i < count; i++) {
        squared_diffs_sum += pow(numbers[i] - average, 2);
    }

    double standard_deviation = sqrt(squared_diffs_sum / count);

    //print the results
    printf("Sorted array: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Standard deviation: %.2f\n", standard_deviation);

    return 0;
}