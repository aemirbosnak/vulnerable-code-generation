//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 1000

int main()
{
    int book[MAX_PAGES];
    int current_page = 1;
    int total_pages, selected_page;

    // Initialize the book
    printf("Enter total number of pages in the book: ");
    scanf("%d", &total_pages);

    for (int i = 1; i <= total_pages; i++) {
        book[i] = i;
    }

    // Start reading the book
    while (1) {
        // Print current page
        printf("You are currently on page %d of %d.\n", current_page, total_pages);

        // Ask for next action
        printf("What would you like to do?\n");
        printf("1. Turn to a specific page\n");
        printf("2. Go to the next page\n");
        printf("3. Go to the previous page\n");
        printf("4. Exit\n");

        int action;
        scanf("%d", &action);

        switch (action) {
            case 1:
                // Turn to specific page
                printf("Enter page number: ");
                scanf("%d", &selected_page);

                if (selected_page >= 1 && selected_page <= total_pages) {
                    current_page = selected_page;
                }
                else {
                    printf("Invalid page number.\n");
                }

                break;
            case 2:
                // Go to next page
                if (current_page < total_pages) {
                    current_page++;
                }
                else {
                    printf("You are at the end of the book.\n");
                }

                break;
            case 3:
                // Go to previous page
                if (current_page > 1) {
                    current_page--;
                }
                else {
                    printf("You are at the beginning of the book.\n");
                }

                break;
            case 4:
                // Exit
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}