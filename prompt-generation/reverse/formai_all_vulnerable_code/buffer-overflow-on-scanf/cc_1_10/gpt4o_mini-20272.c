//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display a menu
void displayMenu() {
    printf("=== File Handling Program ===\n");
    printf("1. Write to File\n");
    printf("2. Read from File\n");
    printf("3. Append to File\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option: ");
}

// Function to write data to the file
void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    char data[256];
    printf("Enter data to write to the file (max 255 characters): ");
    fgets(data, sizeof(data), stdin);
    fputs(data, file);
    fclose(file);

    printf("Data written successfully!\n");
}

// Function to read data from the file
void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    char ch;
    printf("Contents of the file:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\nEnd of file.\n");
}

// Function to append data to the file
void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Failed to open file for appending");
        return;
    }

    char data[256];
    printf("Enter data to append to the file (max 255 characters): ");
    fgets(data, sizeof(data), stdin);
    fputs(data, file);
    fclose(file);

    printf("Data appended successfully!\n");
}

// Main function
int main() {
    char filename[100];
    printf("Enter the filename you wish to use: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character after the choice

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendToFile(filename);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}