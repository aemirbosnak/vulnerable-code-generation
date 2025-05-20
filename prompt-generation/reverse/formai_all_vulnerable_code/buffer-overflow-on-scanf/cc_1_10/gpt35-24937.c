//FormAI DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 20
#define MAX_BOOK_TITLE_SIZE 50
#define MAX_BOOK_AUTHOR_SIZE 50

typedef struct {
   char title[MAX_BOOK_TITLE_SIZE];
   char author[MAX_BOOK_AUTHOR_SIZE];
   int pages;
   double rating;
} Book;

void displayMainMenu();
void addBook(Book books[], int *bookCount);
void displayBooks(Book books[], int bookCount);
void removeBook(Book books[], int *bookCount);
void searchBook(Book books[], int bookCount);

int main() {
   Book books[MAX_BOOKS];
   int bookCount = 0;
   int menuChoice;
    
   while (1) {
       displayMainMenu();
       scanf("%d", &menuChoice);
       
       switch(menuChoice) {
           case 1:
               addBook(books, &bookCount);
               break;
               
           case 2:
               displayBooks(books, bookCount);
               break;
               
           case 3:
               removeBook(books, &bookCount);
               break;
               
           case 4:
               searchBook(books, bookCount);
               break;
               
           case 5:
               printf("Exiting program.\n");
               return 0;
               
           default:
               printf("Invalid choice. Please try again.\n");
               break;
       }
   }
}

void displayMainMenu() {
   printf("\n********** Ebook Reader **********\n");
   printf("1. Add book\n");
   printf("2. Display all books\n");
   printf("3. Remove book\n");
   printf("4. Search book\n");
   printf("5. Exit\n\n");
   printf("Enter choice: ");
}

void addBook(Book books[], int *bookCount) {
   if (*bookCount == MAX_BOOKS) {
       printf("Sorry, maximum number of books have been reached.\n");
       return;
   }
   
   char title[MAX_BOOK_TITLE_SIZE];
   char author[MAX_BOOK_AUTHOR_SIZE];
   int pages;
   double rating;
   
   printf("Enter book title: ");
   scanf("%s", title);
   
   printf("Enter book author: ");
   scanf("%s", author);
   
   printf("Enter number of pages: ");
   scanf("%d", &pages);
   
   printf("Enter book rating (out of 5): ");
   scanf("%lf", &rating);
   
   strcpy(books[*bookCount].title, title);
   strcpy(books[*bookCount].author, author);
   books[*bookCount].pages = pages;
   books[*bookCount].rating = rating;
   (*bookCount)++;
   
   printf("Book successfully added!\n");
}

void displayBooks(Book books[], int bookCount) {
   if (bookCount == 0) {
       printf("No books found.\n");
       return;
   }
   
   printf("\nAll books:\n");
   
   for (int i = 0; i < bookCount; i++) {
       printf("\nTitle: %s\n", books[i].title);
       printf("Author: %s\n", books[i].author);
       printf("Pages: %d\n", books[i].pages);
       printf("Rating: %.1lf\n", books[i].rating);
   }
}

void removeBook(Book books[], int *bookCount) {
   if (*bookCount == 0) {
       printf("No books found.\n");
       return;
   }
   
   char title[MAX_BOOK_TITLE_SIZE];
   printf("Enter book title to remove: ");
   scanf("%s", title);
   
   for (int i = 0; i < *bookCount; i++) {
       if (strcmp(books[i].title, title) == 0) {
           printf("Book '%s' successfully removed.\n", title);
           
           for (int j = i; j < *bookCount - 1; j++) {
               strcpy(books[j].title, books[j+1].title);
               strcpy(books[j].author, books[j+1].author);
               books[j].pages = books[j+1].pages;
               books[j].rating = books[j+1].rating;
           }
           
           (*bookCount)--;
           return;
       }
   }
   
   printf("Book '%s' not found.\n", title);
}

void searchBook(Book books[], int bookCount) {
   if (bookCount == 0) {
       printf("No books found.\n");
       return;
   }
   
   char title[MAX_BOOK_TITLE_SIZE];
   printf("Enter book title to search for: ");
   scanf("%s", title);
   
   for (int i = 0; i < bookCount; i++) {
       if (strcmp(books[i].title, title) == 0) {
           printf("\nBook found:\n");
           printf("Title: %s\n", books[i].title);
           printf("Author: %s\n", books[i].author);
           printf("Pages: %d\n", books[i].pages);
           printf("Rating: %.1lf\n", books[i].rating);
           return;
       }
   }
   
   printf("Book '%s' not found.\n", title);
}