#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int size)
{
    return malloc(size);
}

void my_free(void *ptr)
{
    free(ptr);
}

int main()
{
    char *buffer = my_malloc(10);
    char *overflow_buffer = my_malloc(10);

    printf("Enter a string: ");
    scanf("%s", buffer);

    // Overflow on sscanf
    overflow_buffer = buffer;
    scanf("%s", overflow_buffer);

    my_free(buffer);
    my_free(overflow_buffer);

    return 0;
}
