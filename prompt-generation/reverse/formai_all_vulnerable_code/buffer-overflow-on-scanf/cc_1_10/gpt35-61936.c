//FormAI DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
    printf("Welcome to the Bitwise Operations command line tool!");
    printf("\n\nChoose the operation you want to perform by entering the corresponding option:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            {
                printf("\nYou have chosen Bitwise AND operation.\nEnter two binary numbers to perform AND operation on:\n");
                int num1, num2;
                scanf("%d%d", &num1, &num2);
                int and_result = num1 & num2;
                printf("Result of Bitwise AND operation of %d and %d is %d\n", num1, num2, and_result);
                break;
            }
        case 2: 
            {
                printf("\nYou have chosen Bitwise OR operation.\nEnter two binary numbers to perform OR operation on:\n");
                int num1, num2;
                scanf("%d%d", &num1, &num2);
                int or_result = num1 | num2;
                printf("Result of Bitwise OR operation of %d and %d is %d\n", num1, num2, or_result);
                break;
            }
        case 3: 
            {
                printf("\nYou have chosen Bitwise XOR operation.\nEnter two binary numbers to perform XOR operation on:\n");
                int num1, num2;
                scanf("%d%d", &num1, &num2);
                int xor_result = num1 ^ num2;
                printf("Result of Bitwise XOR operation of %d and %d is %d\n", num1, num2, xor_result);
                break;
            }
        case 4: 
            {
                printf("\nYou have chosen Bitwise NOT operation.\nEnter a binary number to perform NOT operation on:\n");
                int num;
                scanf("%d", &num);
                int not_result = ~num;
                printf("Result of Bitwise NOT operation of %d is %d\n", num, not_result); 
                break;
            }
        default:
            {
                printf("\nInvalid Input. Please enter a valid option.\n");
                break;
            } 
    }

    return 0;
}