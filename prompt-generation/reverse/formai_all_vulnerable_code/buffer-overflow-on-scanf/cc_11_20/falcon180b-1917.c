//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BOOKS 10

typedef struct {
    char title[100];
    char author[100];
    char genre[100];
    char description[1000];
    char file_path[100];
} Book;

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;

    char choice;
    do {
        printf("Welcome to the eBook Reader!\n");
        printf("What would you like to do?\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. View library\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_books >= MAX_BOOKS) {
                    printf("Library is full!\n");
                } else {
                    printf("Enter book title: ");
                    scanf("%s", library[num_books].title);
                    printf("Enter book author: ");
                    scanf("%s", library[num_books].author);
                    printf("Enter book genre: ");
                    scanf("%s", library[num_books].genre);
                    printf("Enter book description: ");
                    scanf("%s", library[num_books].description);
                    printf("Enter book file path: ");
                    scanf("%s", library[num_books].file_path);
                    num_books++;
                }
                break;
            case '2':
                if(num_books == 0) {
                    printf("Library is empty!\n");
                } else {
                    printf("Enter book to remove: ");
                    char book_title[100];
                    scanf("%s", book_title);
                    int i;
                    for(i = 0; i < num_books; i++) {
                        if(strcmp(library[i].title, book_title) == 0) {
                            memset(&library[i], 0, sizeof(Book));
                            num_books--;
                            break;
                        }
                    }
                }
                break;
            case '3':
                printf("Library:\n");
                for(int i = 0; i < num_books; i++) {
                    printf("Title: %s\n", library[i].title);
                    printf("Author: %s\n", library[i].author);
                    printf("Genre: %s\n", library[i].genre);
                    printf("Description: %s\n", library[i].description);
                    printf("File path: %s\n", library[i].file_path);
                    printf("\n");
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '4');

    return 0;
}