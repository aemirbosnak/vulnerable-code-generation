#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload() {
    char filename[20];
    int fileSize;
    FILE *file;

    printf("Enter the filename: ");
    if (fscanf(stdin, "%19s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return;
    }

    printf("Enter the file size: ");
    if (fscanf(stdin, "%d", &fileSize) != 1) {
        fprintf(stderr, "Error reading file size.\n");
        return;
    }

    file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char content[fileSize + 1];
    printf("Enter the file content: ");
    if (fgets(content, sizeof(content), stdin)) {
        fwrite(content, 1, fileSize, file);
    } else {
        fprintf(stderr, "Error reading file content.\n");
    }

    fclose(file);
}

int main() {
    handleFileUpload();
    return 0;
}
