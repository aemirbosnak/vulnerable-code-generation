//FormAI DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[100];
    char author[100];
    char file_name[100];
}Book;

void display_menu() {
  printf("\n----------MENU----------\n");
  printf("1. Open an Ebook for reading\n");
  printf("2. Display all Ebooks in the library\n");
  printf("3. Add a new Ebook to the library\n");
  printf("4. Quit\n");
}

void open_book(Book *books, int num_books) {
    char search[100];
    printf("Enter the title or author of the book you want to read: ");
    scanf(" %[^\n]", search);
    int found = 0;
    for(int i=0; i<num_books; i++) {
        if(strstr(books[i].title, search) || strstr(books[i].author, search)) {
            printf("Opening %s\n", books[i].title);
            FILE *file = fopen(books[i].file_name, "r");
            if(file) {
              printf("\n----------%s----------\n", books[i].title);
              char line[200];
              while(fgets(line, 200, file)) {
                  printf("%s", line);
              }
            } else {
              printf("%s not found in library.\n", search);
            }
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("%s not found in library.\n", search);
    }
}

void display_books(Book *books, int num_books) {
    printf("\n----------LIBRARY----------\n");
    for(int i=0; i<num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
}

void add_book(Book *books, int *num_books) {
    printf("Enter the title of the book: ");
    scanf(" %[^\n]", books[*num_books].title);
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", books[*num_books].author);
    printf("Enter the file name (with extension) of the book: ");
    scanf(" %[^\n]", books[*num_books].file_name);
    *num_books += 1;
}

int main() {
    Book books[10];
    int num_books = 0;
    int choice;
    
    printf("Welcome to the Ebook library!\n");
    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                open_book(books, num_books);
                break;
            case 2:
                display_books(books, num_books);
                break;
            case 3:
                add_book(books, &num_books);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}