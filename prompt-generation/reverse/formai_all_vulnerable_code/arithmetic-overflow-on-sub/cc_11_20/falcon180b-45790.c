//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 1000
#define MAX_STR 100

int main() {
    srand(time(NULL));
    int num1, num2, choice;
    double result;
    char str[MAX_STR];
    char operation[MAX_STR];
    bool valid_input = true;

    printf("Welcome to the Happy Math Exercise Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Enter two numbers:\n");
            if (scanf("%d %d", &num1, &num2)!= 2) {
                valid_input = false;
            }
            if (valid_input) {
                result = num1 + num2;
                printf("Result: %d\n", result);
            }
            break;
        case 2:
            printf("Enter two numbers:\n");
            if (scanf("%d %d", &num1, &num2)!= 2) {
                valid_input = false;
            }
            if (valid_input) {
                result = num1 - num2;
                printf("Result: %d\n", result);
            }
            break;
        case 3:
            printf("Enter two numbers:\n");
            if (scanf("%d %d", &num1, &num2)!= 2) {
                valid_input = false;
            }
            if (valid_input) {
                result = num1 * num2;
                printf("Result: %d\n", result);
            }
            break;
        case 4:
            printf("Enter two numbers:\n");
            if (scanf("%d %d", &num1, &num2)!= 2) {
                valid_input = false;
            }
            if (valid_input && num2!= 0) {
                result = num1 / num2;
                printf("Result: %d\n", result);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    printf("Do you want to try another operation? (y/n)\n");
    scanf(" %[^\n]", str);
    if (strcmp(str, "y") == 0 || strcmp(str, "Y") == 0) {
        main();
    } else {
        printf("Thank you for using the Happy Math Exercise Program!\n");
        return 0;
    }
}