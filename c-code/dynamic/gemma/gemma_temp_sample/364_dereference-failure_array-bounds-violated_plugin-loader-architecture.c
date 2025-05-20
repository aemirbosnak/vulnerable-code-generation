#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(char **plugin_array, int plugin_count)
{
    for (int i = 0; i < plugin_count; i++)
    {
        (*plugin_array)[i] = malloc(1024);
    }

    for (int i = 0; i < plugin_count; i++)
    {
        free((*plugin_array)[i]);
    }
}

int main()
{
    char **plugin_array = NULL;
    int plugin_count = 10;

    plugin_loader(plugin_array, plugin_count);

    return 0;
}
