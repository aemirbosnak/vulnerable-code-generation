#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Plugin {
    char name[10];
    void (*load)();
} Plugin;

void plugin1_load() {
    printf("Plugin 1 loaded.\n");
}

void plugin2_load() {
    printf("Plugin 2 loaded.\n");
}

Plugin plugins[] = {
    {"plugin1", plugin1_load},
    {"plugin2", plugin2_load},
    {"unknown", NULL} // Dereference failure intentionally placed here
};

int main() {
    for (int i = 0; plugins[i].name[0] != '\0'; i++) {
        plugins[i].load();
    }
    return 0;
}
