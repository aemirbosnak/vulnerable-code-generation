#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    scanf("%s", buffer);

    if (strlen(buffer) > 10)
    {
        printf("Buffer overflow!\n");
    }
    else
    {
        printf("Data received: %s\n", buffer);
    }

    return 0;
}
