//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main() {
    int i, j, n;
    double x, y, sum = 0;
    struct tm *t;
    time_t now;
    
    srand(time(NULL));
    now = time(NULL);
    t = localtime(&now);
    
    printf("Welcome to the Exciting World of Math!\n");
    printf("Today's date is: %d/%d/%d\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);
    
    printf("\nLet's start with some basic arithmetic operations:\n");
    for (i = 1; i <= 10; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        sum = x + y;
        printf("%d + %d = %lf\n", x, y, sum);
    }
    
    printf("\n\nNow let's move on to some advanced stuff:\n");
    for (i = 1; i <= 10; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        sum = x - y;
        printf("%d - %d = %lf\n", x, y, sum);
    }
    
    printf("\n\nLet's multiply some numbers now:\n");
    for (i = 1; i <= 10; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        sum = x * y;
        printf("%d * %d = %lf\n", x, y, sum);
    }
    
    printf("\n\nAnd finally, let's divide some numbers:\n");
    for (i = 1; i <= 10; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        sum = x / y;
        printf("%d / %d = %lf\n", x, y, sum);
    }
    
    printf("\n\nThat was exciting, wasn't it? Let's do this again sometime!\n");
    
    return 0;
}