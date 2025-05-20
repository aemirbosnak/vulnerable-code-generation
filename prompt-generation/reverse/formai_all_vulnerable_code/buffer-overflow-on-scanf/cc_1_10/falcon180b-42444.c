//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

// function to calculate the number of set bits in a number
int countBits(unsigned int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n &= (n-1);
    }
    return count;
}

int main()
{
    int i,j,k;
    char str[MAX];
    unsigned int num;

    // get input string from user
    printf("Enter a string: ");
    scanf("%s",str);

    // convert string to uppercase
    for(i=0;i<strlen(str);i++)
    {
        str[i] = toupper(str[i]);
    }

    // get input number from user
    printf("Enter a number: ");
    scanf("%d",&num);

    // count the number of set bits in the number
    int count = countBits(num);

    // print the result
    printf("The number of set bits in %d is %d\n",num,count);

    // count the number of vowels in the string
    int vowelCount = 0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowelCount++;
        }
    }

    // print the result
    printf("The number of vowels in %s is %d\n",str,vowelCount);

    return 0;
}