#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void recoverData(const char* filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0L, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize <= 0) {
        fprintf(stderr, "File is empty\n");
        fclose(file);
        return;
    }
    fseek(file, 0L, SEEK_SET);

    char *buffer = malloc((fileSize + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    if (bytesRead != fileSize) {
        fprintf(stderr, "Failed to read file\n");
        free(buffer);
        fclose(file);
        return;
    }

    buffer[fileSize] = '\0';

    // Vulnerability: Buffer overflow if filePath is too long
    printf("%s", buffer);

    free(buffer);
    fclose(file);
}

int main() {
    char filePath[256];
    printf("Enter file path: ");
    fgets(filePath, sizeof(filePath), stdin);
    filePath[strcspn(filePath, "\n")] = '\0'; // Remove newline character

    recoverData(filePath);

    return 0;
}
