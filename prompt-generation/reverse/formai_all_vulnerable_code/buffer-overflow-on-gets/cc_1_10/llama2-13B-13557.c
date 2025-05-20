//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and print its contents
void readFile(const char* filePath) {
    // Open the file in read mode
    FILE* file = fopen(filePath, "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return;
    }

    // Read the file contents
    char buffer[1024];
    while (fgets(buffer, 1024, file)) {
        // Print the file contents
        printf("%s\n", buffer);
    }

    // Close the file
    fclose(file);
}

// Function to write a file and print its contents
void writeFile(const char* filePath) {
    // Open the file in write mode
    FILE* file = fopen(filePath, "w");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return;
    }

    // Write the file contents
    char buffer[1024];
    gets(buffer); // Replace with your own input function
    fputs(buffer, file);

    // Close the file
    fclose(file);
}

int main() {
    // Read a file and print its contents
    readFile("example.txt");

    // Write a file and print its contents
    writeFile("new_example.txt");

    return 0;
}