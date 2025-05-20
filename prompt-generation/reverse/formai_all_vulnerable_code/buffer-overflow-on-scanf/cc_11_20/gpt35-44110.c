//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_PAGES 1000
#define MAX_PAGE_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int num_pages;
    char *pages[MAX_PAGES];
} Ebook;

int main(void) {
    Ebook my_book;
    int choice, page_num;

    // code for loading book information from file goes here

    while (1) {
        printf("1. Read ebook\n");
        printf("2. Go to page\n");
        printf("3. Quit\n");

        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                for (int i = 0; i < my_book.num_pages; i++) {
                    if (i % 50 == 0 && i != 0) {
                        printf("\nPress any key to continue reading...\n");
                        getchar();
                    }
                    printf("%s", my_book.pages[i]);
                    printf("-----------------------\n");
                }
                break;

            case 2:

                printf("Enter page number: ");
                scanf("%d", &page_num);

                if (page_num >= my_book.num_pages) {
                    printf("Page number is out of range.\n");
                    break;
                }

                for (int i = 0; i < my_book.num_pages; i++) {
                    if (i % 50 == 0 && i != 0) {
                        printf("\nPress any key to continue reading...\n");
                        getchar();
                    }
                    if (i == page_num) {
                        printf("%s", my_book.pages[i]);
                        printf("-----------------------\n");
                        break;
                    }
                }
                break;

            case 3:

                printf("Goodbye!\n");
                exit(0);

            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}