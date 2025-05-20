#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handleFileUpload(char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);

    // Deliberate dereference failure: using an invalid pointer
    int *invalid_ptr = NULL;
    printf("File content: ");
    while (scanf("%s", buffer) != EOF) {
        fprintf(file, "%s\n", buffer);
        // Dereferencing invalid_ptr intentionally to cause a crash
        *invalid_ptr = strlen(buffer); // This will crash as invalid_ptr is NULL
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename to upload: ");
    scanf("%255s", filename); // Safe input handling to prevent buffer overflow

    handleFileUpload(filename);

    return 0;
}
