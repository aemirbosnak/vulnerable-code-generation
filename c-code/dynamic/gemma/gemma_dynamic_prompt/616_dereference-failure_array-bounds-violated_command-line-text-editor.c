#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *arr[10];
    arr[0] = "Hello, world!";
    arr[1] = "This is a string";
    arr[2] = "It has a lot of characters";

    // Array bounds violation
    arr[10] = "This string should not be here";

    printf("%s\n", arr[0]);
    printf("%s\n", arr[1]);
    printf("%s\n", arr[2]);
    printf("%s\n", arr[10]);

    return 0;
}
