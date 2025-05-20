//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>

/* Define the maximum number of pages the ebook can have */
#define MAX_PAGES 1000

/* Helper function to display page content */
void display_page(char* page_content) {
    printf("\n\n****************************************\n\n");
    printf("%s", page_content);
    printf("\n\n****************************************\n\n");
}

/* Main function */
int main() {
    char ebook[MAX_PAGES][1000]; // array of pages, each page can have up to 1000 characters
    int num_pages = 0; // number of pages currently in the ebook
    int current_page = 0; // current page being displayed
    
    /* Display initial welcome message and instructions */
    printf("Welcome to the Ebook Reader!\n");
    printf("To navigate, use the following commands:\n");
    printf("n - go to the next page\n");
    printf("p - go to the previous page\n");
    printf("q - quit the program\n");
    
    /* Main loop */
    char input;
    do {
        /* Display current page */
        display_page(ebook[current_page]);
        
        /* Wait for user input */
        printf("Enter command: ");
        scanf(" %c", &input);
        
        /* Handle user input */
        switch (input) {
            case 'n': /* go to next page */
                if (current_page < num_pages - 1) {
                    current_page++;
                } else {
                    printf("Already on the last page.\n");
                }
                break;
            case 'p': /* go to previous page */
                if (current_page > 0) {
                    current_page--;
                } else {
                    printf("Already on the first page.\n");
                }
                break;
            case 'q': /* quit program */
                printf("Quitting program.\n");
                break;
            default: /* invalid command */
                printf("Invalid command.\n");
                break;
        }
    } while (input != 'q');
    
    return 0;
}