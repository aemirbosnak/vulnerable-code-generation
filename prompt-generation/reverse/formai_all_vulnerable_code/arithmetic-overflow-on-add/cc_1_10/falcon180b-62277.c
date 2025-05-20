//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000

int main() {
    int num1, num2, result;
    int choice;
    int i, j;
    int arr[MAX_NUM];
    int n;

    srand(time(NULL));

    printf("Welcome to the Arithmetic World!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Do you want to generate a random array? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        for(i = 0; i < n; i++) {
            arr[i] = rand() % MAX_NUM;
        }

        printf("Random array generated:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}