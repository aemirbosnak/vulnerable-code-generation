//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 1000  // Maximum data size of the file

int main() {
    char file_name[50];  // Name of the file to be recovered
    char data[MAX_DATA_SIZE];  // Container for the recovered data
    int data_size = 0;  // Size of the recovered data

    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    // Open the file with read mode
    FILE *file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL) {
        printf("Error opening file %s.\n", file_name);
        exit(1);
    }

    // Read the data from the file
    char buffer[MAX_DATA_SIZE];  // Buffer to read the data in chunks
    int buffer_size = sizeof(buffer) / sizeof(char);  // Size of the buffer
    int bytes_read = 0;  // Number of bytes read in each iteration
    
    while ((bytes_read = fread(buffer, sizeof(char), buffer_size, file_ptr)) > 0) {
        // Update recovered data size
        data_size += bytes_read;

        // Append the buffer to the data
        int offset = data_size - bytes_read;  // Offset to the data segment start
        for (int i = 0; i < bytes_read; i++) {
            data[i + offset] = buffer[i];
        }
    }

    // Close the file
    fclose(file_ptr);

    // Write the recovered data to a new file
    FILE *recovered_file_ptr = fopen("recovered.txt", "w");
    if (recovered_file_ptr == NULL) {
        printf("Error creating recovered file.\n");
        exit(1);
    }

    fwrite(data, sizeof(char), data_size, recovered_file_ptr);

    // Close the recovered file
    fclose(recovered_file_ptr);

    printf("Recovery successful. %d bytes of data recovered.\n", data_size);

    return 0;
}