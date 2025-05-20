#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[10];
    FILE *file = fopen("test.txt", "r");
    int size = fread(buffer, 1, 10, file);
    fclose(file);

    buffer[size - 1] = 'A';
    printf("%s", buffer);

    return 0;
}
