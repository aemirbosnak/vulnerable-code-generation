//FormAI DATASET v1.0 Category: Funny ; Style: portable
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    if (num1 > 100 && num2 > 100)
    {
        printf("Woah! Both numbers are greater than 100!\n");
    }
    else if (num1 > 100 || num2 > 100)
    {
        printf("One of the numbers is greater than 100!\n");
    }
    else
    {
        printf("Neither of the numbers is greater than 100!\n");
    }

    int i, j;
    for (i = 1; i <= 10; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    int count = 0;
    while (count < 5)
    {
        printf("I love programming!\n");
        count++;
    }

    char str[] = "Hello World";
    int len = sizeof(str) / sizeof(str[0]);
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    int arr[] = { 2, 4, 6, 8, 10 };
    int sum = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        sum += arr[i];
    }
    printf("The sum of the array is: %d\n", sum);

    return 0;
}