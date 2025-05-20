//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void display_file_content(FILE *file) {
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void open_and_read_file() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;

    printf("Enter the eBook filename (with .txt extension): ");
    if (fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = 0; // Remove trailing newline
    } else {
        fprintf(stderr, "Error reading filename.\n");
        return;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- Content of '%s' ---\n", filename);
    display_file_content(file);
    fclose(file);
}

void display_menu() {
    printf("\n--- eBook Reader Menu ---\n");
    printf("1. Read an eBook (.txt)\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
        // Validate user input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer(); // Clear invalid input from buffer
            choice = 0; // set to continue looping
            continue;
        }
        clear_input_buffer(); // Clear remaining input in buffer

        switch (choice) {
            case 1:
                open_and_read_file();
                break;
            case 2:
                printf("Exiting the eBook Reader. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}