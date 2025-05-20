#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("/etc/passwd", "w");
    fwrite("This is out of bounds!", 1, 20, fp);
    fclose(fp);

    return 0;
}
