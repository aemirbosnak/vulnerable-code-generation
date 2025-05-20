//FormAI DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[100];
    int pages;
};

void displayBook(struct Book b) {
    printf("\nTitle: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
}

int main() {
    // create an array of books
    struct Book library[5];
    
    // add books to the library
    strcpy(library[0].title, "Brave New World");
    strcpy(library[0].author, "Aldous Huxley");
    library[0].pages = 311;
    
    strcpy(library[1].title, "To Kill a Mockingbird");
    strcpy(library[1].author, "Harper Lee");
    library[1].pages = 281;
    
    strcpy(library[2].title, "1984");
    strcpy(library[2].author, "George Orwell");
    library[2].pages = 328;
    
    strcpy(library[3].title, "One Hundred Years of Solitude");
    strcpy(library[3].author, "Gabriel Garcia Marquez");
    library[3].pages = 417;
    
    strcpy(library[4].title, "The Catcher in the Rye");
    strcpy(library[4].author, "J.D. Salinger");
    library[4].pages = 277;
    
    // display the books
    printf("The library contains the following books:\n");
    int i;
    for (i = 0; i < 5; i++) {
        displayBook(library[i]);
    }
    
    // select a book to read
    printf("\nEnter the number of the book you would like to read: ");
    int selection;
    scanf("%d", &selection);
    
    // display the selected book
    printf("\nYou have selected the following book:\n");
    displayBook(library[selection]);
    
    // open the ebook
    printf("\nOpening ebook...\n");
    printf("Title: %s\n", library[selection].title);
    printf("Author: %s\n", library[selection].author);
    printf("Number of pages: %d\n", library[selection].pages);
    printf("Enjoy your read!\n");
    
    return 0;
}