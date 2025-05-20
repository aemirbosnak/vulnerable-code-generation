//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if a given file exists or not
// Returns 1 if file exists, else returns 0
int fileExists(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Function to read the contents of a given file
// Returns the file contents as a string
char* readFile(char *filename) {
    char *buffer = NULL;
    long length;
    FILE *file = fopen(filename, "r");
    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, file);
            buffer[length] = '\0';
        }
        fclose(file);
    }
    return buffer;
}

// Function to display the contents of a given file
void displayFile(char *filename) {
    char *contents = readFile(filename);
    if (contents) {
        printf("%s", contents);
        free(contents);
    } else {
        printf("File not found!\n");
    }
}

// Main program
int main() {
    char *filename = "ebook.txt";
    int choice;

    // Check if file exists
    if (!fileExists(filename)) {
        printf("Ebook file not found!\n");
        return 0;
    }

    // Display menu and prompt user for choice
    while (1) {
        printf("\nEbook Reader\n");
        printf("1. Display Ebook\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Display ebook or exit
        switch (choice) {
            case 1:
                displayFile(filename);
                break;
            case 2:
                printf("Exiting Ebook Reader...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}