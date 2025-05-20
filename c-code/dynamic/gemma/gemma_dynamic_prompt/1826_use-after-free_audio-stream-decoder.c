#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char *buffer = malloc(1024);
    int len = read(0, buffer, 1024);
    if (len > 0)
    {
        free(buffer);
        printf("%s", buffer);
    }
    return 0;
}
