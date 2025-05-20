//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FILENAME_LENGTH 256

void create_file(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to create file");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void write_to_file(char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Enter text to write to the file (type 'exit' to finish):\n");
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
        fprintf(file, "%s", buffer);
    }

    fclose(file);
    printf("Data written to '%s' successfully.\n", filename);
}

void read_from_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Contents of '%s':\n", filename);
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

void delete_file(char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Failed to delete file");
    }
}

void show_menu() {
    printf("\nFile Operations Menu:\n");
    printf("1. Create a File\n");
    printf("2. Write to a File\n");
    printf("3. Read from a File\n");
    printf("4. Delete a File\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char filename[FILENAME_LENGTH];

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character left by scanf
        
        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline
                create_file(filename);
                break;
            case 2:
                printf("Enter filename to write to: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline
                write_to_file(filename);
                break;
            case 3:
                printf("Enter filename to read from: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline
                read_from_file(filename);
                break;
            case 4:
                printf("Enter filename to delete: ");
                fgets(filename, FILENAME_LENGTH, stdin);
                filename[strcspn(filename, "\n")] = 0; // remove newline
                delete_file(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}