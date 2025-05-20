//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n;
    double result;

    srand(time(NULL));
    n = rand() % 10 + 1;

    printf("Enter a number between 1 and %d: ", n);
    scanf("%d", &n);

    switch (n) {
        case 1:
            result = log(n);
            break;
        case 2:
            result = sqrt(n);
            break;
        case 3:
            result = pow(n, 2);
            break;
        case 4:
            result = abs(n);
            break;
        case 5:
            result = ceil(n);
            break;
        case 6:
            result = floor(n);
            break;
        case 7:
            result = sin(n);
            break;
        case 8:
            result = cos(n);
            break;
        case 9:
            result = tan(n);
            break;
        case 10:
            result = rand() % n;
            break;
        default:
            printf("Invalid input.\n");
            return 0;
    }

    printf("Result: %.2f\n", result);

    return 0;
}