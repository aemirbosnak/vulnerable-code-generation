#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void process_image(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // Buffer overflow vulnerability here
    char buffer[10];
    fscanf(file, "%s", buffer); // This can read more than 9 characters into buffer

    printf("Image dimensions: %dx%d\n", width, height);
    printf("Buffer content: %s\n", buffer);

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter image file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    process_image(filename);

    return 0;
}
