//FormAI DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BOOKMARK 100

typedef struct {
    char title[50];
    char author[50];
    char filename[50];
} Book;

typedef struct {
    int page;
    char filename[50];
} Bookmark;

void print_book_info(Book book);
void print_bookmarks(Bookmark bookmarks[], int num_bookmarks);
int add_bookmark(Bookmark bookmarks[], int num_bookmarks, int page, char* filename);

int main() {
    int choice, num_books = 0, num_bookmarks = 0, page;
    char filename[MAX_FILENAME_LENGTH + 5];
    Book books[10];
    Bookmark bookmarks[MAX_BOOKMARK];

    while (1) {
        printf("\n1. Add book\n2. Open book\n3. Add bookmark\n4. View bookmarks\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_books == 10) {
                    printf("Maximum number of books reached\n");
                    break;
                }

                printf("Enter book title: ");
                scanf("%s", books[num_books].title);
                printf("Enter book author: ");
                scanf("%s", books[num_books].author);
                printf("Enter filename: ");
                scanf("%s", books[num_books].filename);

                num_books++;

                printf("Book added successfully\n");
                break;

            case 2:
                printf("Enter book filename: ");
                scanf("%s", filename);

                // Search for book with given filename
                for (int i = 0; i < num_books; i++) {
                    if (strcmp(books[i].filename, filename) == 0) {
                        printf("Opening %s by %s\n", books[i].title, books[i].author);

                        FILE* fp = fopen(filename, "r");
                        if (fp == NULL) {
                            printf("Could not open file\n");
                            break;
                        }

                        // Code to read book contents goes here

                        printf("Enter page number: ");
                        scanf("%d", &page);

                        // Add bookmark
                        num_bookmarks = add_bookmark(bookmarks, num_bookmarks, page, filename);
                        break;
                    }
                }

                break;

            case 3:
                if (num_bookmarks == MAX_BOOKMARK) {
                    printf("Maximum number of bookmarks reached\n");
                    break;
                }

                printf("Enter page number: ");
                scanf("%d", &page);
                printf("Enter filename: ");
                scanf("%s", filename);

                num_bookmarks = add_bookmark(bookmarks, num_bookmarks, page, filename);

                printf("Bookmark added successfully\n");
                break;

            case 4:
                if (num_bookmarks == 0) {
                    printf("No bookmarks found\n");
                    break;
                }

                print_bookmarks(bookmarks, num_bookmarks);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

// Print book information
void print_book_info(Book book) {
    printf("%s by %s\nFilename: %s\n", book.title, book.author, book.filename);
}

// Print bookmarks
void print_bookmarks(Bookmark bookmarks[], int num_bookmarks) {
    printf("Bookmarks:\n");

    for (int i = 0; i < num_bookmarks; i++) {
        printf("%d. Filename: %s, Page: %d\n", i+1, bookmarks[i].filename, bookmarks[i].page);
    }
}

// Add bookmark
int add_bookmark(Bookmark bookmarks[], int num_bookmarks, int page, char* filename) {
    bookmarks[num_bookmarks].page = page;
    strcpy(bookmarks[num_bookmarks].filename, filename);

    return num_bookmarks + 1;
}