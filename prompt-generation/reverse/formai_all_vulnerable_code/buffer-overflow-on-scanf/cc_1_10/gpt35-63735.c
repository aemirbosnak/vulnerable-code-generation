//FormAI DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#define MAX_PAGES 1000
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int page_count;
} Ebook;

int main() {
    Ebook my_book;
    int current_page = 1;
    int user_choice;

    printf("Welcome to the Ebook reader!\n");
    printf("Please enter the title of your Ebook: ");
    fgets(my_book.title, MAX_TITLE_LENGTH, stdin);

    printf("How many pages does your Ebook have? ");
    scanf("%d", &my_book.page_count);

    printf("The Ebook '%s' has %d pages.\n", my_book.title, my_book.page_count);

    while (current_page >= 1 && current_page <= my_book.page_count) {
        printf("You are on page %d. What would you like to do?\n", current_page);
        printf("1. Go to a specific page\n");
        printf("2. Turn to the next page\n");
        printf("3. Turn to the previous page\n");
        printf("4. Exit the Ebook reader\n");

        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                printf("Enter the page number you'd like to go to:\n");
                scanf("%d", &current_page);
                break;
            case 2:
                current_page++;
                break;
            case 3:
                current_page--;
                break;
            case 4:
                printf("Exiting Ebook reader. Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    printf("You reached the end of the Ebook. Exiting reader. Goodbye!\n");
    return EXIT_SUCCESS;
}