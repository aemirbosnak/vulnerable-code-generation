#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_MAGIC_NUMBER 0xDEADBEEF

typedef struct Plugin {
    int magic_number;
    char name[256];
    char function_ptr[];
} Plugin;

void load_plugin(const char *path) {
    FILE *file = fopen(path, "rb");
    Plugin *plugin = (Plugin *)malloc(sizeof(Plugin) + sizeof(void *) + strlen(path));

    fread(plugin, sizeof(Plugin), 1, file);
    if (plugin->magic_number != PLUGIN_MAGIC_NUMBER) {
        printf("Invalid plugin format.\n");
        exit(1);
    }
    fread(plugin->name, strlen(path) + 1, 1, file);
    fread((void *)(plugin + 1), sizeof(void *), 1, file);

    // Vulnerability: Stack-based buffer overflow in sscanf function call.
    char input[16];
    printf("Enter function arguments (comma-separated): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", input); // Overflow into return address of load_plugin function.

    // Exploit code will overwrite the function_ptr field of the Plugin structure
    // with a malicious function address, and then call it, taking control of the program.

    // Continue loading and executing the plugin.
    // ...

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: plugin_loader <path_to_plugin>\n");
        return 1;
    }
    load_plugin(argv[1]);
    return 0;
}
