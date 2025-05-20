#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buf[10];
    gets(buf);

    if (strlen(buf) > 10)
    {
        printf("Error: Buffer overflow.\n");
    }
    else
    {
        printf("The input is: %s\n", buf);
    }

    return 0;
}
