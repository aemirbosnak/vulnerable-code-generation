//FormAI DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 * Donald Knuth style math exercise program
 */

int main(void) {
    srand((unsigned) time(NULL));   // Seed the random number generator with current time
    int a, b, c, d, e, f, answer;
    
    // Problem 1
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    printf("%d + %d = ?", a, b);
    scanf("%d", &answer);
    if (answer != a + b) {
        printf("Incorrect. The correct answer is %d.\n", a + b);
    } else {
        printf("Correct!\n");
    }
    
    // Problem 2
    c = rand() % 10 + 1;
    d = rand() % 10 + 1;
    printf("%d - %d = ?", c, d);
    scanf("%d", &answer);
    if (answer != c - d) {
        printf("Incorrect. The correct answer is %d.\n", c - d);
    } else {
        printf("Correct!\n");
    }
    
    // Problem 3
    e = rand() % 10 + 1;
    f = rand() % 10 + 1;
    printf("%d * %d = ?", e, f);
    scanf("%d", &answer);
    if (answer != e * f) {
        printf("Incorrect. The correct answer is %d.\n", e * f);
    } else {
        printf("Correct!\n");
    }
    
    // Problem 4
    int num = rand() % 100 + 1;
    printf("What is the square root of %d? (rounded to nearest integer):\n", num);
    scanf("%d", &answer);
    if (answer != (int) round(sqrt(num))) {
        printf("Incorrect. The correct answer is %d.\n", (int) round(sqrt(num)));
    } else {
        printf("Correct!\n");
    }
    
    return 0;
}