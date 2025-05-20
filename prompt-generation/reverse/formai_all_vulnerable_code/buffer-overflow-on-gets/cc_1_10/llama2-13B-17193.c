//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILE_NAME 256
#define MAX_BUFFER 1024

// Function to read a file and print its contents
void read_file(const char *filename)
{
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Read the contents of the file
    char buffer[MAX_BUFFER];
    while (fgets(buffer, MAX_BUFFER, file)) {
        printf("%s\n", buffer);
    }

    // Close the file
    fclose(file);
}

// Function to write a file and print its contents
void write_file(const char *filename)
{
    // Open the file in write mode
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write some contents to the file
    char buffer[MAX_BUFFER];
    gets(buffer);
    fprintf(file, "%s\n", buffer);

    // Close the file
    fclose(file);
}

// Function to append to a file and print its contents
void append_file(const char *filename)
{
    // Open the file in append mode
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Read some contents from the user
    char buffer[MAX_BUFFER];
    gets(buffer);

    // Append the contents to the file
    fprintf(file, "%s\n", buffer);

    // Close the file
    fclose(file);
}

int main()
{
    // Read a file and print its contents
    read_file("example.txt");

    // Write a file and print its contents
    write_file("new_file.txt");

    // Append to a file and print its contents
    append_file("existing_file.txt");

    return 0;
}