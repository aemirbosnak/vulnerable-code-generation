#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source = fopen("source.txt", "r");
    if (!source) {
        perror("Failed to open source file");
        return EXIT_FAILURE;
    }

    char destination[10];
    if (fscanf(source, "%s", destination) != 1) {
        fprintf(stderr, "Error reading from source file\n");
        fclose(source);
        return EXIT_FAILURE;
    }

    fclose(source);

    printf("Synchronization complete: %s\n", destination);

    return EXIT_SUCCESS;
}
