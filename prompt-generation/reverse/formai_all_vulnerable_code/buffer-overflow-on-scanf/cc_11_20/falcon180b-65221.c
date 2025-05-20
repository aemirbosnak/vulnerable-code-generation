//Falcon-180B DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

int main() {
    int numbers[MAX_NUMBERS];
    int num_of_numbers;
    int i, j, temp;
    int choice;
    int sum = 0;

    srand(time(NULL));

    printf("Welcome to the Cheerful Number Game!\n");
    printf("How many numbers would you like to generate? (1-100): ");
    scanf("%d", &num_of_numbers);

    if (num_of_numbers < 1 || num_of_numbers > MAX_NUMBERS) {
        printf("Sorry, that's not a valid number of numbers.\n");
        return 1;
    }

    for (i = 0; i < num_of_numbers; i++) {
        numbers[i] = rand() % 100 + 1;
    }

    printf("Here are your %d cheerful numbers:\n", num_of_numbers);

    for (i = 0; i < num_of_numbers; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    do {
        printf("Would you like to sort the numbers in ascending or descending order? (1 for ascending, 2 for descending): ");
        scanf("%d", &choice);
    } while (choice!= 1 && choice!= 2);

    if (choice == 1) {
        for (i = 0; i < num_of_numbers - 1; i++) {
            for (j = 0; j < num_of_numbers - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    } else {
        for (i = 0; i < num_of_numbers - 1; i++) {
            for (j = 0; j < num_of_numbers - i - 1; j++) {
                if (numbers[j] < numbers[j + 1]) {
                    temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    }

    printf("Here are your sorted %d cheerful numbers:\n", num_of_numbers);

    for (i = 0; i < num_of_numbers; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}