//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, n, choice;
    double x, y, z, sum = 0;
    char ch;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the arithmetic series:\n");
    for(i=0; i<n; i++) {
        scanf("%lf", &x);
        sum += x;
    }

    printf("The sum of the arithmetic series is: %.2lf\n", sum);

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &x, &y);
            z = x + y;
            printf("%.2lf + %.2lf = %.2lf\n", x, y, z);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &x, &y);
            z = x - y;
            printf("%.2lf - %.2lf = %.2lf\n", x, y, z);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &x, &y);
            z = x * y;
            printf("%.2lf * %.2lf = %.2lf\n", x, y, z);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &x, &y);
            if(y == 0) {
                printf("Division by zero is not allowed.\n");
            } else {
                z = x / y;
                printf("%.2lf / %.2lf = %.2lf\n", x, y, z);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}