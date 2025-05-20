#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = malloc(10);
    buf[0] = 'H';
    buf[1] = 'T';
    buf[2] = 'T';
    buf[3] = 'P';
    buf[4] = 'A';
    buf[5] = 'L';
    buf[6] = 'C';
    buf[7] = 'O';
    buf[8] = 'N';
    buf[9] = '\0';

    printf("%s", buf);

    free(buf);
    return 0;
}
