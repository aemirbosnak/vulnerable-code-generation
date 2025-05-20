//Falcon-180B DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    int file_fd;
    char file_name[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *filename_ptr;
    int file_size;
    char *buffer;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", file_name);

    // Open file for reading
    file_fd = open(file_name, O_RDONLY);
    if (file_fd == -1) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Get file size
    file_size = lseek(file_fd, 0, SEEK_END);

    // Allocate memory for file buffer
    buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    // Read file into buffer
    lseek(file_fd, 0, SEEK_SET);
    read(file_fd, buffer, file_size);
    close(file_fd);

    // Reverse buffer
    for (i = 0; i < file_size / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[file_size - i - 1];
        buffer[file_size - i - 1] = temp;
    }
    buffer[file_size] = '\0';

    // Print reversed file
    printf("Reversed file:\n");
    for (filename_ptr = buffer; *filename_ptr!= '\0'; filename_ptr++) {
        printf("%c", *filename_ptr);
    }
    printf("\n");

    // Free memory
    free(buffer);

    return 0;
}