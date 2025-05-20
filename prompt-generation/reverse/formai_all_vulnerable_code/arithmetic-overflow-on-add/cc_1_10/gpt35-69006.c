//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>

int main() {

    int x = 10;
    float y = 3.5;
    double z = 4.564324;
    long long a = 9876543210;
    short b = 23;

    printf("Welcome to the future of arithmetic!\n");

    printf("x + y = %.2f\n", x + y); // Output: 13.50
    printf("z - y = %.6lf\n", z - y); // Output: 1.064324
    printf("a / x = %lld\n", a / x); // Output: 987654321
    printf("y * b = %.2f\n", y * b); // Output: 80.50

    int i;

    printf("\nThe Fibonacci series upto 1000:\n");

    printf("0, 1");

    int prev = 0, current = 1, next;

    for (i = 2; i < 1000; i++) {
        next = prev + current;
        printf(", %d", next);
        prev = current;
        current = next;
    }

    printf("\n");

    float average;

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = 0;

    for (i = 0; i < 10; i++) {
        sum += array[i];
    }

    average = (float)sum / 10;

    printf("\nThe average of the array is %.2f\n", average);

    return 0;
}