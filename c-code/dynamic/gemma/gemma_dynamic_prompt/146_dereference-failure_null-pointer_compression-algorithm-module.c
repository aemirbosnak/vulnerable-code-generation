#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* str = NULL;
    *str = 10;
    printf("%c", *str);
    return 0;
}
