#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *arr[10];
    arr[0] = "Hello, world!";
    arr[1] = NULL;

    // Deliberate array bounds violation
    char *ptr = arr[2];

    // Print the value of the dereferenced pointer
    printf("%s", ptr);

    return 0;
}
