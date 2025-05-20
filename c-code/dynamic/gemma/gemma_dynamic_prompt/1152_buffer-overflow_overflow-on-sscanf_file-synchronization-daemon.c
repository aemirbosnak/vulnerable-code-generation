#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    scanf("%s", buffer);

    // Overflow the buffer
    char overflow_data[10000] = "This is a large amount of data that will cause a buffer overflow";
    memcpy(buffer, overflow_data, 10000);

    printf("The data is: %s", buffer);

    return 0;
}
