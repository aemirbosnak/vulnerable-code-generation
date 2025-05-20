//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Learning Academy!\n");
    printf("Today's course is all about C Programming \n");

    int age;
    printf("Before we start, what's your age? ");
    scanf("%d", &age);

    if (age < 18) {
        printf("Oops! You must be at least 18 years old to attend this course.");
        return 1;
    }

    printf("Great! Let's begin with the basics of C programming.\n");

    // Arithmetic Operations
    int a = 10, b = 5;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);

    // Comparison Operators
    if (a == b) {
        printf("%d is equal to %d\n", a, b);
    } else if (a > b) {
        printf("%d is greater than %d\n", a, b);
    } else {
        printf("%d is less than %d\n", a, b);
    }

    // Loops
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    i = 0;
    while (i < 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i < 5);
    printf("\n");

    printf("Congratulations! You've completed the basics of C programming. Keep practicing and coding!\n");

    return 0;
}