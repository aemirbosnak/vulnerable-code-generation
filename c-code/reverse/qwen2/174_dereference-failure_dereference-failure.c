#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void recoverData(char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0) {
        // Simulate data processing
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] += 5; // Simple encryption
        }
        fwrite(buffer, sizeof(char), bytesRead, stdout);
    }

    fclose(file);
}

int main() {
    char filename[256];
    printf("Enter the name of the file to recover: ");
    scanf("%255s", filename);

    recoverData(filename);

    return 0;
}
