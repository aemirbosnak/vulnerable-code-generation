#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[10];
    scanf("%s", buf);

    if (strlen(buf) > 10)
    {
        printf("Error: buffer overflow!\n");
    }
    else
    {
        printf("Data: %s\n", buf);
    }

    return 0;
}
