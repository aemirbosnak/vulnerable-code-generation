//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

//function to convert decimal to binary
void decimal_to_binary(int n)
{
    if(n==0)
    {
        return;
    }
    decimal_to_binary(n/2);
    printf("%d",n%2);
}

//function to perform bitwise OR operation
void bitwise_OR(int a, int b)
{
    if(a==0 && b==0)
    {
        printf("0\n");
    }
    else if(a==1 || b==1)
    {
        printf("1\n");
    }
    else if(a==2 || b==2)
    {
        printf("2\n");
    }
    else if(a==3 || b==3)
    {
        printf("3\n");
    }
    else if(a==4 || b==4)
    {
        printf("4\n");
    }
    else if(a==5 || b==5)
    {
        printf("5\n");
    }
    else if(a==6 || b==6)
    {
        printf("6\n");
    }
    else if(a==7 || b==7)
    {
        printf("7\n"); 
    }
    else if(a==8 || b==8)
    {
        printf("8\n");
    }
    else if(a==9 || b==9)
    {
        printf("9\n"); 
    }
    else if(a==10 || b==10)
    {
        printf("10\n");
    }
    else if(a==11 || b==11)
    {
        printf("11\n");
    }
    else if(a==12 || b==12)
    {
        printf("12\n");
    }
    else if(a==13 || b==13)
    {
        printf("13\n");
    }
    else if(a==14 || b==14)
    {
        printf("14\n");
    }
    else if(a==15 || b==15)
    {
        printf("15\n");
    }
}

//recursive function to perform bitwise AND operation
int bitwise_AND(int a, int b)
{
    if(b==0) 
    {
        return 0;
    }
    else if(b%2==0)
    {
        return bitwise_AND(a,b/2)*2;
    }
    else if(b%2!=0)
    {
        return bitwise_AND(a,b/2)*2+a;
    }
}

//recursive function to perform bitwise XOR operation
int bitwise_XOR(int a, int b)
{
    if(a==0 && b==0) 
    {
        return 0;
    }
    else if((a%2==0 && b%2==0) || (a%2==1 && b%2==1))
    {
        return bitwise_XOR(a/2,b/2)*2;
    }
    else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0))
    {
        return bitwise_XOR(a/2,b/2)*2+1;
    }
}

//recursive function to perform left shift operation
int left_shift(int a, int b)
{
    if(b==0) 
    {
        return a;
    }
    else
    {
        return left_shift(a*2,b-1);
    }
}

//recursive function to perform right shift operation
int right_shift(int a, int b)
{
    if(b==0) 
    {
        return a;
    }
    else
    {
        return right_shift(a/2,b-1);
    }
}

//recursive function to perform ones complement operation
int ones_complement(int a)
{
    if(a==0)
    {
        return 1;
    }
    else if(a%2==0)
    {
        return ones_complement(a/2)*2+1;
    }
    else if(a%2!=0)
    {
        return ones_complement(a/2)*2;
    }
}

//function to perform bitwise NOT operation
void bitwise_NOT(int a)
{
    int complement=ones_complement(a);
    printf("%d\n", complement);
}

int main()
{
    int a,b;
    printf("Enter two decimal numbers: ");
    scanf("%d %d",&a,&b);
    printf("Bitwise OR of %d and %d is: ",a,b);
    bitwise_OR(a,b);
    printf("Bitwise AND of %d and %d is: %d\n",a,b,bitwise_AND(a,b));
    printf("Bitwise XOR of %d and %d is: %d\n",a,b,bitwise_XOR(a,b));
    printf("Left shift of %d by %d bits is: %d\n",a,b,left_shift(a,b));
    printf("Right shift of %d by %d bits is: %d\n",a,b,right_shift(a,b));
    printf("Binary representation of %d is: ",a);
    decimal_to_binary(a);
    printf("\nBinary representation of %d is: ",b);
    decimal_to_binary(b);
    printf("Bitwise NOT of %d is: ",a);
    bitwise_NOT(a);
    return 0;
}