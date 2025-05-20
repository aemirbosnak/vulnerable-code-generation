//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VALUE 1000000
#define MAX_OPERATIONS 1000000

int main() {
    int num1, num2, operation, result;
    char operation_str[10];
    int operations_performed = 0;
    int max_operations_reached = 0;
    int max_value_reached = 0;
    int current_value = 0;

    srand(time(NULL));

    // Initialize the two random numbers
    num1 = rand() % MAX_VALUE;
    num2 = rand() % MAX_VALUE;

    // Prompt the user to enter the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", operation_str);

    // Convert the operation string to integer
    switch (operation_str[0]) {
        case '+':
            operation = 1;
            break;
        case '-':
            operation = 2;
            break;
        case '*':
            operation = 3;
            break;
        case '/':
            operation = 4;
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    // Perform the operation
    switch (operation) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 == 0) {
                printf("Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            break;
    }

    // Print the result
    printf("The result is: %d\n", result);

    // Check if the maximum number of operations has been reached
    operations_performed++;
    if (operations_performed == MAX_OPERATIONS) {
        max_operations_reached = 1;
    }

    // Check if the maximum value has been reached
    if (result > MAX_VALUE) {
        max_value_reached = 1;
    }

    // Check if both conditions have been met
    if (max_operations_reached && max_value_reached) {
        printf("Congratulations! You have reached the maximum number of operations and the maximum value.\n");
        return 0;
    }

    // Continue the program
    printf("Do you want to continue? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        return 0;
    }
}