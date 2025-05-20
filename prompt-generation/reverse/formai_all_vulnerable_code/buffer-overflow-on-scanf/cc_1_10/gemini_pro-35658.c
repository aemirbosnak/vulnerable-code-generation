//GEMINI-pro DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void welcome() {
    printf("Welcome to the File Handling Adventure!\n");
    printf("Prepare yourself for a journey through the world of bits and bytes.\n");
    printf("We'll create, read, write, and explore files like never before.\n\n");
}

// Create a new file
void create_file() {
    // Get the file name from the user
    char file_name[256];
    printf("Enter the name of the file you want to create: ");
    scanf("%s", file_name);

    // Open the file in write mode
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Write some data to the file
    char data[256];
    printf("Enter the data you want to write to the file: ");
    scanf("%s", data);
    fprintf(fp, "%s", data);

    // Close the file
    fclose(fp);

    printf("File created successfully.\n");
}

// Read data from a file
void read_file() {
    // Get the file name from the user
    char file_name[256];
    printf("Enter the name of the file you want to read: ");
    scanf("%s", file_name);

    // Open the file in read mode
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Read the data from the file
    char data[256];
    while (fgets(data, 256, fp) != NULL) {
        printf("%s", data);
    }

    // Close the file
    fclose(fp);

    printf("File read successfully.\n");
}

// Write data to a file
void write_file() {
    // Get the file name from the user
    char file_name[256];
    printf("Enter the name of the file you want to write to: ");
    scanf("%s", file_name);

    // Open the file in write mode
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Write some data to the file
    char data[256];
    printf("Enter the data you want to write to the file: ");
    scanf("%s", data);
    fprintf(fp, "%s", data);

    // Close the file
    fclose(fp);

    printf("File written successfully.\n");
}

// Explore a file
void explore_file() {
    // Get the file name from the user
    char file_name[256];
    printf("Enter the name of the file you want to explore: ");
    scanf("%s", file_name);

    // Open the file in read mode
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Print the file size
    printf("File size: %ld bytes\n", file_size);

    // Print the file contents
    char data[file_size + 1];
    fread(data, file_size, 1, fp);
    data[file_size] = '\0';
    printf("File contents:\n%s", data);

    // Close the file
    fclose(fp);

    printf("File explored successfully.\n");
}

// Goodbye message
void goodbye() {
    printf("\nThank you for using the File Handling Adventure!\n");
    printf("We hope you had a fun and educational experience.\n");
    printf("Until next time, happy coding!\n");
}

// Main function
int main() {
    // Show the welcome message
    welcome();

    // Get the user's choice
    int choice;
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Create a new file\n");
        printf("2. Read data from a file\n");
        printf("3. Write data to a file\n");
        printf("4. Explore a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                read_file();
                break;
            case 3:
                write_file();
                break;
            case 4:
                explore_file();
                break;
            case 5:
                goodbye();
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}