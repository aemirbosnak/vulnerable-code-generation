#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char destination[1024];
    char source[1024];

    printf("Enter source file path: ");
    if (!fgets(source, sizeof(source), stdin)) {
        return 1;
    }

    printf("Enter destination file path: ");
    if (!fgets(destination, sizeof(destination), stdin)) {
        return 1;
    }

    // Buffer overflow vulnerability here with fscanf
    file = fopen(source, "r");
    if (file) {
        fscanf(file, "%s", destination);  // Overflow if filename is too large
        fclose(file);
    }

    printf("Synchronization complete.\n");

    return 0;
}
