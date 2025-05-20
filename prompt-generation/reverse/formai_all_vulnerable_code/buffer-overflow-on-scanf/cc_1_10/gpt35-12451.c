//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    char* author;
    int pageCount;
} Book;

typedef struct {
    Book* books;
    int numBooks;
} Library;

int main() {
    Library library;
    int choice;
    int i;
    
    // Initialize library with some books
    Book book1 = {"The C Programming Language", "Brian Kernighan and Dennis Ritchie", 273};
    Book book2 = {"Effective C: An Introduction to Professional C Programming", "Robert C. Seacord", 304};
    Book book3 = {"C Programming Absolute Beginner's Guide (3rd Edition)", "Greg Perry and Dean Miller", 352};
    
    library.books = (Book*) malloc(3 * sizeof(Book));
    library.books[0] = book1;
    library.books[1] = book2;
    library.books[2] = book3;
    library.numBooks = 3;
    
    while (1) {
        printf("\nWelcome to the C Ebook Reader\n");
        printf("1. List all available books\n");
        printf("2. Search for a book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Available books:\n");
            for (i = 0; i < library.numBooks; i++) {
                printf("%d. %s by %s (%d pages)\n", i+1, library.books[i].title, library.books[i].author, library.books[i].pageCount);
            }
        } else if (choice == 2) {
            char searchTitle[100];
            printf("Enter the title of the book you want to search: ");
            scanf("%s", searchTitle);
            
            for (i = 0; i < library.numBooks; i++) {
                if (strcmp(searchTitle, library.books[i].title) == 0) {
                    printf("%s by %s (%d pages)\n", library.books[i].title, library.books[i].author, library.books[i].pageCount);
                    break;
                }
            }
            if (i == library.numBooks) {
                printf("Book not found\n");
            }
        } else if (choice == 3) {
            printf("Thank you for using C Ebook Reader. Goodbye!\n");
            break;
        } else {
            printf("Please enter a valid choice\n");
        }
    }

    free(library.books);
    return 0;
}