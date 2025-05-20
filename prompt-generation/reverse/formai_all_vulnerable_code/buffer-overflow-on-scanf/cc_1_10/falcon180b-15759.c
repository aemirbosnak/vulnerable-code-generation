//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    double a, b, c, d, e, f;
    int n, m;
    struct tm time_data;
    char *time_string;

    srand(time(NULL));
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;

    printf("Welcome to the Introspective Math Program!\n");
    printf("This program will generate a random set of math problems for you to solve.\n");
    printf("Please enter your name: ");
    scanf("%s", &time_string);
    printf("Hello, %s! Let's get started.\n", time_string);

    for (int i = 0; i < n; i++) {
        a = rand() % 100 + 1;
        b = rand() % 100 + 1;
        printf("Problem #%d: %d + %d = ", i + 1, a, b);
        scanf("%d", &c);
        if (c == a + b) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", a + b);
        }
    }

    for (int j = 0; j < m; j++) {
        d = rand() % 100 + 1;
        e = rand() % 100 + 1;
        printf("Problem #%d: %d - %d = ", j + 1, d, e);
        scanf("%d", &f);
        if (f == d - e) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", d - e);
        }
    }

    printf("Congratulations! You have completed the Introspective Math Program.\n");
    printf("Thank you for playing. Goodbye!\n");

    return 0;
}