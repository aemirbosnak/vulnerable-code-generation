#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *allocate(int size)
{
    void *ptr = malloc(size);
    return ptr;
}

int main()
{
    char *buf = allocate(10);
    gets(buf);

    // Overflow the buffer
    char overflow_data[1024] = "This is an example of an overflowing buffer";
    memcpy(buf, overflow_data, sizeof(overflow_data));

    free(buf);
    return 0;
}
