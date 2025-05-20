//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_STRING_LENGTH 100
#define FILE_PATH "output.txt"

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void write_to_file(const char *data) {
    FILE *file = fopen(FILE_PATH, "a");
    if (file == NULL) {
        handle_error("Failed to open file for writing");
    }

    if (fputs(data, file) == EOF) {
        fclose(file);
        handle_error("Failed to write to file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close file");
    }

    printf("Successfully wrote to %s\n", FILE_PATH);
}

void read_from_file() {
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        handle_error("Failed to open file for reading");
    }

    char line[MAX_STRING_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("Read from file: %s", line);
    }

    if (ferror(file)) {
        fclose(file);
        handle_error("Error reading file");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close file");
    }

    printf("Finished reading from %s\n", FILE_PATH);
}

void append_data() {
    char input[MAX_STRING_LENGTH];
    printf("Enter data to write to file (type 'exit' to stop):\n");

    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            handle_error("Failed to read input");
        }

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        write_to_file(input);
    }
}

int main() {
    printf("File I/O Error Handling Example\n");
    printf("1. Append data to a file\n");
    printf("2. Read data from a file\n");
    printf("3. Exit\n");

    int choice = 0;
    while (1) {
        printf("Choose an option (1-3): ");
        if (scanf("%d", &choice) != 1) {
            handle_error("Invalid input");
        }

        // Clear the standard input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                append_data();
                break;
            case 2:
                read_from_file();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please choose 1, 2, or 3.\n");
                break;
        }
    }

    return 0;
}