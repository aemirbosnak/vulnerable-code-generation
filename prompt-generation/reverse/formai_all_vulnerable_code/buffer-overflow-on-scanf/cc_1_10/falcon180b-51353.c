//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, operator;
    char repeat;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user decides to quit
    do {
        // Generate two random numbers and an operator
        num1 = rand_int(1, 100);
        num2 = rand_int(1, 100);
        operator = rand_int(1, 4);

        // Perform the arithmetic operation and print the result
        switch(operator) {
            case 1:
                printf("%.0f + %.0f = %.0f\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("%.0f - %.0f = %.0f\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("%.0f * %.0f = %.0f\n", num1, num2, num1 * num2);
                break;
            case 4:
                if(num2 == 0) {
                    printf("Cannot divide by zero!\n");
                } else {
                    printf("%.0f / %.0f = %.2f\n", num1, num2, (float)num1 / (float)num2);
                }
                break;
        }

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n) ");
        scanf("%c", &repeat);

    } while(repeat == 'y' || repeat == 'Y');

    return 0;
}