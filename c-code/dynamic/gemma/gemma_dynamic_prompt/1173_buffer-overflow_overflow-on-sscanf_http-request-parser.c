#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char* ptr = buffer;
    int n = scanf(ptr, "%[^\n]%*c", buffer);

    printf("Read %d bytes: %s", n, buffer);

    return 0;
}
