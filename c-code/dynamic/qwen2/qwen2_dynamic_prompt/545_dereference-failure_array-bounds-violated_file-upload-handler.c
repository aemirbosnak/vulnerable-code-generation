#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handleFileUpload(const char* filename, const char* content) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);

    // Simulate file processing
    if (strlen(content) > 1024) {
        printf("Error: File content too large.\n");
        return;
    }

    // Vulnerability: Array bounds violation
    int index = strlen(buffer);
    while (index >= 0) {
        buffer[index] = content[index % strlen(content)];
        index--;
    }

    printf("File '%s' uploaded successfully.\n", buffer);
}

int main() {
    const char* filename = "example.txt";
    const char* content = "This is a test file content.";

    handleFileUpload(filename, content);

    return 0;
}
