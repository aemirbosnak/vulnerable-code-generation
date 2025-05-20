//Falcon-180B DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024

int main() {
    char input_file[MAX_LINE_SIZE];
    char output_file[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    int input_file_fd, output_file_fd;
    ssize_t bytes_read;

    // Prompt user for input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Open input file for reading
    input_file_fd = open(input_file, O_RDONLY);
    if (input_file_fd == -1) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    // Prompt user for output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Open output file for writing
    output_file_fd = open(output_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (output_file_fd == -1) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    // Loop through input file and reverse each line
    while ((bytes_read = read(input_file_fd, line, MAX_LINE_SIZE)) > 0) {
        line[bytes_read - 1] = '\0';
        for (int i = strlen(line) - 1; i >= 0; i--) {
            printf("%c", line[i]);
        }
        printf("\n");
        if (write(output_file_fd, line, strlen(line)) == -1) {
            printf("Error: could not write to output file\n");
            exit(1);
        }
        memset(line, 0, MAX_LINE_SIZE);
    }

    // Close input and output files
    close(input_file_fd);
    close(output_file_fd);

    return 0;
}