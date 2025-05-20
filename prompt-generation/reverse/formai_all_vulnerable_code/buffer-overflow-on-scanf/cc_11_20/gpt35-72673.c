//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {

    // Let's create a random number for the user to solve
    int num1 = rand() % 100, num2 = rand() % 100, num3 = rand() % 100;
    float result = 0.0;
    int choice;

    // Let's ask the user what operation they want to perform
    printf("Welcome to MathBot, your personal math tutor! I have a surprise math exercise for you today.\n\n");
    printf("Your first number is: %d\n", num1);
    printf("Your second number is: %d\n", num2);
    printf("Your third number is: %d\n\n", num3);

    printf("What operation do you want to perform? Enter:\n");
    printf("1 for addition\n");
    printf("2 for subtraction\n");
    printf("3 for multiplication\n");
    printf("4 for division\n");

    scanf("%d", &choice);

    switch(choice) {

        case 1:
            result = num1 + num2 + num3;
            printf("\nYou chose addition. The answer is %.2f\n", result);
            break;

        case 2:
            result = num1 - num2 - num3;
            printf("\nYou chose subtraction. The answer is %.2f\n", result);
            break;

        case 3:
            result = num1 * num2 * num3;
            printf("\nYou chose multiplication. The answer is %.2f\n", result);
            break;

        case 4:
            if(num2 == 0 || num3 == 0) {
                printf("\nYou can't perform division with a zero so let's re-do the numbers.\n");
                while(num2 == 0 || num3 == 0) {
                    num2 = rand() % 100;
                    num3 = rand() % 100;
                }
            }
            result = (float)num1 / (float)num2 / (float)num3;
            printf("\nYou chose division. The answer is %.2f\n", result);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    if(result == INFINITY || isnan(result)) {
        printf("\nOops, the result is out of range. Let's re-do the numbers.\n");
        num1 = rand() % 100;
        num2 = rand() % 100;
        num3 = rand() % 100;
        result = 0.0;
    }

    int i;
    bool is_prime = true;

    for(i = 2; i <= result / 2; ++i) {
        if((int)result % i == 0) {
            is_prime = false;
            break;
        }
    }

    if(is_prime) {
        printf("\nThe final result is %.2f which is a prime number!\n", result);
    } else {
        printf("\nThe final result is %.2f which is not a prime number.\n", result);
    }

    printf("\nThank you for using MathBot today! Have a great day!\n");

    return 0;
}