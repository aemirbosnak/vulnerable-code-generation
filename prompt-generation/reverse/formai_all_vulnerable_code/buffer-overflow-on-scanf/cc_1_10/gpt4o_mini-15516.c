//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCROLLS 100
#define MAX_NAME_LENGTH 100
#define FILENAME "scroll_library.txt"

// Function to add a scroll to the library
void add_scroll() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Alas, unable to open the scroll library!\n");
        return;
    }
    
    char scroll_name[MAX_NAME_LENGTH];
    printf("Enter the name of the ancient scroll to add: ");
    fgets(scroll_name, sizeof(scroll_name), stdin);
    scroll_name[strcspn(scroll_name, "\n")] = 0;  // Remove the newline

    fprintf(file, "%s\n", scroll_name);
    printf("The scroll '%s' has been inscribed into the library.\n", scroll_name);
    
    fclose(file);
}

// Function to display all scrolls in the library
void display_scrolls() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Alas, the scroll library is empty or unknown!\n");
        return;
    }
    
    char scroll_name[MAX_NAME_LENGTH];
    printf("The scrolls within the library are as follows:\n");

    while (fgets(scroll_name, sizeof(scroll_name), file) != NULL) {
        printf("- %s", scroll_name);
    }
    
    fclose(file);
}

// Function to clear the scroll library
void clear_scrolls() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Alas, unable to access the scroll library to clear it!\n");
        return;
    }

    fprintf(file, "");
    printf("The ancient scrolls have been erased from the library.\n");
    fclose(file);
}

// Main function of the scroll library program
int main() {
    int choice;

    do {
        printf("\nWelcome to the Scroll Library of the Kingdom!\n");
        printf("1. Add a new scroll\n");
        printf("2. Display all scrolls\n");
        printf("3. Clear the scroll library\n");
        printf("4. Exit the library\n");
        printf("Choose your destiny (1-4): ");
        scanf("%d", &choice);
        getchar();  // Consume the newline left by scanf

        switch (choice) {
            case 1:
                add_scroll();
                break;
            case 2:
                display_scrolls();
                break;
            case 3:
                clear_scrolls();
                break;
            case 4:
                printf("Fare thee well, brave scholar!\n");
                break;
            default:
                printf("Nay, that is not a valid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}