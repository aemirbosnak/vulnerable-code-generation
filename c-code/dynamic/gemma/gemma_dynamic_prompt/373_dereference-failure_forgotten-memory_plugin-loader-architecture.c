#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void **plugin_ptr = NULL;

    // Allocate memory for the plugin pointer
    plugin_ptr = malloc(sizeof(void *));

    // Dereference the pointer and attempt to access a memory location beyond the allocated space
    (*(plugin_ptr + 10) = 0xdeadbeef);

    return 0;
}
