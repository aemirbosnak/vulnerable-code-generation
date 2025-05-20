//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a file and write to it
void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    char input[256];
    printf("Enter text to write to the file (type 'exit' to finish):\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        fputs(input, file);
    }

    fclose(file);
    printf("Data successfully written to '%s'.\n", filename);
}

// Function to read from a file
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

// Function to append to a file
void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    char input[256];
    printf("Enter text to append to the file (type 'exit' to finish):\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        fputs(input, file);
    }

    fclose(file);
    printf("Data successfully appended to '%s'.\n", filename);
}

// Function to display the menu and get user choice
int displayMenu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Create a file\n");
    printf("2. Read a file\n");
    printf("3. Append to a file\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        // Clear input buffer if non-integer is entered
        while (getchar() != '\n');
        return -1; // Indicate error
    }
    // Clear input buffer
    while (getchar() != '\n');
    return choice;
}

int main() {
    const char *filename = "example.txt";
    int choice;

    printf("File Management Program\n");
    
    while (1) {
        choice = displayMenu();
        if (choice == -1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            continue;
        }

        switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2:
            readFile(filename);
            break;
        case 3:
            appendFile(filename);
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Please select a valid option (1-4).\n");
        }
    }

    return 0;
}