#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handleFileUpload(char* filename) {
    FILE* file;
    char buffer[1024];

    // Simulate file opening
    if (strcmp(filename, "valid.txt") == 0) {
        file = fopen("valid.txt", "r");
    } else if (strcmp(filename, "malicious.txt") == 0) {
        file = fopen("malicious.txt", "r");
    } else {
        fprintf(stderr, "Invalid filename\n");
        return;
    }

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Simulate reading from file
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove newline character
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    handleFileUpload(filename);

    return 0;
}
