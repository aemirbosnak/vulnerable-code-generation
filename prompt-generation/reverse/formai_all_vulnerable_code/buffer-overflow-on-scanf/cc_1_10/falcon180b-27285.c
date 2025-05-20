//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n, i, j, k, l, m;
    double a, b, c, d, e, f, g, h, x, y, z, w, p, q, r, s, t, u, v;
    char ch;
    printf("Welcome to the Exciting World of Mathematics!\n");
    printf("This program will generate a random math problem for you to solve.\n");
    printf("Are you ready? (y/n) ");
    scanf("%c", &ch);
    srand(time(0));
    n = rand() % 4 + 1; // Generate a random number between 1 and 4
    switch(n) {
        case 1:
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
            printf("Solve the following equation: %d + %d =?\n", a, b);
            scanf("%lf", &x);
            if(x == a + b) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
        case 2:
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            printf("Solve the following equation: %d * %d =?\n", a, b);
            scanf("%lf", &x);
            if(x == a * b) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
        case 3:
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            printf("Solve the following equation: %d / %d =?\n", a, b);
            scanf("%lf", &x);
            if(x == a / b) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
        case 4:
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
            c = rand() % 10 + 1;
            printf("Solve the following equation: %d + %d + %d =?\n", a, b, c);
            scanf("%lf", &x);
            if(x == a + b + c) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
            break;
    }
    return 0;
}