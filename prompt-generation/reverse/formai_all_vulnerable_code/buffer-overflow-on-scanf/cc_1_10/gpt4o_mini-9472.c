//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for error codes
#define SUCCESS 0
#define FILE_OPEN_ERROR 1
#define MEMORY_ALLOCATION_ERROR 2
#define INVALID_OPTION_ERROR 3
#define FILE_READ_ERROR 4

// Function declarations
void display_menu();
int read_file(const char *filename, char **buffer);
void handle_error(int error_code);
void clean_up(char *buffer);

int main() {
    char *buffer = NULL;
    int choice, result;

    while (1) {
        display_menu();
        printf("Enter your choice (1-3) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                result = read_file("sample.txt", &buffer);
                if (result != SUCCESS) {
                    handle_error(result);
                } else {
                    printf("File content:\n%s\n", buffer);
                }
                clean_up(buffer);
                buffer = NULL;  // Reset buffer after cleanup
                break;

            case 2:
                printf("You can implement an additional feature here.\n");
                // Placeholder for additional functionality
                break;

            case 3:
                printf("You can implement another additional feature here.\n");
                // Placeholder for another functionality
                break;

            default:
                handle_error(INVALID_OPTION_ERROR);
                break;
        }
    }

    return SUCCESS;
}

void display_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Read File\n");
    printf("2. Additional Feature 1\n");
    printf("3. Additional Feature 2\n");
    printf("------------------\n");
}

int read_file(const char *filename, char **buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return FILE_OPEN_ERROR;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = (char *)malloc(file_size + 1);
    if (!*buffer) {
        fclose(file);
        return MEMORY_ALLOCATION_ERROR;
    }

    size_t read_size = fread(*buffer, 1, file_size, file);
    if (read_size < file_size) {
        fclose(file);
        free(*buffer);
        *buffer = NULL;
        return FILE_READ_ERROR;
    }

    (*buffer)[file_size] = '\0';  // Null-terminate the string
    fclose(file);
    return SUCCESS;
}

void handle_error(int error_code) {
    switch (error_code) {
        case FILE_OPEN_ERROR:
            fprintf(stderr, "Error: Unable to open the file. Please check the file's existence and permissions.\n");
            break;
        case MEMORY_ALLOCATION_ERROR:
            fprintf(stderr, "Error: Memory allocation failed. Please check your system's memory status.\n");
            break;
        case INVALID_OPTION_ERROR:
            fprintf(stderr, "Error: Invalid option selected. Please choose a valid option from the menu.\n");
            break;
        case FILE_READ_ERROR:
            fprintf(stderr, "Error: Unable to read the full content of the file. Check the file format and content.\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown error occurred.\n");
            break;
    }
}

void clean_up(char *buffer) {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}