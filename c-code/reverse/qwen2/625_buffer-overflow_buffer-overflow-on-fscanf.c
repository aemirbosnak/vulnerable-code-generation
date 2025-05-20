#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[10];

    // Writing to a file
    file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fprintf(file, "Hello, world!\n");
    fclose(file);

    // Reading from a file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fgets(buffer, sizeof(buffer), file);
    printf("%s", buffer);
    fclose(file);

    // Intentional buffer overflow
    strcpy(buffer, "This is a very long string that will cause a buffer overflow");

    return EXIT_SUCCESS;
}
