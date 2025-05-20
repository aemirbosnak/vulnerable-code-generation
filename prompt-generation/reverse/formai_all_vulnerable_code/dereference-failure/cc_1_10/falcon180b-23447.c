//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to check if a file exists
int file_exists(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file!= NULL) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

// Function to read a file into memory and return as a string
char* read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*) malloc(file_size + 1);
    fread(buffer, file_size, 1, file);
    fclose(file);

    buffer[file_size] = '\0';
    return buffer;
}

// Function to write a string to a file
void write_file(char* filename, char* data) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    fwrite(data, strlen(data), 1, file);
    fclose(file);
}

int main() {
    char* filename = "example.txt";

    // Check if file exists, otherwise create it
    if (!file_exists(filename)) {
        char* initial_data = "This is an example file.\n";
        write_file(filename, initial_data);
    }

    // Read file into memory
    char* file_data = read_file(filename);
    printf("File contents:\n%s", file_data);

    // Append to file
    char* new_data = "This is some new data.\n";
    write_file(filename, new_data);

    // Read file into memory again and display updated contents
    file_data = read_file(filename);
    printf("Updated file contents:\n%s", file_data);

    free(file_data);
    return 0;
}