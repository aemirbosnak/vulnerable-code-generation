//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for file paths and maximum file size
#define MAX_FILE_SIZE 100000
#define FILE_PATH_LENGTH 50

// Function to read file content and display on console
void read_file(char* file_path) {
    FILE* fp; // Pointer to file
    char content[MAX_FILE_SIZE]; // Char array to store file content
    int size;

    fp = fopen(file_path, "r"); // Open file in read mode

    if(fp) { // If file exists and opened successfully
        size = fread(content, sizeof(content[0]), MAX_FILE_SIZE, fp); // Read file contents
        content[size] = '\0'; // Terminate string with null character
        fclose(fp); // Close file
        printf("%s", content); // Display file content
    } else { // If file does not exist or fails to open
        printf("Error: Cannot open file %s", file_path);
    }
}

int main() {
    char file_path[FILE_PATH_LENGTH]; // Char array to store file path
    int choice;

    printf("\t Welcome to Happy Ebook Reader!\n\n");

    do {
        // Display options menu
        printf("\t 1. Read an Ebook\n");
        printf("\t 2. Exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Please enter the path of the ebook file: ");
                scanf("%s", file_path);
                read_file(file_path);
                printf("\n\nHappy reading!\n\n");
                break;
            case 2:
                printf("\nThank you for using Happy Ebook Reader!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(choice != 2);

    return 0;
}