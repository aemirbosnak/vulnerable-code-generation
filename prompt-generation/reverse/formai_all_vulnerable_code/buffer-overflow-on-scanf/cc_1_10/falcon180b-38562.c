//Falcon-180B DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_SIZE 1000

// Function to read a file and store its content in a buffer
int read_file(char* filename, char* buffer, int max_size) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return -1;
    }

    int bytes_read = 0;
    char c;
    while ((c = fgetc(fp))!= EOF) {
        if (bytes_read >= max_size) {
            printf("Error: File is too large to fit in buffer\n");
            fclose(fp);
            return -1;
        }
        buffer[bytes_read++] = c;
    }

    fclose(fp);
    buffer[bytes_read] = '\0';
    return 0;
}

// Function to write to a file
int write_file(char* filename, char* buffer, int size) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to open file %s for writing\n", filename);
        return -1;
    }

    int bytes_written = fwrite(buffer, size, 1, fp);
    if (bytes_written!= 1) {
        printf("Error: Failed to write to file %s\n", filename);
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

// Function to handle errors
void error_handler(int error_code) {
    switch (error_code) {
        case -1:
            printf("Error: File operation failed\n");
            break;
        case -2:
            printf("Error: File is too large to fit in buffer\n");
            break;
        case -3:
            printf("Error: Failed to write to file\n");
            break;
        default:
            printf("Error: Unknown error\n");
            break;
    }
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    char buffer[MAX_SIZE];
    int error_code = read_file(filename, buffer, MAX_SIZE);
    if (error_code!= 0) {
        error_handler(error_code);
        return -1;
    }

    printf("File content:\n%s", buffer);

    printf("Enter the name of the file to write: ");
    scanf("%s", filename);

    error_code = write_file(filename, buffer, strlen(buffer));
    if (error_code!= 0) {
        error_handler(error_code);
        return -1;
    }

    printf("File written successfully\n");

    return 0;
}