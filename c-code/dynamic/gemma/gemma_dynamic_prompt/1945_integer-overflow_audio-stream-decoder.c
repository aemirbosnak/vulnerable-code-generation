#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int buffer[1024] = { 0 };

    for (i = 0; i < 1024; i++)
    {
        buffer[i] = 0x7FFFFFFF;
    }

    int result = 0;
    result = sum(buffer, 1024);

    printf("The result is: %d\n", result);

    return 0;
}

int sum(int *arr, int size)
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}
