#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10] = "Hello, world!";
    char *ptr = buffer;

    // Out-of-bounds write vulnerability
    ptr[-1] = 'A';

    printf("%s", buffer);

    return 0;
}
