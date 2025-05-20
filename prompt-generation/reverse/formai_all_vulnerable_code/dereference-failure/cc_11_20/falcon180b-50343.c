//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BOOK_NAME 100

typedef struct {
    char name[MAX_BOOK_NAME];
    int pages;
    int read_pages;
} Book;

int main() {
    int num_books, i;
    printf("Enter the number of books: ");
    scanf("%d", &num_books);
    
    Book *books = (Book *)malloc(num_books * sizeof(Book));
    
    for (i = 0; i < num_books; i++) {
        printf("Enter the name of book %d: ", i+1);
        scanf("%s", books[i].name);
        printf("Enter the number of pages: ");
        scanf("%d", &books[i].pages);
        books[i].read_pages = 0;
    }
    
    int choice;
    while (1) {
        printf("\n1. Read a book\n2. Quit\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter the name of the book you want to read: ");
            char book_name[MAX_BOOK_NAME];
            scanf("%s", book_name);
            
            int j;
            for (j = 0; j < num_books; j++) {
                if (strcmp(book_name, books[j].name) == 0) {
                    break;
                }
            }
            
            if (j == num_books) {
                printf("Book not found!\n");
            }
            else {
                printf("Reading %s...\n", books[j].name);
                int page;
                while (1) {
                    printf("Enter the page number you want to read (0 to quit): ");
                    scanf("%d", &page);
                    
                    if (page == 0) {
                        break;
                    }
                    
                    if (page > books[j].pages) {
                        printf("Page out of range!\n");
                        continue;
                    }
                    
                    books[j].read_pages += page;
                    printf("You have read %d pages of %s.\n", books[j].read_pages, books[j].name);
                }
            }
        }
        else if (choice == 2) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    
    free(books);
    return 0;
}