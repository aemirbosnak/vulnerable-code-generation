#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *log_message = NULL;
    log_message = (char *)malloc(10);

    // Out-of-bounds read vulnerability
    log_message[10] = 'A';

    printf("%s", log_message);

    free(log_message);

    return 0;
}
