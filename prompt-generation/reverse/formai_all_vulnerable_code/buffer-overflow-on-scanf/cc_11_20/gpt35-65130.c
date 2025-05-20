//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int currentPage;
    int totalPages;
    char content[MAX_PAGES];
} Book;

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;
    int choice, bookIndex;

    while(1) {
        printf("Ebook Reader:\n");
        printf("1. Add a new book\n");
        printf("2. Open a book\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add a new book
                if(numBooks >= MAX_BOOKS) {
                    printf("Maximum number of books reached.\n");
                    break;
                }
                
                printf("Enter the book title: ");
                scanf("%s", books[numBooks].title);
                
                printf("Enter the author name: ");
                scanf("%s", books[numBooks].author);
                
                printf("Enter the total number of pages: ");
                scanf("%d", &books[numBooks].totalPages);
                
                printf("Enter the content of the book: ");
                scanf("%s", books[numBooks].content);

                books[numBooks].currentPage = 0;
                numBooks++;

                printf("Book added successfully.\n");
                break;

            case 2: // Open a book
                printf("Enter the book title: ");
                scanf("%s", books[numBooks].title);

                for(bookIndex = 0; bookIndex < numBooks; bookIndex++) {
                    if(strcmp(books[bookIndex].title, books[numBooks].title) == 0) {
                        break;
                    }
                }

                if(bookIndex == numBooks) {
                    printf("Book not found.\n");
                    break;
                }

                printf("Book Details:\n");
                printf("Title: %s\n", books[bookIndex].title);
                printf("Author: %s\n", books[bookIndex].author);
                printf("Total pages: %d\n", books[bookIndex].totalPages);

                while(1) {
                    printf("\nCurrent Page: %d / Total Pages: %d\n", books[bookIndex].currentPage + 1, books[bookIndex].totalPages);
                    printf("1. Go to next page\n");
                    printf("2. Go to previous page\n");
                    printf("3. Go to specific page\n");
                    printf("4. Close book\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            if(books[bookIndex].currentPage < books[bookIndex].totalPages - 1) {
                                books[bookIndex].currentPage++;
                            } else {
                                printf("You have reached the last page.\n");
                            }
                            break;

                        case 2:
                            if(books[bookIndex].currentPage > 0) {
                                books[bookIndex].currentPage--;
                            } else {
                                printf("You are already on the first page.\n");
                            }
                            break;

                        case 3:
                            printf("Enter the page number you want to go to: ");
                            scanf("%d", &books[bookIndex].currentPage);
                            books[bookIndex].currentPage--;

                            if(books[bookIndex].currentPage < 0 || books[bookIndex].currentPage >= books[bookIndex].totalPages) {
                                printf("Invalid page number.\n");
                                books[bookIndex].currentPage = 0;
                            }
                            break;

                        case 4:
                            printf("Closing book.\n");
                            break;

                        default:
                            printf("Invalid choice.\n");
                            break;
                    }

                    if(choice == 4) {
                        break;
                    }
                }

                break;

            case 3: // Exit
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0; 
}