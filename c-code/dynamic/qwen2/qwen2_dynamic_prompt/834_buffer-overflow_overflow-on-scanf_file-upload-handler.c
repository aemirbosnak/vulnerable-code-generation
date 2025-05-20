#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 128

void handle_file_upload(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    printf("Uploading file: %s\n", filename);
    // Vulnerability: No bounds checking on the input length
    scanf("%s", buffer);
    printf("File uploaded successfully: %s\n", buffer);
}

int main() {
    const char* filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
