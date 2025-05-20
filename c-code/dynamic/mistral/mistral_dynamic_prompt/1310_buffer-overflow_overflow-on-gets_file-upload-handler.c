#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void handle_file_upload(char* buffer) {
    char file_data[BUFFER_SIZE];
    FILE* file = fopen("uploaded_file", "wb");

    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(buffer, strlen(buffer), 1, file);
    fclose(file);
}

int main(int argc, char* argv[]) {
    char buffer[BUFFER_SIZE];
    printf("File uploader v1.0\n");
    printf("Enter the path of the file to upload: ");

    gets(buffer); // UNSAFE: uses gets() function with no bounds checking

    handle_file_upload(buffer);

    printf("File uploaded successfully!\n");

    return 0;
}
