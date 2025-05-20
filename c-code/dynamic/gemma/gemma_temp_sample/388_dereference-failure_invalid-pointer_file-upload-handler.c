#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    FILE *file = fopen("foo.txt", "w");

    if (file)
    {
        fwrite("Hello, world!", 1, 13, file);
        fclose(file);
    }

    *ptr = 0;
    printf("Content of file: %s", ptr);

    return 0;
}
