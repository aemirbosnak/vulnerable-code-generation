//Falcon-180B DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main() {
    char input_file[100];
    char output_file[100];
    char buffer[BUFFER_SIZE];
    int input_fd, output_fd;
    int bytes_read, bytes_written;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file for reading
    input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Create output file for writing
    output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error creating output file\n");
        exit(1);
    }

    // Copy contents of input file to output file
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file\n");
            exit(1);
        }
    }

    // Close input and output files
    close(input_fd);
    close(output_fd);

    printf("File copied successfully\n");

    return 0;
}