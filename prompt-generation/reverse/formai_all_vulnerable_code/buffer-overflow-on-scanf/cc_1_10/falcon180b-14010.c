//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100
#define PI 3.14159265358979323846

int main() {
    int i, j, n;
    double x, y, sum = 0;
    struct tm *t;
    time_t now;

    srand(time(NULL));
    now = time(NULL);
    t = localtime(&now);

    printf("Welcome to the Math Exercise Program!\n");
    printf("Today's date is %d/%d/%d.\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
    printf("Let's start with some basic arithmetic operations.\n");

    for (i = 1; i <= 10; i++) {
        x = rand() % MAX + 1;
        y = rand() % MAX + 1;
        printf("Problem %d: %d + %d = ", i, x, y);
        if (scanf("%d", &n)!= 1 || n!= x + y) {
            printf("Incorrect answer. The correct answer is %d.\n", x + y);
        } else {
            printf("Correct answer.\n");
            sum += 1;
        }
    }

    if (sum == 10) {
        printf("Congratulations! You got all the answers correct.\n");
    } else {
        printf("You got %d out of 10 answers correct.\n", sum);
    }

    printf("\nNow let's move on to some advanced math problems.\n");

    for (i = 1; i <= 5; i++) {
        x = rand() % MAX + 1;
        y = rand() % MAX + 1;
        printf("Problem %d: %d * %d = ", i, x, y);
        if (scanf("%d", &n)!= 1 || n!= x * y) {
            printf("Incorrect answer. The correct answer is %d.\n", x * y);
        } else {
            printf("Correct answer.\n");
            sum += 1;
        }
    }

    if (sum == 5) {
        printf("Congratulations! You got all the answers correct.\n");
    } else {
        printf("You got %d out of 5 answers correct.\n", sum);
    }

    return 0;
}