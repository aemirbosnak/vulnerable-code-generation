//Falcon-180B DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SIZE 1024

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    int input_fd, output_fd;
    char buffer[MAX_SIZE];
    int bytes_read, bytes_written;

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error opening output file: %s\n", strerror(errno));
        close(input_fd);
        return 1;
    }

    while ((bytes_read = read(input_fd, buffer, MAX_SIZE)) > 0) {
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file: %s\n", strerror(errno));
            close(input_fd);
            close(output_fd);
            return 1;
        }
    }

    close(input_fd);
    close(output_fd);

    printf("File copied successfully!\n");
    return 0;
}