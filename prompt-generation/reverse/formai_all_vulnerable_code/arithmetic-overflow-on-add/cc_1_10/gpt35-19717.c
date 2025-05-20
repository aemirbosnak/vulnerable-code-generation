//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define PAGE_SIZE 1024

typedef struct Page {
    char content[PAGE_SIZE];
} Page;

typedef struct Book {
    char title[50];
    char author[50];
    Page pages[MAX_PAGES];
    int current_page;
    int num_pages;
} Book;

void print_menu() {
    printf("1. Open book\n");
    printf("2. Close book\n");
    printf("3. Go to next page\n");
    printf("4. Go to previous page\n");
    printf("5. Go to specific page\n");
    printf("6. Print page content\n");
    printf("7. Exit\n");
}

void open_book(Book* book) {
    printf("Enter title: ");
    scanf("%s", book->title);
    printf("Enter author: ");
    scanf("%s", book->author);
    printf("Enter number of pages (max %d): ", MAX_PAGES);
    int num_pages;
    scanf("%d", &num_pages);
    if (num_pages > MAX_PAGES) {
        printf("Error: too many pages\n");
        return;
    }
    book->num_pages = num_pages;
    for (int i = 0; i < num_pages; i++) {
        printf("Enter content of page %d: ", i+1);
        scanf("%s", book->pages[i].content);
    }
    book->current_page = 1;
    printf("Book opened successfully\n");
}

void close_book() {
    printf("Book closed successfully\n");
}

void next_page(Book* book) {
    if (book->current_page == book->num_pages) {
        printf("Error: already on last page\n");
        return;
    }
    book->current_page++;
    printf("Moved to page %d\n", book->current_page);
}

void prev_page(Book* book) {
    if (book->current_page == 1) {
        printf("Error: already on first page\n");
        return;
    }
    book->current_page--;
    printf("Moved to page %d\n", book->current_page);
}

void goto_page(Book* book) {
    int page_num;
    printf("Enter page number (1-%d): ", book->num_pages);
    scanf("%d", &page_num);
    if (page_num < 1 || page_num > book->num_pages) {
        printf("Error: invalid page number\n");
        return;
    }
    book->current_page = page_num;
    printf("Moved to page %d\n", book->current_page);
}

void print_page(Book* book) {
    printf("Page %d:\n%s\n", book->current_page, book->pages[book->current_page-1].content);
}

int main() {
    Book book;
    int choice = 0;
    while (choice != 7) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: open_book(&book);
                    break;
            case 2: close_book();
                    break;
            case 3: next_page(&book);
                    break;
            case 4: prev_page(&book);
                    break;
            case 5: goto_page(&book);
                    break;
            case 6: print_page(&book);
                    break;
            case 7: printf("Exiting...\n");
                    return 0;
            default: printf("Error: invalid choice\n");
                    break;
        }
    }
    return 0;
}