#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int (*plugin_func_ptr)(int) = NULL;
    char **plugin_data = NULL;
    int plugin_index = 0;

    // Allocate memory for plugin data
    plugin_data = malloc(1024);

    // Access invalid memory beyond the allocated space
    plugin_func_ptr = (int (*)(int))(*(plugin_data + 1024));

    // Call the plugin function through the invalid pointer
    (*plugin_func_ptr)(plugin_index);

    return 0;
}
