//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a file name
#define MAX_FILENAME_LEN 50

// Define the maximum length of a line in a file
#define MAX_LINE_LEN 100

// Define the maximum number of lines in a file
#define MAX_LINES 1000

// Define the menu options
#define CREATE_FILE 1
#define READ_FILE 2
#define ADD_LINE 3
#define DELETE_LINE 4
#define MODIFY_LINE 5
#define EXIT 6

// Define a function to display the main menu
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Create an empty file\n");
    printf("2. Read a file\n");
    printf("3. Add a line to a file\n");
    printf("4. Delete a line from a file\n");
    printf("5. Modify a line in a file\n");
    printf("6. Exit\n");
}

// Define a function to create a new empty file
void create_file() {
    char filename[MAX_FILENAME_LEN];
    FILE *fptr;

    // Get the file name from the user
    printf("Enter the name of the file to create: ");
    scanf("%s", filename);

    // Open the file in write mode
    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Error creating file %s\n", filename);
        return;
    }

    printf("File %s created successfully!\n", filename);

    // Close the file
    fclose(fptr);
}

// Define a function to read a file
void read_file() {
    char filename[MAX_FILENAME_LEN];
    FILE *fptr;
    char line[MAX_LINE_LEN];

    // Get the file name from the user
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read and print each line in the file
    while (fgets(line, MAX_LINE_LEN, fptr) != NULL) {
        printf("%s", line);
    }

    // Close the file
    fclose(fptr);
}

// Define a function to add a line to a file
void add_line() {
    char filename[MAX_FILENAME_LEN];
    FILE *fptr;
    char line[MAX_LINE_LEN];

    // Get the file name from the user
    printf("Enter the name of the file to add a line to: ");
    scanf("%s", filename);

    // Open the file in append mode
    fptr = fopen(filename, "a");

    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the line to add from the user
    printf("Enter the line to add: ");
    getchar(); // Consume the newline character left behind by scanf
    fgets(line, MAX_LINE_LEN, stdin);

    // Write the line to the file
    fputs(line, fptr);

    printf("Line added successfully!\n");

    // Close the file
    fclose(fptr);
}

// Define a function to delete a line from a file
void delete_line() {
    char filename[MAX_FILENAME_LEN];
    FILE *fptr;
    char line[MAX_LINE_LEN];
    char temp_filename[MAX_FILENAME_LEN];
    int line_num, curr_line_num = 0;
    int deleting = 0;

    // Get the file name from the user
    printf("Enter the name of the file to delete a line from: ");
    scanf("%s", filename);

    // Open the file in read mode
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the line number to delete from the user
    printf("Enter the number of the line to delete: ");
    scanf("%d", &line_num);

    // Open a temporary file in write mode
    strcpy(temp_filename, "temp.txt");
    FILE *temp_fptr = fopen(temp_filename, "w");

    if (temp_fptr == NULL) {
        printf("Error creating temporary file\n");
        return;
    }

    // Read each line in the file, writing to the temporary file except for the line to delete
    while (fgets(line, MAX_LINE_LEN, fptr) != NULL) {
        curr_line_num++;

        if (curr_line_num == line_num) {
            deleting = 1;
            continue;
        }

        fputs(line, temp_fptr);

        if (deleting == 1 && curr_line_num == (line_num + 1)) {
            deleting = 0;
            printf("Line deleted successfully!\n");
        }
    }

    // Close the files
    fclose(fptr);
    fclose(temp_fptr);

    // Delete the original file
    remove(filename);

    // Rename the temporary file to the original file name
    rename(temp_filename, filename);
}

// Define a function to modify a line in a file
void modify_line() {
    char filename[MAX_FILENAME_LEN];
    FILE *fptr;
    char line[MAX_LINE_LEN];
    char temp_filename[MAX_FILENAME_LEN];
    int line_num, curr_line_num = 0;
    int modifying = 0;

    // Get the file name from the user
    printf("Enter the name of the file to modify a line in: ");
    scanf("%s", filename);

    // Open the file in read mode
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the line number to modify from the user
    printf("Enter the number of the line to modify: ");
    scanf("%d", &line_num);

    // Open a temporary file in write mode
    strcpy(temp_filename, "temp.txt");
    FILE *temp_fptr = fopen(temp_filename, "w");

    if (temp_fptr == NULL) {
        printf("Error creating temporary file\n");
        return;
    }

    // Read each line in the file, writing modified text to the temporary file for the line to modify
    while (fgets(line, MAX_LINE_LEN, fptr) != NULL) {
        curr_line_num++;

        if (curr_line_num == line_num) {
            modifying = 1;

            // Get the new line of text from the user
            printf("Enter the modified line: ");
            getchar(); // Consume the newline character left behind by scanf
            fgets(line, MAX_LINE_LEN, stdin);

            // Write the modified line to the temporary file
            fputs(line, temp_fptr);
        } else {
            fputs(line, temp_fptr);
        }

        if (modifying == 1 && curr_line_num == (line_num + 1)) {
            modifying = 0;
            printf("Line modified successfully!\n");
        }
    }

    // Close the files
    fclose(fptr);
    fclose(temp_fptr);

    // Delete the original file
    remove(filename);

    // Rename the temporary file to the original file name
    rename(temp_filename, filename);
}

int main() {
    int choice;

    // Display the main menu
    display_menu();

    while (1) {
        // Get the user's choice
        printf("\nEnter an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case CREATE_FILE:
                create_file();
                break;
            case READ_FILE:
                read_file();
                break;
            case ADD_LINE:
                add_line();
                break;
            case DELETE_LINE:
                delete_line();
                break;
            case MODIFY_LINE:
                modify_line();
                break;
            case EXIT:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
        
        // Display the main menu
        display_menu();
    }

    return 0;
}