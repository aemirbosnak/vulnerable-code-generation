#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pInt = NULL;
    *pInt = 10;
    printf("%d", *pInt);
    free(pInt);
    return 0;
}
