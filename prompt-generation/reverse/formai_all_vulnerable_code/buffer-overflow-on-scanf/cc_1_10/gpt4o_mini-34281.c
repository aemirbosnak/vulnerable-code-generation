//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void displayMenu() {
    printf("Ebook Reader\n");
    printf("1. Read Ebook\n");
    printf("2. Exit\n");
    printf("Choose an option (1-2): ");
}

int readEbook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    char buffer[MAX_BUFFER_SIZE];

    printf("\n--- Ebook Contents ---\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        strcat(buffer, line);
        lineCount++;
        
        if (lineCount % 10 == 0) { // Display every 10 lines
            printf("%s", buffer);
            buffer[0] = '\0'; // Reset buffer
            printf("\nPress Enter to continue or Ctrl+C to exit...\n");
            getchar(); // Wait for user input
        }
    }

    // Display any remaining lines
    if (lineCount % 10 != 0) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int option;

    while (1) {
        displayMenu();
        
        // Input for menu selection
        if(scanf("%d", &option) != 1) {
            while(getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a number (1-2).\n");
            continue; // Prompt for input again
        }

        switch (option) {
            case 1:
                printf("Enter the filename to read (e.g., ebook.txt): ");
                // Clear input buffer before reading filename
                while(getchar() != '\n');
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                
                if (strlen(filename) == 0 || strlen(filename) >= MAX_FILENAME_LENGTH) {
                    printf("Invalid filename. Please try again.\n");
                    break;
                }
                readEbook(filename);
                break;

            case 2:
                printf("Exiting the ebook reader. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please enter a number (1-2).\n");
                break;
        }
    }

    return 0;
}