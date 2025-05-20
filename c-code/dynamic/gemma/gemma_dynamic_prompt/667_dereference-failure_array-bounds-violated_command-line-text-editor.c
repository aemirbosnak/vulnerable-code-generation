#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int i = 0;

    arr = malloc(10 * sizeof(char *));
    arr[0] = "Hello, world!";
    arr[1] = "This is a string.";
    arr[2] = NULL;

    // This line will cause a dereference failure
    arr[10] = "This is an out-of-bounds element.";

    printf("%s\n", arr[0]);
    printf("%s\n", arr[1]);
    printf("%s\n", arr[2]);

    free(arr);

    return 0;
}
