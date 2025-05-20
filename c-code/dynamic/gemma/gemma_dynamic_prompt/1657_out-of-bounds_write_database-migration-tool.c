#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("test.txt", "w");
    char buffer[1024];
    buffer[1024 - 1] = 'a';
    fwrite(buffer, 1, 1024, file);
    fclose(file);
    return 0;
}
