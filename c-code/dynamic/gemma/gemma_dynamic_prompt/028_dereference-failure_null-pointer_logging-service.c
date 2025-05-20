#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **arr = NULL;
    arr = (char**)malloc(10);
    *arr = "Hello, world!";

    printf("%s", *arr);

    free(arr);
    return 0;
}
