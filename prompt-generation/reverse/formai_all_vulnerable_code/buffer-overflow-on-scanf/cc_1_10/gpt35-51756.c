//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include<stdio.h>

void displayBits(unsigned int);
void bitwiseAnd(unsigned int, unsigned int);
void bitwiseOr(unsigned int, unsigned int);
void bitwiseXor(unsigned int, unsigned int);
void bitwiseNot(unsigned int);
void leftShift(unsigned int, int);
void rightShift(unsigned int, int);

int main()
{
    unsigned int num1, num2, ans;
    int shift;

    printf("Enter a number: ");
    scanf("%u", &num1);
    printf("Enter another number: ");
    scanf("%u", &num2);
    printf("Enter a number of times to shift: ");
    scanf("%d", &shift);

    printf("\nEntered numbers:\n");
    printf("%u in binary: ", num1);
    displayBits(num1);
    printf("%u in binary: ", num2);
    displayBits(num2);

    printf("\nBitwise AND: %u & %u = ", num1, num2);
    bitwiseAnd(num1, num2);

    printf("Bitwise OR: %u | %u = ", num1, num2);
    bitwiseOr(num1, num2);

    printf("Bitwise XOR: %u ^ %u = ", num1, num2);
    bitwiseXor(num1, num2);

    printf("Bitwise NOT of %u: ", num1);
    bitwiseNot(num1);

    printf("Left shift by %d of %u: ", shift, num1);
    leftShift(num1, shift);

    printf("Right shift by %d of %u: ", shift, num1);
    rightShift(num1, shift);

    return 0;
}

void displayBits(unsigned int num)
{
    unsigned int mask = 1 << 31;

    for(int i = 1; i <= 32; i++)
    {
        putchar(num & mask ? '1' : '0');
        num <<= 1;

        if(i % 8 == 0)
            putchar(' ');
    }

    putchar('\n');
}

void bitwiseAnd(unsigned int num1, unsigned int num2)
{
    unsigned int ans = num1 & num2;
    displayBits(ans);
}

void bitwiseOr(unsigned int num1, unsigned int num2)
{
    unsigned int ans = num1 | num2;
    displayBits(ans);
}

void bitwiseXor(unsigned int num1, unsigned int num2)
{
    unsigned int ans = num1 ^ num2;
    displayBits(ans);
}

void bitwiseNot(unsigned int num)
{
    unsigned int ans = ~num;
    displayBits(ans);
}

void leftShift(unsigned int num, int shift)
{
    unsigned int ans = num << shift;
    displayBits(ans);
}

void rightShift(unsigned int num, int shift)
{
    unsigned int ans = num >> shift;
    displayBits(ans);
}