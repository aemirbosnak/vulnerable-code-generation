#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("/etc/passwd", "r");
    char buffer[1024];
    int offset = rand() % 1024;
    size_t read_size = read(fp, buffer, offset) + 1;
    printf("%s", buffer);
    fclose(fp);
    return 0;
}
