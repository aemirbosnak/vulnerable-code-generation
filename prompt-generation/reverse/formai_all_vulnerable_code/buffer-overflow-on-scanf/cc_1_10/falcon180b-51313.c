//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIT_COUNT 32
#define MAX_VALUE (1 << BIT_COUNT) - 1

// Function to print a binary number
void print_binary(unsigned int num)
{
    char binary[BIT_COUNT + 1] = {0};
    int i;

    for (i = 0; i < BIT_COUNT; i++)
    {
        binary[BIT_COUNT - i - 1] = '0' + (num & 1);
        num >>= 1;
    }

    printf("%s\n", binary);
}

// Function to perform bitwise operations on two numbers
void bitwise_operations(int num1, int num2, int operation)
{
    unsigned int result;

    switch (operation)
    {
        case 0: // AND operation
            result = num1 & num2;
            printf("Result: ");
            print_binary(result);
            break;

        case 1: // OR operation
            result = num1 | num2;
            printf("Result: ");
            print_binary(result);
            break;

        case 2: // XOR operation
            result = num1 ^ num2;
            printf("Result: ");
            print_binary(result);
            break;

        case 3: // NOT operation
            result = ~num1;
            printf("Result: ");
            print_binary(result);
            break;

        case 4: // Left shift operation
            result = num1 << num2;
            printf("Result: ");
            print_binary(result);
            break;

        case 5: // Right shift operation
            result = num1 >> num2;
            printf("Result: ");
            print_binary(result);
            break;

        default:
            printf("Invalid operation!\n");
            break;
    }
}

// Function to generate a random number
int generate_random_number()
{
    return rand() % MAX_VALUE;
}

int main()
{
    srand(time(NULL));

    int num1, num2, operation;

    // Get user input for two numbers and operation
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (0-5): ");
    scanf("%d", &operation);

    // Perform bitwise operation and display result
    bitwise_operations(num1, num2, operation);

    return 0;
}