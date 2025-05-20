#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int size)
{
    void *ptr = malloc(size);
    return ptr;
}

int main()
{
    char *buffer = my_malloc(1024);
    scanf("%s", buffer);
    buffer[1023] = 'A';
    printf("%s", buffer);
    free(buffer);
    return 0;
}
