//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

int main() {
    int num1, num2;
    int choice;
    char input[MAX_NUM];

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Enter 1 for addition.\n");
    printf("Enter 2 for subtraction.\n");
    printf("Enter 3 for multiplication.\n");
    printf("Enter 4 for division.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers separated by a space: ");
            scanf("%s", input);
            num1 = atoi(input);

            printf("Enter another number: ");
            scanf("%s", input);
            num2 = atoi(input);

            printf("%.0f + %.0f = %.0f\n", num1, num2, num1 + num2);
            break;

        case 2:
            printf("Enter two numbers separated by a space: ");
            scanf("%s", input);
            num1 = atoi(input);

            printf("Enter another number: ");
            scanf("%s", input);
            num2 = atoi(input);

            printf("%.0f - %.0f = %.0f\n", num1, num2, num1 - num2);
            break;

        case 3:
            printf("Enter two numbers separated by a space: ");
            scanf("%s", input);
            num1 = atoi(input);

            printf("Enter another number: ");
            scanf("%s", input);
            num2 = atoi(input);

            printf("%.0f * %.0f = %.0f\n", num1, num2, num1 * num2);
            break;

        case 4:
            printf("Enter two numbers separated by a space: ");
            scanf("%s", input);
            num1 = atoi(input);

            printf("Enter another number: ");
            scanf("%s", input);
            num2 = atoi(input);

            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                printf("%.0f / %.0f = %.2f\n", num1, num2, (float)num1 / num2);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}