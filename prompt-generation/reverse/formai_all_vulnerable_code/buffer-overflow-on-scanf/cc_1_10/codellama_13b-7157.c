//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: cheerful
// Ebook reader program in a cheerful style
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store book information
struct book {
  char title[50];
  char author[50];
  char genre[50];
  int pageCount;
};

// Function to display book information
void displayBook(struct book b) {
  printf("Title: %s\n", b.title);
  printf("Author: %s\n", b.author);
  printf("Genre: %s\n", b.genre);
  printf("Page Count: %d\n", b.pageCount);
}

// Function to search for a book by title
struct book* searchBookByTitle(struct book* books, int numBooks, char* title) {
  for (int i = 0; i < numBooks; i++) {
    if (strcmp(books[i].title, title) == 0) {
      return &books[i];
    }
  }
  return NULL;
}

// Function to search for a book by author
struct book* searchBookByAuthor(struct book* books, int numBooks, char* author) {
  for (int i = 0; i < numBooks; i++) {
    if (strcmp(books[i].author, author) == 0) {
      return &books[i];
    }
  }
  return NULL;
}

// Function to search for a book by genre
struct book* searchBookByGenre(struct book* books, int numBooks, char* genre) {
  for (int i = 0; i < numBooks; i++) {
    if (strcmp(books[i].genre, genre) == 0) {
      return &books[i];
    }
  }
  return NULL;
}

// Function to display the menu
void displayMenu() {
  printf("Welcome to the Ebook reader program!\n");
  printf("1. Search for a book by title\n");
  printf("2. Search for a book by author\n");
  printf("3. Search for a book by genre\n");
  printf("4. Display all books\n");
  printf("5. Exit\n");
}

int main() {
  // Array of books
  struct book books[] = {
    {"The C Programming Language", "Dennis Ritchie", "Computer Science", 200},
    {"The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 200},
    {"To Kill a Mockingbird", "Harper Lee", "Fiction", 100},
    {"The Alchemist", "Paulo Coelho", "Fiction", 100}
  };
  int numBooks = sizeof(books) / sizeof(struct book);

  // Loop until user chooses to exit
  int choice;
  while (1) {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Search for a book by title
    if (choice == 1) {
      char title[50];
      printf("Enter the title of the book: ");
      scanf("%s", title);
      struct book* book = searchBookByTitle(books, numBooks, title);
      if (book != NULL) {
        displayBook(*book);
      } else {
        printf("No book found with that title.\n");
      }
    }

    // Search for a book by author
    else if (choice == 2) {
      char author[50];
      printf("Enter the author's name: ");
      scanf("%s", author);
      struct book* book = searchBookByAuthor(books, numBooks, author);
      if (book != NULL) {
        displayBook(*book);
      } else {
        printf("No book found with that author.\n");
      }
    }

    // Search for a book by genre
    else if (choice == 3) {
      char genre[50];
      printf("Enter the genre of the book: ");
      scanf("%s", genre);
      struct book* book = searchBookByGenre(books, numBooks, genre);
      if (book != NULL) {
        displayBook(*book);
      } else {
        printf("No book found with that genre.\n");
      }
    }

    // Display all books
    else if (choice == 4) {
      for (int i = 0; i < numBooks; i++) {
        displayBook(books[i]);
      }
    }

    // Exit the program
    else if (choice == 5) {
      break;
    }
  }

  return 0;
}