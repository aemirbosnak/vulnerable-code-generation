//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256

void handle_error(const char *msg) {
    fprintf(stderr, "Error: %s. Errno: %d - %s\n", msg, errno, strerror(errno));
    exit(EXIT_FAILURE);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handle_error("Failed to open file");
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    if (ferror(file)) {
        handle_error("Error reading file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close file");
    }
}

void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        handle_error("Failed to create file");
    }

    if (fprintf(file, "%s", data) < 0) {
        handle_error("Error writing to file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close file");
    }
}

void append_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        handle_error("Failed to open file for appending");
    }

    if (fprintf(file, "%s", data) < 0) {
        handle_error("Error appending to file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close file");
    }
}

void display_menu() {
    printf("1. Read File\n");
    printf("2. Write to File\n");
    printf("3. Append to File\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char filename[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];

    printf("Welcome to the File Manager!\n");
    do {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter filename to read: ");
                scanf("%s", filename);
                read_file(filename);
                break;

            case 2:
                printf("Enter filename to write: ");
                scanf("%s", filename);
                printf("Enter content to write: ");
                getchar(); // clear newline left by scanf
                fgets(buffer, sizeof(buffer), stdin);
                write_file(filename, buffer);
                break;

            case 3:
                printf("Enter filename to append: ");
                scanf("%s", filename);
                printf("Enter content to append: ");
                getchar(); // clear newline left by scanf
                fgets(buffer, sizeof(buffer), stdin);
                append_to_file(filename, buffer);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                fprintf(stderr, "Invalid choice. Please select a valid option.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}