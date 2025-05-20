#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handle_upload(const char* file_path, const char* buffer, size_t size) {
    FILE* file = fopen(file_path, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    // Simulate an out-of-bounds write vulnerability
    fwrite(buffer, 1, size + 50, file); // Writing more data than allocated
    
    fclose(file);
}

int main() {
    char buffer[BUFFER_SIZE];
    const char* file_path = "/tmp/uploaded_file";
    
    // Read input into buffer
    printf("Enter data to upload: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    // Handle the file upload with potential out-of-bounds write
    handle_upload(file_path, buffer, strlen(buffer));
    
    printf("File uploaded successfully.\n");
    return 0;
}
