#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    FILE* file = fopen("text.txt", "r");
    size_t size = 0;

    if (file)
    {
        while (fgets(buffer, 1024, file) != NULL)
        {
            size++;
        }
        fclose(file);
    }

    printf("The file has %d lines.", size);

    return 0;
}
