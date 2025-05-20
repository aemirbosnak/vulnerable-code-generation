#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *arr = (char *)malloc(10);
    arr[10] = 'a';
    printf("%c", arr[10]);
    free(arr);
    return 0;
}
