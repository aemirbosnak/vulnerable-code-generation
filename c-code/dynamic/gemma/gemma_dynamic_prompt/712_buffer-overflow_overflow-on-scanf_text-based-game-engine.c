#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10];
    scanf("%s", buffer);

    if (strlen(buffer) > 10)
    {
        printf("Error: buffer overflow\n");
    }
    else
    {
        printf("Your input: %s\n", buffer);
    }

    return 0;
}
