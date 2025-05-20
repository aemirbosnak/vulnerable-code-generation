//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[30];
    char author[30];
    char filename[30];
} book;

void search_books(book books[], int book_count);
void read_book(book selected_book);
void display_books(book books[], int book_count);

int main(){
    book books[5];
    books[0] = (book) {"The Catcher in the Rye", "J.D. Salinger", "catcher.txt"};
    books[1] = (book) {"The Great Gatsby", "F. Scott Fitzgerald", "gatsby.txt"};
    books[2] = (book) {"To Kill a Mockingbird", "Harper Lee", "mockingbird.txt"};
    books[3] = (book) {"1984", "George Orwell", "1984.txt"};
    books[4] = (book) {"Animal Farm", "George Orwell", "animal_farm.txt"};

    int book_count = 5;
    int choice = 0;

    while(choice != 3){
        printf("\nWelcome to the Ebook Reader!\n");
        printf("Please select one of the following options:\n");
        printf(" 1. Search for a book\n");
        printf(" 2. Display all books\n");
        printf(" 3. Exit\n");

        printf("\nYour choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            search_books(books, book_count);
        }
        else if(choice == 2){
            display_books(books, book_count);
        }
        else if(choice == 3){
            printf("\nThank you for using the Ebook Reader!");
        }
        else{
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void search_books(book books[], int book_count){
    char search_term[30];

    printf("\nEnter the title or author of the book you want to find: ");
    scanf("%s", search_term);

    for(int i = 0; i < book_count; i++){
        if(strstr(books[i].title, search_term) != NULL || strstr(books[i].author, search_term) != NULL){
            printf("\nBook found!\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Press enter to read the book.\n");
            getchar();
            read_book(books[i]);
            return;
        }
    }

    printf("\nBook not found.\n");
}

void read_book(book selected_book){
    FILE *book_file = fopen(selected_book.filename, "r");

    char line[256];

    printf("\nThe first 10 lines of %s:\n\n", selected_book.title);

    for(int i = 0; i < 10; i++){
        if(fgets(line, 256, book_file) != NULL){
            printf("%s", line);
        }
        else{
            break;
        }
    }

    fclose(book_file);
}

void display_books(book books[], int book_count){
    printf("\nThe available books are:\n");

    for(int i = 0; i < book_count; i++){
        printf(" %d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
}