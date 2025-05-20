#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int i = 0;
    int n = 0;

    scanf("Enter the number of filters:", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the filter parameters:");
        scanf("%s", buffer);

        // Overflow on sscanf
        buffer[1024 - 1] = 'a';

        printf("Filter applied.\n");
    }

    return 0;
}
