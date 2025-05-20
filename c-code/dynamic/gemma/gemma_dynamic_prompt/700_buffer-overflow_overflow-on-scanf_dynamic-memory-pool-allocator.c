#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **mem_pool = NULL;
    int mem_size = 0;

    char buffer[1024];

    scanf("Enter the size of the memory pool: ", buffer);
    mem_size = atoi(buffer);

    mem_pool = (char **)malloc(mem_size * sizeof(char *));

    for (int i = 0; i < mem_size; i++)
    {
        mem_pool[i] = NULL;
    }

    free(mem_pool);

    return 0;
}
