//Falcon-180B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FILE_NAME "data.txt"
#define BUFFER_SIZE 1024

void write_to_file(int file_descriptor) {
    char buffer[BUFFER_SIZE];
    int bytes_written;
    while (1) {
        printf("Enter a line to write to the file: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        bytes_written = write(file_descriptor, buffer, strlen(buffer));
        if (bytes_written <= 0) {
            printf("Error writing to file.\n");
            exit(1);
        }
    }
}

void read_from_file(int file_descriptor) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while (1) {
        bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            printf("End of file reached.\n");
            break;
        }
        buffer[bytes_read - 1] = '\0';
        printf("%s", buffer);
    }
}

int main() {
    int file_descriptor;
    struct stat file_stat;

    // Check if file exists
    stat(FILE_NAME, &file_stat);
    if (file_stat.st_size == 0) {
        printf("File does not exist. Creating new file...\n");
        file_descriptor = open(FILE_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    } else {
        printf("File exists. Opening file...\n");
        file_descriptor = open(FILE_NAME, O_RDWR, S_IRUSR | S_IWUSR);
    }

    if (file_descriptor == -1) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter 'w' to write to file or 'r' to read from file: ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'w') {
        write_to_file(file_descriptor);
    } else if (choice == 'r') {
        read_from_file(file_descriptor);
    } else {
        printf("Invalid choice. Exiting program.\n");
        exit(1);
    }

    close(file_descriptor);
    return 0;
}