//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Need time.h to seed the random number generator

int main(void) {
    int a, b, c, d, x, y;

    printf("Welcome to the C Math Exercise Example Program!\n");
    printf("Please solve the following equation for x and y:\n");
    printf("a + b = x\n");
    printf("c - d = y\n");

    // Seed the random number generator
    srand(time(NULL));

    // Generate four random integers between 1 and 10
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    c = rand() % 10 + 1;
    d = rand() % 10 + 1;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    // Calculate x and y using the generated random integers
    x = a + b;
    y = c - d;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    // Ask the user to solve the equation and enter their answer
    printf("Please enter your answer for x: ");
    int user_answer_x;
    scanf("%d", &user_answer_x);

    printf("Please enter your answer for y: ");
    int user_answer_y;
    scanf("%d", &user_answer_y);

    // Check if the user's answers match the correct answers
    if (user_answer_x == x && user_answer_y == y) {
        printf("Congratulations, your answers are correct!\n");
    } else {
        printf("Sorry, your answers are incorrect. The correct answers are x = %d and y = %d.\n", x, y);
    }

    return 0;
}