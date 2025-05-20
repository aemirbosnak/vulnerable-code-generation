#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void process_image(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);
    printf("Processing image: %s\n", buffer);
}

int main() {
    char input_filename[1024];
    printf("Enter image filename: ");
    gets(input_filename); // Vulnerable to buffer overflow
    process_image(input_filename);
    return 0;
}
