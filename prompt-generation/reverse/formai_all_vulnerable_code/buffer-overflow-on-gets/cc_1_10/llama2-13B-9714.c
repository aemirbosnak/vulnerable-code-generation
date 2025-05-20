//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to read a file and print its contents
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s\n", buffer);
    }

    fclose(file);
}

// Function to write a file and print its contents
void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[1024];
    gets(buffer); // Don't use gets() in real code, use fgets() or scanf() instead
    printf("Wrote %s to file %s\n", buffer, filename);

    fclose(file);
}

int main() {
    // Example 1: Reading a file
    char filename[] = "example1.txt";
    readFile(filename);

    // Example 2: Writing to a file
    char filename2[] = "example2.txt";
    writeFile(filename2);

    // Example 3: Reading and writing to the same file
    char filename3[] = "example3.txt";
    readFile(filename3);
    writeFile(filename3);

    return 0;
}