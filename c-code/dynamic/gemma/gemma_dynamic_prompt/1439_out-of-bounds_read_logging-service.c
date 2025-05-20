#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *log_data = malloc(10);
    log_data[0] = 'a';
    log_data[1] = 'b';
    log_data[2] = 'c';

    // Out of bounds read vulnerability
    int index = 10;
    printf("%c", log_data[index]);

    free(log_data);
    return 0;
}
