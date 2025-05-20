//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int a = 10, b = 5;
    float c = 2.5, d = 3.7;
    double e = 5.63, f = 9.37;

    printf("Initial values:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("c = %.2f, d = %.2f\n", c, d);
    printf("e = %.3lf, f = %.3lf\n\n", e, f);

    int sum = a + b;
    float product = c * d;
    double division = e / f;

    printf("Calculations:\n");
    printf("a + b = %d\n", sum);
    printf("c * d = %.2f\n", product);
    printf("e / f = %.3lf\n\n", division);

    int random_num = rand() % 100;
    printf("Random number between 0 and 100: %d\n\n", random_num);

    int i;
    printf("Even numbers from 1 to 50:\n");
    for (i = 2; i <= 50; i += 2) {
        printf("%d ", i);
    }
    printf("\n\n");

    int j = 5;
    printf("Factorial of 5:\n");
    for (i = j - 1; i > 0; i--) {
        j *= i;
    }
    printf("%d\n\n", j);

    int k = 20;
    printf("Numbers divisible by 3 from 20 to 40:\n");
    for (i = k; i <= 40; i++) {
        if (i % 3 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    printf("Enter a number: ");
    int input;
    scanf("%d", &input);

    if (input > 10) {
        printf("%d is greater than 10\n\n", input);
    } else if (input < 10) {
        printf("%d is less than 10\n\n", input);
    } else {
        printf("%d is equal to 10\n\n", input);
    }

    return 0;
}