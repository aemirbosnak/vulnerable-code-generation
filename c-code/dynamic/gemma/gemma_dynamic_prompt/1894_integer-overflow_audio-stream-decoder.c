#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int n = 0;
    int data = 0;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the sample value: ");
        scanf("%d", &data);

        // Overflow the int data type
        data = data * data * data;

        printf("The decoded sample value is: %d\n", data);
    }

    return 0;
}
