#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = NULL;
    int size = 0;
    FILE *file = fopen("audio.wav", "r");

    if (file) {
        fscanf(file, "%d", &size);
        buffer = malloc(size);
        fread(buffer, size, 1, file);
        fclose(file);
    }

    if (buffer) {
        printf("%s", buffer);
        free(buffer);
    } else {
        printf("Error allocating memory");
    }

    return 0;
}
