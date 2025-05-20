#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename) {
    char buffer[1024];
    size_t len = strlen(filename);

    // Integer overflow vulnerability
    if (len > sizeof(buffer)) {
        int offset = len - sizeof(buffer);
        memmove(buffer, &filename[offset], sizeof(buffer));
    } else {
        strcpy(buffer, filename);
    }

    printf("File uploaded: %s\n", buffer);
}

int main() {
    const char* malicious_filename = "A very long string that will cause an overflow";
    handle_file_upload(malicious_filename);
    return 0;
}
