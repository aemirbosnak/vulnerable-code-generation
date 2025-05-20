//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void check_file_open(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    check_file_open(file);

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
    }

    fclose(file);
}

void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    check_file_open(file);

    if (fputs(content, file) == EOF) {
        fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
    }

    fclose(file);
}

void append_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");
    check_file_open(file);

    if (fputs(content, file) == EOF) {
        fprintf(stderr, "Error appending to file: %s\n", strerror(errno));
    }

    fclose(file);
}

void delete_file(const char *filename) {
    if (remove(filename) != 0) {
        fprintf(stderr, "Error deleting file: %s\n", strerror(errno));
    } else {
        printf("File %s successfully deleted.\n", filename);
    }
}

void display_menu() {
    printf("\n--- File Management Menu ---\n");
    printf("1. Read from file\n");
    printf("2. Write to file\n");
    printf("3. Append to file\n");
    printf("4. Delete a file\n");
    printf("5. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_BUFFER_SIZE];

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear the input buffer
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
                while (getchar() != '\n'); // clear the newline character from the buffer
                fgets(content, MAX_BUFFER_SIZE, stdin);
                write_file(filename, content);
                break;
            case 3:
                printf("Enter filename to append to: ");
                scanf("%s", filename);
                printf("Enter content to append: ");
                while (getchar() != '\n'); // clear the newline character from the buffer
                fgets(content, MAX_BUFFER_SIZE, stdin);
                append_to_file(filename, content);
                break;
            case 4:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                delete_file(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}