#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("/etc/passwd", "r");
    char *buf = malloc(1024);
    int len = read(fp, buf, 1024);
    printf("%s", buf);
    fclose(fp);
    free(buf);
    return 0;
}
