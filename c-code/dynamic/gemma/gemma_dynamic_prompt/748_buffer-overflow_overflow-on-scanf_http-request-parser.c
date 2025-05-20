#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    scanf("%s", buffer);

    if (strlen(buffer) > 1024)
    {
        printf("Error: buffer overflow\n");
    }
    else
    {
        printf("Data: %s\n", buffer);
    }

    return 0;
}
