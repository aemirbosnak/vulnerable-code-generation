#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    int user_id;

    // Simulate receiving data from a client
    if (sscanf(filename, "%s %d", buffer, &user_id) != 2) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    // Vulnerability: Buffer overflow due to insufficient check on filename length
    strcpy(buffer, filename);

    printf("File uploaded: %s\nUser ID: %d\n", buffer, user_id);
}

int main() {
    const char *filename = "example.txt 1234567890123456789012345678901234567890";
    handle_file_upload(filename);
    return 0;
}
