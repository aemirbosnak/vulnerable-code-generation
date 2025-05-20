//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's play a little game!
    int x, y, z;
    printf("Pick three numbers, dear friend!\n");
    printf("Enter your first number: ");
    scanf("%d", &x);
    printf("Enter your second number: ");
    scanf("%d", &y);
    printf("Enter your third number: ");
    scanf("%d", &z);

    // Now, let's find some patterns!

    // Pattern 1: Sum of the numbers
    int sum = x + y + z;
    printf("The sum of your numbers is %d.\n", sum);

    // Pattern 2: Product of the numbers
    int product = x * y * z;
    printf("The product of your numbers is %d.\n", product);

    // Pattern 3: Average of the numbers
    double average = (double)(sum) / 3;
    printf("The average of your numbers is %.2f.\n", average);

    // Pattern 4: Maximum of the numbers
    int max = x;
    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    printf("The maximum of your numbers is %d.\n", max);

    // Pattern 5: Minimum of the numbers
    int min = x;
    if (y < min) {
        min = y;
    }
    if (z < min) {
        min = z;
    }
    printf("The minimum of your numbers is %d.\n", min);

    // Pattern 6: Is the sum of the first two numbers greater than the third number?
    int firstTwoSum = x + y;
    if (firstTwoSum > z) {
        printf("Yes, the sum of the first two numbers is greater than the third number.\n");
    } else {
        printf("No, the sum of the first two numbers is not greater than the third number.\n");
    }

    // Pattern 7: Is the product of the first two numbers divisible by the third number?
    if ((x * y) % z == 0) {
        printf("Yes, the product of the first two numbers is divisible by the third number.\n");
    } else {
        printf("No, the product of the first two numbers is not divisible by the third number.\n");
    }

    // Pattern 8: Is the average of the numbers an integer?
    if (average == (int)average) {
        printf("Yes, the average of the numbers is an integer.\n");
    } else {
        printf("No, the average of the numbers is not an integer.\n");
    }

    // Pattern 9: Is the maximum of the numbers even or odd?
    if (max % 2 == 0) {
        printf("The maximum of the numbers is even.\n");
    } else {
        printf("The maximum of the numbers is odd.\n");
    }

    // Pattern 10: Is the minimum of the numbers prime?
    int isPrime = 1;
    for (int i = 2; i <= min / 2; ++i) {
        if (min % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime == 1) {
        printf("The minimum of the numbers is prime.\n");
    } else {
        printf("The minimum of the numbers is not prime.\n");
    }

    return 0;
}