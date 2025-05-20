//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    char* author;
    int pages;
} book;

void print_book(book* b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Pages: %d\n\n", b->pages);
}

int main() {
    book* library = NULL;
    int num_books = 0;
    char choice;

    do {
        printf("Welcome to the Ebook Reader!\n");
        printf("Please select an option:\n");
        printf("1. Add book\n");
        printf("2. Remove book\n");
        printf("3. Print library\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                library = realloc(library, sizeof(book)*++num_books);
                library[num_books-1].title = malloc(100*sizeof(char));
                library[num_books-1].author = malloc(100*sizeof(char));
                printf("Enter book title:\n");
                scanf("%s", library[num_books-1].title);
                printf("Enter author:\n");
                scanf("%s", library[num_books-1].author);
                printf("Enter number of pages:\n");
                scanf("%d", &library[num_books-1].pages);
                break;
            case '2':
                printf("Enter book index to remove:\n");
                int index;
                scanf("%d", &index);
                if(index >= 0 && index < num_books) {
                    free(library[index].title);
                    free(library[index].author);
                    library = realloc(library, sizeof(book)*--num_books);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case '3':
                for(int i=0; i<num_books; i++) {
                    print_book(&library[i]);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}