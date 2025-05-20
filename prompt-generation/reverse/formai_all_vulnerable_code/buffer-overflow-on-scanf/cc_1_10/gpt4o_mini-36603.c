//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

void display_menu() {
    printf("\n------ eBook Reader ------\n");
    printf("1. Read eBook\n");
    printf("2. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

void read_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char *lines[MAX_LINES];
    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), file) && line_count < MAX_LINES) {
        // Allocate memory for each line
        lines[line_count] = (char *)malloc(strlen(buffer) + 1);
        if (lines[line_count] == NULL) {
            perror("Memory allocation failed");
            break;
        }
        strcpy(lines[line_count], buffer);
        line_count++;
    }

    fclose(file);

    int current_page = 0;  
    int lines_per_page = 10;  
    while (current_page * lines_per_page < line_count) {
        printf("\n--- Page %d ---\n", current_page + 1);
        for (int i = 0; i < lines_per_page && (i + current_page * lines_per_page) < line_count; i++) {
            printf("%s", lines[i + current_page * lines_per_page]);
        }

        if (current_page * lines_per_page + lines_per_page < line_count) {
            printf("\nPress Enter for next page, 'q' to quit: ");
            char input[10];
            fgets(input, sizeof(input), stdin);
            if (input[0] == 'q') break;
            current_page++;
        } else {
            printf("\nEnd of the eBook reached.\n");
            break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
}

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear buffer

        switch (choice) {
            case 1:
                read_ebook("ebook.txt"); // Make sure this file exists in the same directory
                break;
            case 2:
                printf("Exiting eBook reader. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}