#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    char data[1024];

    printf("Enter data: ");
    fscanf(stdin, "%s", buffer);

    // Overflow on fscanf
    memcpy(data, buffer, 1024);

    // Do something with the data
    printf("Data: %s", data);

    return 0;
}
