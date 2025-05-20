#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Simulate a buffer overflow by writing more data than the allocated space
    char buffer[10];
    strcpy(buffer, content);

    // Dereference an invalid pointer
    int* invalid_ptr = NULL;
    *invalid_ptr = 42; // This will cause a segmentation fault

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char content[1024];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter file content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = '\0';

    handle_file_upload(filename, content);

    return 0;
}
