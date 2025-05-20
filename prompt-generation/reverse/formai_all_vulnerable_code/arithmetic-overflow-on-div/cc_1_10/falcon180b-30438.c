//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate paranoid style numbers
int paranoid_number(int min, int max) {
    int paranoid_num = 0;
    int random_num = rand() % (max - min + 1) + min;
    int i = 0;
    while (random_num!= 0) {
        paranoid_num += random_num % 10;
        random_num /= 10;
        i++;
        if (i == 10) {
            break;
        }
    }
    return paranoid_num;
}

int main() {
    srand(time(NULL));
    int min = 1;
    int max = 1000;
    int num1, num2;
    int operation;
    int result;
    char repeat;

    do {
        printf("Enter minimum value: ");
        scanf("%d", &min);
        printf("Enter maximum value: ");
        scanf("%d", &max);
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("Enter the operation (+, -, *, /): ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                result = num1 + num2;
                break;
            case 2:
                result = num1 - num2;
                break;
            case 3:
                result = num1 * num2;
                break;
            case 4:
                if (num2 == 0) {
                    printf("Division by zero is not allowed.\n");
                    result = 0;
                } else {
                    result = num1 / num2;
                }
                break;
            default:
                printf("Invalid operation.\n");
                result = 0;
        }

        printf("Result: %d\n", result);
        printf("Do you want to try again? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}