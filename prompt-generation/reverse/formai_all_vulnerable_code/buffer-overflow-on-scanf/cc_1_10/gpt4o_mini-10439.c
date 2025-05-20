//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define COMMAND_SIZE 100

void display_menu() {
    printf("\nSimple Text Editor\n");
    printf("1. Display Text\n");
    printf("2. Insert Text\n");
    printf("3. Delete Text\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void display_text(const char *text) {
    if (strlen(text) == 0) {
        printf("\nThe text is empty.\n");
    } else {
        printf("\nCurrent Text: %s\n", text);
    }
}

void insert_text(char *text, size_t *current_length) {
    char buffer[MAX_BUFFER];
    printf("Enter text to insert: ");
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

    size_t insert_length = strlen(buffer);
    if (*current_length + insert_length < MAX_BUFFER) {
        strcat(text, buffer);
        *current_length += insert_length;
        printf("Text inserted!\n");
    } else {
        printf("Insertion failed! The text would exceed maximum buffer size.\n");
    }
}

void delete_text(char *text, size_t *current_length) {
    if (*current_length > 0) {
        printf("Enter number of characters to delete: ");
        size_t num_to_delete;
        scanf("%zu", &num_to_delete);
        getchar(); // consume newline

        if (num_to_delete > *current_length) {
            num_to_delete = *current_length; // delete all if more than available
        }
        text[*current_length - num_to_delete] = '\0'; // truncate the string
        *current_length -= num_to_delete;
        printf("Text deleted!\n");
    } else {
        printf("No text to delete.\n");
    }
}

int main() {
    char text[MAX_BUFFER] = "";
    size_t current_length = 0;
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);
        getchar(); // consume newline

        switch (option) {
            case 1:
                display_text(text);
                break;
            case 2:
                insert_text(text, &current_length);
                break;
            case 3:
                delete_text(text, &current_length);
                break;
            case 4:
                printf("Exiting the editor. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}