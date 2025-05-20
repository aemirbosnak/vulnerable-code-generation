#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = NULL;
    str = malloc(10);
    str[0] = 'a';
    str[1] = '\0';

    printf("%s", str);

    free(str);
    return 0;
}
