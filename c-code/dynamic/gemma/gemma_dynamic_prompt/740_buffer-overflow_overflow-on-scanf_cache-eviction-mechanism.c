#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **cache = NULL;
    int size = 0;
    char buf[1024];

    scanf("%d", &size);

    cache = malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++)
    {
        cache[i] = malloc(1024);
    }

    for (int i = 0; i < size; i++)
    {
        scanf("%s", cache[i]);
    }

    printf("Cache contents:");

    for (int i = 0; i < size; i++)
    {
        printf("%s ", cache[i]);
    }

    return 0;
}
