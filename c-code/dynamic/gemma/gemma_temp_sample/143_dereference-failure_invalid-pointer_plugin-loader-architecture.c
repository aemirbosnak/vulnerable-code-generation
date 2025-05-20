#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* plugin_loader(char* plugin_name)
{
    void* plugin = NULL;

    // Open the plugin file
    FILE* plugin_file = fopen(plugin_name, "r");
    if (plugin_file == NULL)
    {
        return NULL;
    }

    // Allocate memory for the plugin
    plugin = malloc(1024);
    if (plugin == NULL)
    {
        fclose(plugin_file);
        return NULL;
    }

    // Read the plugin code from the file
    fread(plugin, 1024, 1, plugin_file);

    // Close the plugin file
    fclose(plugin_file);

    // Return the plugin
    return plugin;
}

int main()
{
    void* plugin = plugin_loader("plugin.so");

    // Dereference the invalid pointer
    (*(int*)plugin) = 42;

    // Free the plugin
    free(plugin);

    return 0;
}
