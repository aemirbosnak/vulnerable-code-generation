#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void handleFileUpload(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    printf("Uploading file: %s\n", filename);
    // Vulnerability: No bounds checking on the input length
    scanf("%s", buffer);
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    const char* filename = "example.txt";
    handleFileUpload(filename);
    return 0;
}
