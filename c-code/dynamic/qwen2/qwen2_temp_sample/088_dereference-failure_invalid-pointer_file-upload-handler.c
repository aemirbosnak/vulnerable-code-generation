#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(char *filename) {
    FILE *file;
    char buffer[1024];

    // Simulate file opening
    if (strcmp(filename, "safe.txt") == 0) {
        file = fopen("safe.txt", "r");
    } else {
        file = fopen(filename, "w+");
    }

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Deliberate dereference failure
    char *ptr = NULL;
    *ptr = 'A'; // This will cause a segmentation fault

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
    filename[strcspn(filename, "\n")] = '\0';

    handle_file_upload(filename);

    return 0;
}
