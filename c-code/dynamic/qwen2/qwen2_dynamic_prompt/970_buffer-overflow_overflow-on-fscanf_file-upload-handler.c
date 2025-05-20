#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_file_upload() {
    char filename[BUFFER_SIZE];
    FILE *file;
    
    printf("Enter the filename to upload: ");
    if (fscanf(stdin, "%s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return;
    }
    
    // Vulnerability: No bounds checking on filename length
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    printf("File uploaded successfully.\n");
    fclose(file);
}

int main() {
    handle_file_upload();
    return 0;
}
