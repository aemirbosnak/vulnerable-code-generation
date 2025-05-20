//FormAI DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_TITLE 30
#define MAX_AUTHOR 20
#define MAX_BOOKS 100

struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int num_pages;
};

typedef struct Book BOOK;

int main()
{
    int book_count = 0;
    BOOK library[MAX_BOOKS];
    
    while(1) {
        printf("1. Add book\n2. Read book\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        if(choice == 1) {   
            if(book_count == MAX_BOOKS) {
                printf("Sorry, library is full\n");
                continue;
            }
            
            BOOK new_book;
            printf("Enter book title: ");
            scanf("%s", new_book.title);
            printf("Enter author name: ");
            scanf("%s", new_book.author);
            printf("Enter number of pages: ");
            scanf("%d", &new_book.num_pages);
            
            library[book_count] = new_book;
            book_count++;
            printf("Book added to library\n");
            
        } else if(choice == 2) {
            if(book_count == 0) {
                printf("Sorry, library is empty\n");
                continue;
            }
            
            printf("Enter book title: ");
            char title[MAX_TITLE];
            scanf("%s", title);
            
            for(int i = 0; i < book_count; i++) {
                if(strcmp(library[i].title, title) == 0) {
                    printf("Reading book...\n");
                    printf("Title: %s\nAuthor: %s\nNumber of Pages: %d\n", 
                           library[i].title, library[i].author, library[i].num_pages);
                    break;
                } else if(i == book_count - 1) {
                    printf("Sorry, book not found\n");
                }
            }
            
        } else if(choice == 3) {
            printf("Exiting ebook reader...\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
        
        printf("\n");
    }
    
    return 0;
}