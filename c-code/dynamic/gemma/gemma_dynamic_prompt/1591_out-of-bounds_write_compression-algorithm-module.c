#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Out-of-bounds write
    data[n] = 11;

    // Print the array
    for(int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");

    return 0;
}
