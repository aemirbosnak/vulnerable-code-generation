#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *log_buffer = NULL;
    int log_size = 0;

    log_buffer = malloc(1024);

    // Write out of bounds (read)
    log_buffer[-1] = 'a';

    printf("Log buffer content: %s", log_buffer);

    free(log_buffer);

    return 0;
}
