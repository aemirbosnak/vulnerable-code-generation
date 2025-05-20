#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGIN_NAME_LENGTH 100
#define PLUGIN_LOAD_ADDRESS 0x8048000

typedef void (*plugin_func_t)(void);

void load_plugin(char *name) {
    char buffer[MAX_PLUGIN_NAME_LENGTH];
    plugin_func_t plugin_ptr;

    printf("Enter plugin name: ");
    scanf("%s", buffer);

    plugin_ptr = (plugin_func_t)strtoul(buffer, NULL, 16);
    plugin_ptr();
}

void dangerous_plugin_1(void) {
    printf("Executing dangerous plugin 1\n");
    system("/bin/ls -la");
}

void dangerous_plugin_2(void) {
    printf("Executing dangerous plugin 2\n");
    system("/bin/rm -rf /");
}

int main() {
    load_plugin("dangerous_plugin_1");
    load_plugin("dangerous_plugin_2");

    return 0;
}
