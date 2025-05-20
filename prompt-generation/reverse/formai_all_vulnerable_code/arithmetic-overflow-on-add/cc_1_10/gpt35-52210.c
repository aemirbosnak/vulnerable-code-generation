//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

/* Function Declaration */
int addTwoNumbers(int num1, int num2);
int subTwoNumbers(int num1, int num2);
int multiplyTwoNumbers(int num1, int num2);
float divideTwoNumbers(float num1, float num2);

int main()
{
    int num1, num2;
    float fnum1, fnum2;
    int sum, sub, mul;
    float div;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    /* Addition */
    sum = addTwoNumbers(num1, num2);
    printf("%d + %d = %d\n", num1, num2, sum);

    /* Subtraction */
    sub = subTwoNumbers(num1, num2);
    printf("%d - %d = %d\n", num1, num2, sub);

    /* Multiplication */
    mul = multiplyTwoNumbers(num1, num2);
    printf("%d * %d = %d\n", num1, num2, mul);

    /* Division */
    printf("Enter two floating point numbers: ");
    scanf("%f %f", &fnum1, &fnum2);
    div = divideTwoNumbers(fnum1, fnum2);
    if (div == -1) 
    {
        printf("Cannot divide by zero.\n");
    }
    else
    {
        printf("%.2f / %.2f = %.2f\n", fnum1, fnum2, div);
    }

    return 0;
}

/* Function Definition */

int addTwoNumbers(int num1, int num2)
{
    return num1 + num2;
}

int subTwoNumbers(int num1, int num2)
{
    return num1 - num2;
}

int multiplyTwoNumbers(int num1, int num2)
{
    return num1 * num2;
}

float divideTwoNumbers(float num1, float num2)
{
    if (num2 == 0)
    {
        return -1;
    }
    else
    {
        return num1 / num2;
    }
}