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

    // Simulate writing data to the file
    fprintf(file, "%s", content);
    fclose(file);

    printf("File uploaded successfully: %s\n", filename);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char content[1024];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter file content: ");
    fgets(content, sizeof(content), stdin);

    handle_file_upload(filename, content);

    return 0;
}
