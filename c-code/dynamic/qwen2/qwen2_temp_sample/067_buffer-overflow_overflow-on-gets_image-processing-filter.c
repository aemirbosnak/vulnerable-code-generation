#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void process_image(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    if (strlen(filename) >= MAX_FILENAME_LENGTH) {
        fprintf(stderr, "Error: Filename too long\n");
        return;
    }
    strcpy(buffer, filename);
    // Simulate image processing
    printf("Processing image: %s\n", buffer);
}

int main() {
    char input_filename[1024];
    printf("Enter the image filename: ");
    gets(input_filename); // Vulnerable to buffer overflow
    process_image(input_filename);
    return 0;
}
