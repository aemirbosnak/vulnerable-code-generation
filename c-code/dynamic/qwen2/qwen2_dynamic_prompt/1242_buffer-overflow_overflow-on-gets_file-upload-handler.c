#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    gets(buffer); // Vulnerable to buffer overflow
    printf("File uploaded: %s\n", buffer);
}

int main() {
    const char* filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
