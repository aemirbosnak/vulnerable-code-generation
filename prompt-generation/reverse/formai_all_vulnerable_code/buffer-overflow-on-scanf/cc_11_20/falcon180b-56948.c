//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[50];
    char genre[50];
    int pages;
} book;

int main() {
    int choice, num_books = 0, search_result = 0;
    char input[100];
    book library[MAX_BOOKS];

    printf("Welcome to the Happy Library!\n");
    printf("Please choose an option:\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search for a book\n");
    printf("4. Exit\n");

    while(1) {
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_books >= MAX_BOOKS) {
                    printf("Sorry, the library is full!\n");
                } else {
                    printf("Enter book title: ");
                    scanf("%s", library[num_books].title);
                    printf("Enter author: ");
                    scanf("%s", library[num_books].author);
                    printf("Enter genre: ");
                    scanf("%s", library[num_books].genre);
                    printf("Enter number of pages: ");
                    scanf("%d", &library[num_books].pages);
                    num_books++;
                }
                break;

            case 2:
                printf("All books in the library:\n");
                for(int i=0; i<num_books; i++) {
                    printf("%d. %s by %s (%s) - %d pages\n", i+1, library[i].title, library[i].author, library[i].genre, library[i].pages);
                }
                break;

            case 3:
                printf("Enter book title to search: ");
                scanf("%s", input);
                for(int i=0; i<num_books; i++) {
                    if(strcmp(library[i].title, input) == 0) {
                        printf("%d. %s by %s (%s) - %d pages\n", i+1, library[i].title, library[i].author, library[i].genre, library[i].pages);
                        search_result = 1;
                    }
                }
                if(search_result == 0) {
                    printf("Book not found.\n");
                }
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}