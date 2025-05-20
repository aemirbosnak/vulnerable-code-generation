//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int num1, num2, sum, diff, prod, quot;
    char op;
    int count = 0;
    int choice;
    int arr[10], n1, n2, temp;

    printf("Welcome to the Arithmetic Program!\n");
    printf("Please choose an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Generate random numbers\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Please enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, sum);
            break;

        case 2:
            printf("Please enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            diff = num1 - num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, diff);
            break;

        case 3:
            printf("Please enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            prod = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, prod);
            break;

        case 4:
            printf("Please enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Division by zero is not allowed.\n");
            } else {
                quot = num1 / num2;
                printf("The quotient of %d and %d is %d.\n", num1, num2, quot);
            }
            break;

        case 5:
            printf("Please enter the number of random numbers to generate:\n");
            scanf("%d", &n1);

            for(i=0; i<n1; i++) {
                num1 = rand() % 100;
                printf("%d ", num1);
            }

            printf("\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}