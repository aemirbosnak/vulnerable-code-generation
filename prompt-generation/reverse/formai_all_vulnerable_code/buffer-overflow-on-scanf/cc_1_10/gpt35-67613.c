//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

void print_menu();
void get_numbers(int *numbers, int *count);
void arithmetic_operations(int *numbers, int count);

int main()
{
    int numbers[MAX_NUMBERS];
    int count = 0;
    print_menu();
    get_numbers(numbers, &count);
    arithmetic_operations(numbers, count);
    return 0;
}

void print_menu()
{
    printf("Welcome to Arithmetic Operations Program.\n");
    printf("You can perform the following operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter '0' to exit.\n");
}

void get_numbers(int *numbers, int *count)
{
    int number;
    printf("Enter the numbers you want to perform operations on (maximum %d):\n", MAX_NUMBERS);
    printf("Enter '0' to finish.\n");
    do {
        scanf("%d", &number);
        if (number != 0) {
            numbers[*count] = number;
            (*count)++;
        }
    } while ((*count) < MAX_NUMBERS && number != 0);
}

void arithmetic_operations(int *numbers, int count)
{
    int option;
    int i;
    int result;
    printf("Enter the operation you want to perform (0 to exit):\n");
    scanf("%d", &option);
    switch(option) {
        case 0:
            printf("Exiting.\n");
            break;
        case 1:
            result = 0;
            for (i = 0; i < count; i++) {
                result += numbers[i];
            }
            printf("The result of addition is %d.\n", result);
            arithmetic_operations(numbers, count);
            break;
        case 2:
            result = numbers[0];
            for (i = 1; i < count; i++) {
                result -= numbers[i];
            }
            printf("The result of subtraction is %d.\n", result);
            arithmetic_operations(numbers, count);
            break;
        case 3:
            result = 1;
            for (i = 0; i < count; i++) {
                result *= numbers[i];
            }
            printf("The result of multiplication is %d.\n", result);
            arithmetic_operations(numbers, count);
            break;
        case 4:
            result = numbers[0];
            for (i = 1; i < count; i++) {
                if (numbers[i] == 0) {
                    printf("Cannot divide by zero!\n");
                    arithmetic_operations(numbers, count);
                    return;
                }
                result /= numbers[i];
            }
            printf("The result of division is %d.\n", result);
            arithmetic_operations(numbers, count);
            break;
        default:
            printf("Invalid option! Try again.\n");
            arithmetic_operations(numbers, count);
            break;
    }
}