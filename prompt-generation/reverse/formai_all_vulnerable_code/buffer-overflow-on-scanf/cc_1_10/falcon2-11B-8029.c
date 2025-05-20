//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    int sum = 0;
    int count = 0;
    int max = 0;
    int min = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    while (num1!= 0 && num2!= 0)
    {
        sum = num1 + num2;
        count++;

        if (sum > max)
            max = sum;

        if (sum < min)
            min = sum;

        printf("Sum = %d\n", sum);
        printf("Count = %d\n", count);

        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);
    }

    if (count == 1)
    {
        printf("Only one integer was entered!\n");
        printf("Sum = %d\n", sum);
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
    }
    else if (count == 2)
    {
        printf("Two integers were entered!\n");
        printf("Sum = %d\n", sum);
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
    }
    else
    {
        printf("More than two integers were entered!\n");
        printf("Sum = %d\n", sum);
        printf("Max = %d\n", max);
        printf("Min = %d\n", min);
    }

    return 0;
}