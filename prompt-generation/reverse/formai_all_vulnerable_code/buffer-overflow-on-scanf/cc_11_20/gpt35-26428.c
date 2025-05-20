//FormAI DATASET v1.0 Category: Browser Plugin ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256
#define MAX_PAGES 100

/* Struct representing a web page */
typedef struct {
    char url[MAX_URL_LENGTH];
    bool visited;
} Page;

int main() {
    Page pages[MAX_PAGES];
    int num_pages = 0;

    while (true) {
        /* Get user input */
        char action;
        printf("Enter 'a' to add a page, 'v' to visit a page, or 'q' to quit: ");
        scanf("%c", &action);

        /* Handle user input */
        if (action == 'a') {
            /* Add a page */
            if (num_pages == MAX_PAGES) {
                printf("Sorry, you have reached the maximum number of pages.\n");
            } else {
                printf("Enter the URL of the page: ");
                char url[MAX_URL_LENGTH];
                scanf("%s", url);

                /* Check if page already exists */
                bool page_exists = false;
                for (int i = 0; i < num_pages; i++) {
                    if (strcmp(pages[i].url, url) == 0) {
                        page_exists = true;
                        break;
                    }
                }
                if (page_exists) {
                    printf("Sorry, that page already exists.\n");
                } else {
                    /* Add page to array */
                    Page new_page;
                    strcpy(new_page.url, url);
                    new_page.visited = false;
                    pages[num_pages] = new_page;
                    num_pages++;
                }
            }

        } else if (action == 'v') {
            /* Visit a page */
            if (num_pages == 0) {
                printf("Sorry, there are no pages to visit.\n");
            } else {
                printf("Enter the URL of the page to visit: ");
                char url[MAX_URL_LENGTH];
                scanf("%s", url);

                /* Find page in array and mark as visited */
                bool page_found = false;
                for (int i = 0; i < num_pages; i++) {
                    if (strcmp(pages[i].url, url) == 0) {
                        pages[i].visited = true;
                        page_found = true;
                        break;
                    }
                }
                if (page_found) {
                    printf("You have visited the page.\n");
                } else {
                    printf("Sorry, that page has not been added.\n");
                }
            }

        } else if (action == 'q') {
            /* Quit program */
            printf("Goodbye!\n");
            break;

        } else {
            /* Invalid input */
            printf("Sorry, that is not a valid action.\n");
        }

        /* Consume newline character from input buffer */
        while (getchar() != '\n');
    }

    return 0;
}