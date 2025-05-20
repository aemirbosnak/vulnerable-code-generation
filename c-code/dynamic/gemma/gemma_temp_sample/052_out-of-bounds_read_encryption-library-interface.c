#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *key = "secret";
    char *msg = "Hello, world!";

    // Out-of-bounds read
    *(key + 10) = msg[0];

    printf("%s", key);

    return 0;
}
