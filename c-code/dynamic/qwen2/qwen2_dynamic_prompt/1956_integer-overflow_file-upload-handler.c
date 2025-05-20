#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename, const char* content) {
    char buffer[1024];
    size_t total_length = strlen(filename) + strlen(content);

    // Integer overflow vulnerability
    if (total_length > sizeof(buffer)) {
        printf("Buffer overflow detected!\n");
        return;
    }

    snprintf(buffer, sizeof(buffer), "%s%s", filename, content);
    printf("File uploaded: %s\n", buffer);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char content[1024];

    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter file content: ");
    fgets(content, 1024, stdin);

    handle_file_upload(filename, content);

    return 0;
}
