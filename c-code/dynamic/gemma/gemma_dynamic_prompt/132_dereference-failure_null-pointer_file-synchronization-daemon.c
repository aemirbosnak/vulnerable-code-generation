#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *a = NULL;
    *a = 'a';
    printf("%c", *a);
    return 0;
}
