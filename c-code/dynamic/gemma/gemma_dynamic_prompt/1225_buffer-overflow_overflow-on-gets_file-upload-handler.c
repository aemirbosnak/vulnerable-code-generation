#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = malloc(10);
    int length = 0;

    // Get the file data from the client
    FILE *file = fopen("uploads/test.txt", "w");
    if (file) {
        // Read the file data until the client sends a newline character
        while ((length = gets(buffer)) > 0) {
            fprintf(file, "%s", buffer);
            memset(buffer, 0, length);
        }

        fclose(file);
    }

    free(buffer);
    return 0;
}
