//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>

#define MAX_EBOOK_TITLE_LEN 100
#define MAX_EBOOK_PAGES 1000

struct Ebook {
    char title[MAX_EBOOK_TITLE_LEN];
    char author[MAX_EBOOK_TITLE_LEN];
    int num_pages;
    char pages[MAX_EBOOK_PAGES][1000];
};

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Load Ebook\n");
    printf("2. Display Ebook Information\n");
    printf("3. Read Next Page\n");
    printf("4. Exit\n");
}

void load_ebook(struct Ebook *book) {
    printf("\nEnter Ebook title: ");
    scanf("%s", book->title);
    printf("Enter Ebook author: ");
    scanf("%s", book->author);
    printf("Enter Ebook number of pages: ");
    scanf("%d", &book->num_pages);
    printf("Enter Ebook contents (one page per line):\n");
    for (int i = 0; i < book->num_pages; i++) {
        scanf("%s", book->pages[i]);
    }
}

void display_ebook_info(struct Ebook book) {
    printf("\nEbook title: %s\n", book.title);
    printf("Ebook author: %s\n", book.author);
    printf("Number of pages: %d\n", book.num_pages);
}

void read_next_page(struct Ebook book, int *current_page) {
    if (*current_page >= book.num_pages) {
        printf("\nYou have reached the end of the Ebook.\n");
        return;
    }
    printf("\n--Page %d--\n", *current_page + 1);
    printf("%s\n", book.pages[*current_page]);
    (*current_page)++;
}

int main() {
    struct Ebook book;
    int current_page = 0;
    int choice = 0;

    while (choice != 4) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                load_ebook(&book);
                break;
            case 2:
                display_ebook_info(book);
                break;
            case 3:
                read_next_page(book, &current_page);
                break;
            case 4:
                printf("\nExiting Ebook reader.\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}