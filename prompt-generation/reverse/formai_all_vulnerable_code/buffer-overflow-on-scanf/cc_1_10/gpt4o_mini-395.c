//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error creating file: %s\n", filename);
        return;
    }
    fprintf(file, "Welcome to the peaceful file handling program!\n");
    fprintf(file, "You can add data and explore your creativity.\n");
    fclose(file);
    printf("File '%s' created successfully with initial content.\n", filename);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error reading file: %s\n", filename);
        return;
    }
    
    char line[256];
    printf("Contents of '%s':\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for appending: %s\n", filename);
        return;
    }
    
    char input[256];
    printf("Enter text to append to '%s'. Type 'exit' to finish:\n", filename);
    
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        fputs(input, file);
    }
    fclose(file);
    printf("Text successfully appended to '%s'.\n", filename);
}

void displayMenu() {
    printf("\n--- Peaceful File Handling Program Menu ---\n");
    printf("1. Create a new file\n");
    printf("2. Read existing file\n");
    printf("3. Append to existing file\n");
    printf("4. Exit\n");
    printf("-------------------------------------------\n");
}

int main() {
    const char *filename = "peaceful_file.txt";
    int choice;

    createFile(filename);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the leftover newline character

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendToFile(filename);
                break;
            case 4:
                printf("Exiting the peaceful program. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}