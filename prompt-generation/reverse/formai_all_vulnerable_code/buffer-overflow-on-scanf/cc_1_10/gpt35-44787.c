//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int num)
{
    if(num==0)
        return 1;
    else
        return num*factorial(num-1);
}

// Function to calculate power of a number
float power(float num, int p)
{
    float result=1;
    if(p==0)
        return 1;
    else if(p>0)
    {
        for(int i=1;i<=p;i++)
        {
            result*=num;
        }
        return result;
    }
    else
    {
        for(int i=1;i<=-p;i++)
        {
            result/=num;
        }
        return result;
    }
}

int main()
{
    float x;
    int n;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);

    float sum=1.0f;
    for(int i=1;i<=n;i++)
    {
        float term=power(x,i)/factorial(i);
        if(i%2==0)
            term*=-1; // change sign of even terms
        sum+=term;
    }

    printf("The value of cos(%f) is: %f",x,sum);

    return 0;
}