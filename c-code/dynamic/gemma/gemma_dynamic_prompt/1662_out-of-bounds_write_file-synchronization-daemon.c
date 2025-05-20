#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    FILE *fp = fopen("/etc/passwd", "w");
    write(fileno(fp), "Hello, world!", 13);
    fclose(fp);

    return 0;
}
