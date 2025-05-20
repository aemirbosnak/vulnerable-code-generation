#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 16

void execute_plugin(const char *plugin_code) {
    char buffer[MAX_BUFFER_SIZE];
    if (sscanf(plugin_code, "%15s", buffer) == 1) {
        printf("Executing: %s\n", buffer);
        // Simulate plugin execution
        system(buffer);
    } else {
        printf("Invalid plugin code.\n");
    }
}

int main() {
    char input[256];

    printf("Enter plugin code: ");
    fgets(input, sizeof(input), stdin);

    execute_plugin(input);

    return 0;
}
