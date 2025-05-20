//FormAI DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int p[10], q[10], ch, n, i, j, sum = 0;

    printf("Enter the number of elements in the arrays: ");
    scanf("%d", &n);

    printf("Enter the elements of the first array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the elements of the second array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    printf("Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            printf("The sum of the arrays is\n");
            for(i = 0; i < n; i++) {
                printf("%d ", p[i] + q[i]);
            }
            break;

        case 2:
            printf("The difference of the arrays is\n");
            for(i = 0; i < n; i++) {
                printf("%d ", p[i] - q[i]);
            }
            break;

        case 3:
            printf("The product of the arrays is\n");
            for(i = 0; i < n; i++) {
                printf("%d ", p[i] * q[i]);
            }
            break;

        case 4:
            printf("The quotient of the arrays is\n");
            for(i = 0; i < n; i++) {
                if(q[i] == 0) {
                    printf("Undefined ");
                } else {
                    printf("%d ", p[i] / q[i]);
                }
            }
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}