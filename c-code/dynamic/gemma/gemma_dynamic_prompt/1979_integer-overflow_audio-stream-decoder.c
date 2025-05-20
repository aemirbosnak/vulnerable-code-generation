#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int buf[10] = { 0 };

    // Malformed data to trigger overflow
    char data[] = { 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80 };

    // Attempt to decode data
    for (i = 0; i < 10; i++)
    {
        int value = data[i] - 0x80;
        buf[i] = value * value;
    }

    // Print decoded data
    for (i = 0; i < 10; i++)
    {
        printf("%d ", buf[i]);
    }

    return 0;
}
