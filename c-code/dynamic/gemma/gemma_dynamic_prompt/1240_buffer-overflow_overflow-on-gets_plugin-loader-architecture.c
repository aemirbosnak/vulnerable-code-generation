#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(char *plugin_path)
{
    FILE *plugin_file = fopen(plugin_path, "r");
    if (!plugin_file)
    {
        return;
    }

    char buffer[1024];
    gets(buffer); // Buffer overflow vulnerability

    fclose(plugin_file);
}

int main()
{
    plugin_loader("/path/to/plugin.so");
    return 0;
}
