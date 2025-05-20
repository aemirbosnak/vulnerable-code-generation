#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("/tmp/log.txt", "w");
    char buf[1024];

    // Write beyond the buffer size
    buf[1024] = 'a';
    fwrite(buf, 1024, 1, fp);

    fclose(fp);

    return 0;
}
