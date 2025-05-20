//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>

int main() {
    printf("Are you brave enough to face this program?\n");
    printf("Let's conquer the world of science together!\n");

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // We need to calculate the factorial of num
    int factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    printf("Factorial of %d is %d\n", num, factorial);

    // Now let's calculate the sum of all even numbers till num
    int sum = 0;
    for (int i = 2; i <= num; i += 2) {
        sum += i;
    }

    printf("Sum of all even numbers till %d is %d\n", num, sum);

    // Let's find the average of first 10 prime numbers
    int count = 0;
    int prime = 2;
    double average = 0;
    while (count < 10) {
        int flag = 0;
        for (int i = 2; i <= prime / 2; i++) {
            if (prime % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            average += prime;
            count++;
        }
        prime++;
    }
    average /= 10;

    printf("Average of first 10 prime numbers is %.2f\n", average);

    printf("Keep the scientific spirit alive! Good job!\n");

    return 0;
}