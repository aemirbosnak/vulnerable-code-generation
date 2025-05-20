#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Plugin {
    void (*load)();
} Plugin;

void dangerousPlugin() {
    printf("Executing dangerous plugin!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <plugin_address>\n", argv[0]);
        return 1;
    }

    unsigned long address = strtoul(argv[1], NULL, 16);
    Plugin *plugin = (Plugin *)address;

    // Dereferencing an invalid pointer to crash the program
    plugin->load();

    return 0;
}
