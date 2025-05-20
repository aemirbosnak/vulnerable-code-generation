#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("foo.txt", "w");
    int* ptr = NULL;
    *ptr = 10;
    fprintf(file, "%d", *ptr);
    fclose(file);

    return 0;
}
