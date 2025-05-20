//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, sum;
    char choice;
    
    printf("Welcome to the surreal world of math!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%c", &choice);
    
    switch(choice) {
        case '1':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 + num2;
            printf("The surreal sum is: %d\n", sum);
            break;
        case '2':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 - num2;
            printf("The surreal difference is: %d\n", sum);
            break;
        case '3':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 * num2;
            printf("The surreal product is: %d\n", sum);
            break;
        case '4':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Division by zero is not allowed in the surreal world!\n");
            } else {
                sum = num1 / num2;
                printf("The surreal quotient is: %d\n", sum);
            }
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
    
    return 0;
}