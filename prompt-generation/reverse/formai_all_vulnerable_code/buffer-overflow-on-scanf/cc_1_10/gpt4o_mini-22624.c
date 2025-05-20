//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define FILENAME "names.txt"

// Function to write names to a file
void writeNameToFile(const char *name) {
    FILE *file = fopen(FILENAME, "a"); // Open file in append mode
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fprintf(file, "%s\n", name);
    fclose(file);
    printf("Name '%s' added to the file.\n", name);
}

// Function to read names from a file
void readNamesFromFile() {
    FILE *file = fopen(FILENAME, "r"); // Open file in read mode
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Names in %s:\n", FILENAME);
    while (fgets(name, sizeof(name), file) != NULL) {
        printf("%s", name);
    }
    fclose(file);
}

// Function to clear contents of the file
void clearFileContents() {
    FILE *file = fopen(FILENAME, "w"); // Open file in write mode, clearing its contents
    if (file == NULL) {
        perror("Error clearing file");
        return;
    }
    fclose(file);
    printf("File contents cleared.\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\n--- Name Management System ---\n");
        printf("1. Add a Name\n");
        printf("2. Display Names\n");
        printf("3. Clear All Names\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 4.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the name to add: ");
                scanf("%s", name);
                writeNameToFile(name);
                break;
            case 2:
                readNamesFromFile();
                break;
            case 3:
                clearFileContents();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    }
    return 0;
}