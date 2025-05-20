#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 10

void handle_file_upload(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    FILE* file;

    // Simulate file upload by reading user input
    printf("Enter filename: ");
    if (fscanf(stdin, "%s", buffer) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return;
    }

    // Attempt to open the file with the provided name
    file = fopen(buffer, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Read from the file
    char content[256];
    while (fgets(content, sizeof(content), file)) {
        printf("%s", content);
    }

    fclose(file);
}

int main() {
    handle_file_upload(NULL); // Intentionally pass NULL to demonstrate vulnerability
    return 0;
}
