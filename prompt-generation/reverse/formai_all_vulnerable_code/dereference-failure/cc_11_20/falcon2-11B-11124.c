//Falcon2-11B DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char filename[100];
    FILE *file;

    // Prompt user to enter file name
    printf("Enter the name of the file to open: ");
    fgets(filename, sizeof(filename), stdin);

    // Check if file name is null terminated
    if (strlen(filename) == sizeof(filename)) {
        printf("Error: File name is too long.\n");
        return 1;
    }

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File could not be opened.\n");
        return 1;
    }

    // Check file permissions
    if (!access(filename, F_OK) ||!access(filename, W_OK)) {
        printf("Error: Permission denied.\n");
        return 1;
    }

    // Read file contents
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char buffer[size];
    if (fread(buffer, sizeof(char), size, file)!= size) {
        printf("Error: Failed to read file contents.\n");
        return 1;
    }

    // Display file contents
    printf("File contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%c", buffer[i]);
    }

    // Close file
    fclose(file);

    // Check file permissions again
    if (!access(filename, F_OK) ||!access(filename, W_OK)) {
        printf("Error: Permission denied.\n");
        return 1;
    }

    // Attempt to write to file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: File could not be opened.\n");
        return 1;
    }
    if (fwrite("Hello, World!", sizeof("Hello, World!"), 1, file)!= 1) {
        printf("Error: Failed to write to file.\n");
        return 1;
    }
    fclose(file);

    // Check file permissions again
    if (!access(filename, F_OK) ||!access(filename, W_OK)) {
        printf("Error: Permission denied.\n");
        return 1;
    }

    // Attempt to delete file
    if (remove(filename)!= 0) {
        printf("Error: Failed to delete file.\n");
        return 1;
    }

    // Check file permissions again
    if (!access(filename, F_OK) ||!access(filename, W_OK)) {
        printf("Error: Permission denied.\n");
        return 1;
    }

    printf("All done!\n");

    return 0;
}