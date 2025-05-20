//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Static buffer for the ebook content
#define BUFFER_SIZE 10240
static char ebook[BUFFER_SIZE];

// Function to load the ebook from a file
int load_ebook(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return -1;
    }

    // Read the file contents into the buffer
    size_t bytes_read = fread(ebook, 1, BUFFER_SIZE, fp);
    if (bytes_read < 0) {
        fprintf(stderr, "Error reading file %s\n", filename);
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Add a null-terminator to the end of the buffer
    ebook[bytes_read] = '\0';

    return 0;
}

// Function to display a page of the ebook
void display_page(int page, int page_size) {
    // Calculate the starting and ending offsets of the page
    int start_offset = page * page_size;
    int end_offset = start_offset + page_size;

    // Ensure that the ending offset does not exceed the length of the ebook
    if (end_offset > strlen(ebook)) {
        end_offset = strlen(ebook);
    }

    // Print the page to the console
    printf("%.*s", end_offset - start_offset, ebook + start_offset);
}

// Function to handle user input
int handle_input(int *page, int page_size) {
    // Get user input
    char input[10];
    printf("Enter a command: (n)ext page, (p)revious page, (q)uit\n");
    scanf("%s", input);

    // Process the input
    if (strcmp(input, "n") == 0) {
        // Go to the next page
        *page += 1;
    } else if (strcmp(input, "p") == 0) {
        // Go to the previous page
        *page -= 1;
    } else if (strcmp(input, "q") == 0) {
        // Quit the program
        return 1;
    } else {
        // Invalid input
        printf("Invalid command\n");
    }

    // Ensure that the page number is within bounds
    if (*page < 0) {
        *page = 0;
    } else if (*page >= strlen(ebook) / page_size) {
        *page = strlen(ebook) / page_size - 1;
    }

    return 0;
}

// Main function
int main() {
    // Load the ebook from a file
    if (load_ebook("ebook.txt") < 0) {
        fprintf(stderr, "Error loading ebook\n");
        return -1;
    }

    // Set the page size to 500 characters
    int page_size = 500;

    // Display the first page of the ebook
    int page = 0;
    display_page(page, page_size);

    // Loop until the user quits
    while (1) {
        // Handle user input
        if (handle_input(&page, page_size)) {
            break;
        }

        // Display the next or previous page
        display_page(page, page_size);
    }

    return 0;
}