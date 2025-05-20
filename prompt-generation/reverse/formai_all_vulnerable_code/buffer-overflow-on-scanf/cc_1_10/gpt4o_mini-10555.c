//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_TITLE 100
#define BUFFER_SIZE 256

void displayEbooks(const char *directory);
void readEbook(const char *filepath);
void clearScreen();

int main() {
    const char *ebookDirectory = "ebooks"; // Change as needed

    clearScreen();
    printf("Welcome to the E-book Reader\n");
    displayEbooks(ebookDirectory);

    return 0;
}

void displayEbooks(const char *directory) {
    DIR *d;
    struct dirent *dir;
    char filepath[MAX_PATH];
    int choice = 0;

    d = opendir(directory);
    if (d) {
        printf("Available E-books:\n");
        int index = 1;

        while ((dir = readdir(d)) != NULL) {
            // Ignore current and parent directory entries
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                printf("%d. %s\n", index++, dir->d_name);
            }
        }
        
        printf("\nEnter the number of the E-book you want to read (0 to exit): ");
        scanf("%d", &choice);

        // Ensure valid selection
        if (choice > 0 && choice < index) {
            closedir(d);
            printf("Reading E-book...\n");
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, dir->d_name);
            readEbook(filepath);
        } else if (choice == 0) {
            printf("Exiting E-book Reader.\n");
            closedir(d);
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
            closedir(d);
            displayEbooks(directory);
        }
    } else {
        perror("Unable to open the ebook directory");
        exit(EXIT_FAILURE);
    }
}

void readEbook(const char *filepath) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    file = fopen(filepath, "r");
    if (!file) {
        perror("Error opening the E-book");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
        // Pause after 20 lines for user input to continue reading
        if (ftell(file) % (BUFFER_SIZE * 20) == 0) {
            printf("\nPress Enter to continue...");
            getchar();
            getchar();  // to consume the newline character
            clearScreen();
        }
    }

    fclose(file);
    printf("\nEnd of E-book. Returning to the list...\n");
    displayEbooks("ebooks");
}

void clearScreen() {
    // Clear the console
    printf("\033[H\033[J");
}