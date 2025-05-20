//FormAI DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 255
#define MAX_BUFFER_SIZE 1024

int main() {
    char filename[MAX_FILENAME_SIZE + 1];
    char buffer[MAX_BUFFER_SIZE];
    int size;
    FILE *file_ptr, *recovered_file_ptr;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    // Open the file for reading
    file_ptr = fopen(filename, "rb");
    if (file_ptr == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Get the size of the file
    fseek(file_ptr, 0L, SEEK_END);
    size = ftell(file_ptr);
    rewind(file_ptr);

    // Create a new file for writing
    recovered_file_ptr = fopen("recovered.bin", "wb");
    if (recovered_file_ptr == NULL) {
        printf("Could not create file for writing\n");
        fclose(file_ptr);
        return 1;
    }

    // Read the file in chunks and write it to the new file
    while (size > 0) {
        if (size < MAX_BUFFER_SIZE) {
            fread(buffer, size, 1, file_ptr);
            fwrite(buffer, size, 1, recovered_file_ptr);
            size = 0;
        } else {
            fread(buffer, MAX_BUFFER_SIZE, 1, file_ptr);
            fwrite(buffer, MAX_BUFFER_SIZE, 1, recovered_file_ptr);
            size -= MAX_BUFFER_SIZE;
        }
    }

    printf("File recovery successful\n");
    fclose(file_ptr);
    fclose(recovered_file_ptr);
    return 0;
}