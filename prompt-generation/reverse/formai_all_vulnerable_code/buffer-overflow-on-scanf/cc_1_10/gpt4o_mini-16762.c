//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define PAGE_SIZE 20

// Function to display the content of the ebook
void display_content(FILE *file) {
    char buffer[BUFFER_SIZE];
    int line_count = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
        line_count++;
        if (line_count >= PAGE_SIZE) {
            line_count = 0;
            printf("\n-- Press Enter to continue --.");
            getchar();  // Wait for user input to proceed
        }
    }
}

// Function to read the ebook file
void read_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }
    
    printf("Opening the ebook: %s\n", filename);
    printf("Enjoy your reading...\n");
    
    display_content(file);
    
    fclose(file);
    printf("Thank you for reading! Good day!\n\n");
}

// Function to show the menu
void show_menu() {
    printf("Welcome to the Peaceful Ebook Reader\n");
    printf("1. Read EPUB ebook\n");
    printf("2. Read TXT ebook\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

// Main function
int main() {
    int choice;
    char filename[BUFFER_SIZE];

    while (1) {
        show_menu();
        scanf("%d", &choice);
        getchar();  // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Please enter the path to your EPUB file: ");
                fgets(filename, BUFFER_SIZE, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove new line character
                read_ebook(filename);
                break;
            case 2:
                printf("Please enter the path to your TXT file: ");
                fgets(filename, BUFFER_SIZE, stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove new line character
                read_ebook(filename);
                break;
            case 3:
                printf("Exiting the reader. May your day be filled with peace and joy!\n");
                exit(0);
            default:
                printf("Invalid choice, please choose again.\n");
                break;
        }
    }

    return 0;
}