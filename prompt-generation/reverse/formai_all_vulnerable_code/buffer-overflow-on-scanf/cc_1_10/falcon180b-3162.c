//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>

//Function to perform bitwise OR operation
void bitwise_or(unsigned int a, unsigned int b)
{
    printf("Bitwise OR of %u and %u is %u\n", a, b, a|b);
}

//Function to perform bitwise AND operation
void bitwise_and(unsigned int a, unsigned int b)
{
    printf("Bitwise AND of %u and %u is %u\n", a, b, a&b);
}

//Function to perform bitwise XOR operation
void bitwise_xor(unsigned int a, unsigned int b)
{
    printf("Bitwise XOR of %u and %u is %u\n", a, b, a^b);
}

//Function to perform bitwise NOT operation
void bitwise_not(unsigned int a)
{
    printf("Bitwise NOT of %u is %u\n", a, ~a);
}

//Function to perform left shift operation
void bitwise_left_shift(unsigned int a, int b)
{
    printf("Left shift of %u by %d is %u\n", a, b, a<<b);
}

//Function to perform right shift operation
void bitwise_right_shift(unsigned int a, int b)
{
    printf("Right shift of %u by %d is %u\n", a, b, a>>b);
}

//Main function
int main()
{
    unsigned int a, b;
    int choice;

    //Input from user
    printf("Enter two unsigned integers: ");
    scanf("%u %u", &a, &b);

    //Menu-driven program for bitwise operations
    printf("\nBitwise Operations Menu:\n");
    printf("1. Bitwise OR\n");
    printf("2. Bitwise AND\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            bitwise_or(a, b);
            break;

        case 2:
            bitwise_and(a, b);
            break;

        case 3:
            bitwise_xor(a, b);
            break;

        case 4:
            bitwise_not(a);
            break;

        case 5:
            printf("Enter the number of positions to shift left: ");
            scanf("%d", &b);
            bitwise_left_shift(a, b);
            break;

        case 6:
            printf("Enter the number of positions to shift right: ");
            scanf("%d", &b);
            bitwise_right_shift(a, b);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}