//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 10000

int main() {
    int num, i;
    char choice;
    double sum = 0.0;

    printf("Enter an integer between 1 and %d: ", MAX_NUM);
    scanf("%d", &num);

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%c", &choice);

    switch(choice) {
        case '1':
            for(i = 1; i <= num; i++) {
                sum += i;
            }
            printf("Result: %.0f\n", sum);
            break;
        case '2':
            for(i = num; i >= 1; i--) {
                sum += i;
            }
            printf("Result: %.0f\n", sum);
            break;
        case '3':
            for(i = 1; i <= num; i++) {
                sum *= i;
            }
            printf("Result: %.0f\n", sum);
            break;
        case '4':
            for(i = num; i >= 1; i--) {
                sum *= i;
            }
            printf("Result: %.0f\n", sum);
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}