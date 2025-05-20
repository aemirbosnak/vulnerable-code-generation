#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename, const char* content) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);
    strcat(buffer, ".tmp");

    FILE* file = fopen(buffer, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);

    printf("File uploaded successfully: %s\n", buffer);
}

int main() {
    char filename[1024];
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
