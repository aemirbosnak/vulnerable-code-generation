//FormAI DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_PUBLISHER_LENGTH 50

// Define a structure for each book in our library
typedef struct{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char publisher[MAX_PUBLISHER_LENGTH];
    int year_published;
} Book;

int main(){
    Book library[10];
    int num_books = 0;

    // Prompt the user to enter the title, author, publisher,
    // and year published for each book until they decide to 
    // stop entering books
    char choice = 'y';
    while(num_books < 10 && choice == 'y'){
        printf("Please enter the title of the book: ");
        fgets(library[num_books].title, MAX_TITLE_LENGTH, stdin);
        library[num_books].title[strcspn(library[num_books].title, "\n")] = 0;
        printf("Please enter the author of the book: ");
        fgets(library[num_books].author, MAX_AUTHOR_LENGTH, stdin);
        library[num_books].author[strcspn(library[num_books].author, "\n")] = 0;
        printf("Please enter the publisher of the book: ");
        fgets(library[num_books].publisher, MAX_PUBLISHER_LENGTH, stdin);
        library[num_books].publisher[strcspn(library[num_books].publisher, "\n")] = 0;
        printf("Please enter the year the book was published: ");
        scanf("%d", &library[num_books].year_published);
        getchar();  // consume the newline character left in stdin after reading the year
        num_books++;

        // Ask the user if they want to continue entering books
        printf("Enter another book? (y/n): ");
        scanf("%c", &choice);
        getchar();  // consume the newline character left in stdin after reading the choice
    }

    // Print out the contents of our library
    printf("Our library contains %d books:\n", num_books);
    for(int i=0; i<num_books; i++){
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Publisher: %s\n", library[i].publisher);
        printf("Year published: %d\n\n", library[i].year_published);
    }

    return 0;
}