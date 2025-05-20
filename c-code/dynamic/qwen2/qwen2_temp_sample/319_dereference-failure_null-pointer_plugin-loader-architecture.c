#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulate loading a plugin
void loadPlugin() {
    // Dereference null pointer to crash
    int* ptr = NULL;
    printf("%d\n", *ptr);
}

int main() {
    printf("Attempting to load a plugin...\n");
    loadPlugin();
    printf("Plugin loaded!\n");
    return 0;
}
