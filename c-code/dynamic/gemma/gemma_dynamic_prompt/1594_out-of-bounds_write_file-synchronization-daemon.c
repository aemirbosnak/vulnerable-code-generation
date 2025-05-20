#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file = fopen("/tmp/test.txt", "w");
    fwrite("Hello, world!", 1, 13, file);
    fclose(file);

    FILE* file2 = fopen("/tmp/test.txt", "r");
    char buffer[1024];
    fread(buffer, 1, 1024, file2);
    printf("%s", buffer);
    fclose(file2);

    return 0;
}
