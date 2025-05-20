#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    int id;

    // Simulate receiving data from a client
    if (sscanf(filename, "%s %d", buffer, &id) != 2) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    // Vulnerability: Buffer overflow due to lack of bounds checking
    printf("File: %s, ID: %d\n", buffer, id);
}

int main() {
    const char *malicious_input = "A very long filename that exceeds the buffer size by a lot 1234567890";
    handle_file_upload(malicious_input);
    return 0;
}
