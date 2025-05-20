#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req_len = 1000000000;
    int* buf = (int*)malloc(req_len);

    // Overflow the int with a large number
    buf[0] = 2147483647;

    // Do something with the buffer
    printf("Content of the buffer: %s", buf);

    free(buf);
    return 0;
}
