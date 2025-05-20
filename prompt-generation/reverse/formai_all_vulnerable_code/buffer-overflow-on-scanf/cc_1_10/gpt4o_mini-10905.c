//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 1000  // Max characters per page
#define MAX_FILENAME_LENGTH 100

void display_page(FILE *file, int page_number) {
    char buffer[PAGE_SIZE + 1];
    int current_page = 0;

    // Seek to the current page position in the file
    fseek(file, page_number * PAGE_SIZE, SEEK_SET);

    // Read the page content
    fread(buffer, sizeof(char), PAGE_SIZE, file);
    buffer[PAGE_SIZE] = '\0';  // Null terminate the string

    // If the buffer is empty, we hit the end of the file
    if (feof(file)) {
        printf("End of the book.\n");
        return;
    }

    // Display the current page
    printf("\nPage %d:\n", page_number + 1);
    printf("%s", buffer);
}

void read_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    int page_number = 0;
    char command[10];

    // Read, display, and navigate through the book
    while (1) {
        display_page(file, page_number);

        // Prompt user for command
        printf("\nCommands: n (next), p (previous), q (quit). Choose an action: ");
        scanf("%s", command);

        if (strcmp(command, "n") == 0) {
            page_number++;
        } else if (strcmp(command, "p") == 0) {
            if (page_number > 0) {
                page_number--;
            } else {
                printf("You are already at the first page.\n");
            }
        } else if (strcmp(command, "q") == 0) {
            printf("Exiting the ebook reader.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }

        // Check if the next page is available before moving
        fseek(file, (page_number + 1) * PAGE_SIZE, SEEK_SET);
        if (feof(file)) {
            printf("You have reached the end of the book.\n");
            break;
        }
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Welcome to the Simple Ebook Reader!\n");
    printf("Enter the path of the text file to open: ");
    scanf("%s", filename);

    read_ebook(filename);

    return 0;
}