#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int log_size = 100;
    int data_size = 10 * 1024;
    int* data = malloc(data_size);

    // Overflow the integer variable 'log_size'
    log_size = log_size + data_size * 2;

    printf("Log size: %d\n", log_size);

    free(data);
    return 0;
}
