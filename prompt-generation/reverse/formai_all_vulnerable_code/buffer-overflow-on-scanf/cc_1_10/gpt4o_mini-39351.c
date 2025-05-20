//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Error opening file");
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        fclose(file);
        handle_error("Error reading file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing file");
    }
}

void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        handle_error("Error opening file for writing");
    }

    if (fputs(content, file) == EOF) {
        fclose(file);
        handle_error("Error writing to file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing file");
    }
}

void append_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        handle_error("Error opening file for appending");
    }

    if (fputs(content, file) == EOF) {
        fclose(file);
        handle_error("Error appending to file");
    }

    if (fclose(file) != 0) {
        handle_error("Error closing file");
    }
}

void create_and_write_file(const char *filename) {
    char content[MAX_BUFFER_SIZE];
    printf("Enter content to write to %s:\n", filename);
    if (fgets(content, sizeof(content), stdin) == NULL) {
        handle_error("Error reading input");
    }
    write_file(filename, content);
}

void read_and_append_file(const char *filename) {
    char content[MAX_BUFFER_SIZE];
    printf("Enter content to append to %s:\n", filename);
    if (fgets(content, sizeof(content), stdin) == NULL) {
        handle_error("Error reading input");
    }
    append_to_file(filename, content);
}

void display_menu() {
    printf("\nFile Operation Menu:\n");
    printf("1. Create and Write to a File\n");
    printf("2. Read a File\n");
    printf("3. Append to a File\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int main() {
    int choice;
    char filename[MAX_BUFFER_SIZE];

    do {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            handle_error("Invalid input. Please enter a number.");
        }

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                create_and_write_file(filename);
                break;

            case 2:
                printf("Enter filename to read: ");
                scanf("%s", filename);
                read_file(filename);
                break;

            case 3:
                printf("Enter filename to append: ");
                scanf("%s", filename);
                read_and_append_file(filename);
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }

        // Clear the input buffer
        while ((getchar()) != '\n');

    } while (choice != 4);

    return EXIT_SUCCESS;
}