//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, m, sum = 0;
    float avg;
    char repeat;

    srand(time(NULL));
    n = rand() % 50 + 1; // Generate a random number between 1 and 50
    m = rand() % 50 + 1; // Generate another random number between 1 and 50

    printf("Welcome to the Arithmetic Game!\n");
    printf("You will be given two numbers between 1 and 50.\n");
    printf("Your goal is to add, subtract, multiply, and divide these numbers to get the result of 0.\n");
    printf("Are you ready? (y/n): ");
    scanf("%c", &repeat);

    while (repeat == 'y' || repeat == 'Y') {
        i = rand() % 4; // Generate a random operation: 0 for addition, 1 for subtraction, 2 for multiplication, 3 for division
        switch (i) {
            case 0:
                printf("Addition:\n");
                sum = n + m;
                break;
            case 1:
                printf("Subtraction:\n");
                sum = n - m;
                break;
            case 2:
                printf("Multiplication:\n");
                sum = n * m;
                break;
            case 3:
                printf("Division:\n");
                if (m == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    break;
                }
                sum = n / m;
                break;
        }
        printf("The result is: %d\n", sum);

        if (sum == 0) {
            printf("Congratulations! You got the result of 0!\n");
        } else {
            printf("Sorry, you did not get the result of 0.\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf("%c", &repeat);
    }

    return 0;
}