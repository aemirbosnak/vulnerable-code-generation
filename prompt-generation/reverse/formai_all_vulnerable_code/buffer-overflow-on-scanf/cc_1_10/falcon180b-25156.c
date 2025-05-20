//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, m, n, sum = 0;
    float avg;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of integers to generate
    printf("Enter the number of integers to generate: ");
    scanf("%d", &n);

    // Generate n random integers between 1 and 1000
    for (i = 0; i < n; i++) {
        m = rand() % 1000 + 1;
        printf("%d ", m);
    }
    printf("\n");

    // Prompt the user for the operation to perform
    printf("Enter the operation to perform (+, -, *, /): ");
    scanf(" %c", &choice);

    // Perform the operation and output the result
    switch (choice) {
        case '+':
            for (i = 0; i < n; i++) {
                sum += m;
            }
            printf("The sum is %d\n", sum);
            break;
        case '-':
            for (i = 0; i < n; i++) {
                sum -= m;
            }
            printf("The difference is %d\n", sum);
            break;
        case '*':
            for (i = 0; i < n; i++) {
                sum *= m;
            }
            printf("The product is %.2f\n", sum);
            break;
        case '/':
            for (i = 0; i < n; i++) {
                sum += m;
            }
            avg = sum / n;
            printf("The average is %.2f\n", avg);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
}