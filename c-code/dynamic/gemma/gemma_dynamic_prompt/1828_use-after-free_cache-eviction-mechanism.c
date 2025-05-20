#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *cache_entry = malloc(1024);
    free(cache_entry);
    cache_entry = NULL;

    cache_entry = malloc(1024);
    cache_entry = NULL;

    return 0;
}
