//FormAI DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_CHAPTERS 20
#define MAX_PAGES 100

typedef struct page {
    int page_number;
    char text[MAX_PAGES];
} Page;

typedef struct chapter {
    int chapter_number;
    char title[MAX_TITLE_LENGTH];
    Page pages[MAX_PAGES];
    int num_pages;
} Chapter;

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    Chapter chapters[MAX_CHAPTERS];
    int num_chapters;
} Book;

Book* books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books < MAX_BOOKS) {
        Book* new_book = (Book*) malloc(sizeof(Book));
        if (new_book == NULL) {
            printf("Error: Out of memory.\n");
        }
        else {
            printf("Enter title of book: ");
            scanf("%49s", new_book->title);
            printf("Enter author of book: ");
            scanf("%29s", new_book->author);
            new_book->num_chapters = 0;
            books[num_books] = new_book;
            num_books++;
        }
    }
    else {
        printf("Error: Maximum number of books reached.\n");
    }
}

void add_chapter(Book* book) {
    if (book->num_chapters < MAX_CHAPTERS) {
        Chapter* new_chapter = (Chapter*) malloc(sizeof(Chapter));
        if (new_chapter == NULL) {
            printf("Error: Out of memory.\n");
        }
        else {
            printf("Enter title of chapter: ");
            scanf("%49s", new_chapter->title);
            new_chapter->chapter_number = book->num_chapters + 1;
            new_chapter->num_pages = 0;
            book->chapters[book->num_chapters] = *new_chapter;
            book->num_chapters++;
        }
    }
    else {
        printf("Error: Maximum number of chapters reached.\n");
    }
}

void add_page(Chapter* chapter) {
    if (chapter->num_pages < MAX_PAGES) {
        Page* new_page = (Page*) malloc(sizeof(Page));
        if (new_page == NULL) {
            printf("Error: Out of memory.\n");
        }
        else {
            printf("Enter text for page %d: ", chapter->num_pages + 1);
            scanf("%99s", new_page->text);
            new_page->page_number = chapter->num_pages + 1;
            chapter->pages[chapter->num_pages] = *new_page;
            chapter->num_pages++;
        }
    }
    else {
        printf("Error: Maximum number of pages reached.\n");
    }
}

void print_books() {
    printf("List of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s, by %s\n", i + 1, books[i]->title, books[i]->author);
    }
}

void print_chapters(Book* book) {
    printf("%s\n", book->title);
    for (int i = 0; i < book->num_chapters; i++) {
        printf("%d. %s\n", book->chapters[i].chapter_number, book->chapters[i].title);
    }
}

void print_pages(Chapter* chapter) {
    printf("%s\n", chapter->title);
    for (int i = 0; i < chapter->num_pages; i++) {
        printf("%d. %s\n", chapter->pages[i].page_number, chapter->pages[i].text);
    }
}

int main() {
    int choice = 0;
    while (choice != 5) {
        printf("1. Add book\n");
        printf("2. Add chapter\n");
        printf("3. Add page\n");
        printf("4. Print\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                print_books();
                printf("Enter number of book: ");
                scanf("%d", &choice);
                if (choice > 0 && choice <= num_books) {
                    add_chapter(books[choice - 1]);
                }
                else {
                    printf("Invalid choice.\n");
                }
                break;
            case 3:
                print_books();
                printf("Enter number of book: ");
                scanf("%d", &choice);
                if (choice > 0 && choice <= num_books) {
                    print_chapters(books[choice - 1]);
                    printf("Enter number of chapter: ");
                    scanf("%d", &choice);
                    if (choice > 0 && choice <= books[choice - 1]->num_chapters) {
                        add_page(&books[choice - 1]->chapters[choice - 1]);
                    }
                    else {
                        printf("Invalid choice.\n");
                    }
                }
                else {
                    printf("Invalid choice.\n");
                }
                break;
            case 4:
                print_books();
                printf("Enter number of book: ");
                scanf("%d", &choice);
                if (choice > 0 && choice <= num_books) {
                    print_chapters(books[choice - 1]);
                    printf("Enter number of chapter: ");
                    scanf("%d", &choice);
                    if (choice > 0 && choice <= books[choice - 1]->num_chapters) {
                        print_pages(&books[choice - 1]->chapters[choice - 1]);
                    }
                    else {
                        printf("Invalid choice.\n");
                    }
                }
                else {
                    printf("Invalid choice.\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    // free memory
    for (int i = 0; i < num_books; i++) {
        for (int j = 0; j < books[i]->num_chapters; j++) {
            free(books[i]->chapters[j].pages);
        }
        free(books[i]);
    }
    return 0;
}