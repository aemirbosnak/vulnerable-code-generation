//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int isPrime(int num)
{
    if(num == 1 || num == 0)
    {
        return 0;
    }

    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int num,i;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the number of prime numbers you want to generate:");
    scanf("%d",&num);

    if(num <= 0)
    {
        printf("Invalid input!");
    }
    else
    {
        int primeArray[num];
        primeArray[0] = 2;
        int count = 1;
        int currentNum = 3;
        while(count < num)
        {
            int isPrimeFlag = isPrime(currentNum);
            if(isPrimeFlag == 1)
            {
                primeArray[count] = currentNum;
                count++;
            }
            currentNum++;
        }
        printf("Here are your %d prime numbers:\n",num);
        for(i = 0; i < num; i++)
        {
            printf("%d ",primeArray[i]);
        }
    }
    return 0;
}