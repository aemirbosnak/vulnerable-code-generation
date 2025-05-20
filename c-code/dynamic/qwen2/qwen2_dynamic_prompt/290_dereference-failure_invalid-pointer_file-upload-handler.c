#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename, const char* content) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file\n");
        return;
    }

    size_t content_length = strlen(content);
    fwrite(content, sizeof(char), content_length, file);

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char content[1024];

    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter file content: ");
    fgets(content, 1024, stdin);
    content[strcspn(content, "\n")] = '\0';

    // Simulate an invalid pointer dereference
    char* invalid_ptr = NULL;
    *invalid_ptr = 'A'; // This will cause a segmentation fault

    handle_file_upload(filename, content);

    return 0;
}
