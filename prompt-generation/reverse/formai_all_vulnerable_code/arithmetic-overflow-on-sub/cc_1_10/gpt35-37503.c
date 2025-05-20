//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include<stdio.h>

int fib(int n)
{
    if(n==0)
      return 0;
    if(n==1)
      return 1;
    return fib(n-1)+fib(n-2);
}

int fact(int n)
{
   if(n==0 || n==1)
      return 1;
   else
      return n*fact(n-1);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int pow(int n, int m)
{
   if(m==0)
      return 1;
   else
      return n*pow(n,m-1);
}

int main()
{
    int op, num1, num2;
    printf("Select an operation:\n");
    printf("1) Fibonacci\n2) Factorial\n3) Greatest Common Divisor\n4) Power\n");
    scanf("%d", &op);
    switch(op){
        case 1:
            printf("Enter a number to calculate its Fibonacci number: ");
            scanf("%d", &num1);
            printf("Fibonacci(%d) = %d", num1, fib(num1));
            break;
        case 2:
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &num1);
            printf("%d! = %d", num1, fact(num1));
            break;
        case 3:
            printf("Enter two numbers to calculate their GCD: ");
            scanf("%d%d", &num1, &num2);
            printf("GCD(%d,%d) = %d", num1, num2, gcd(num1,num2));
            break;
        case 4:
            printf("Enter a number and its power: ");
            scanf("%d%d", &num1, &num2);
            printf("%d^%d = %d", num1, num2, pow(num1,num2));
            break;
        default:
            printf("Invalid option");
            break;
    }
    return 0;
}