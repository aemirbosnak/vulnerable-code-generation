//FormAI DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of books in the library
#define MAX_BOOKS 50

// Book struct definition
typedef struct Book {
  int ID;
  char title[50];
  char author[50];
  int pages;
} Book;

// Creates an empty Book struct
Book createBook() {
  Book book;
  book.ID = 0;
  memset(book.title, 0, sizeof(book.title));
  memset(book.author, 0, sizeof(book.author));
  book.pages = 0;

  return book;
}

// Main function
int main() {
  // Declare variables
  int bookCount = 0; // Number of books in the library
  Book library[MAX_BOOKS]; // Book library array

  // Print intro message
  printf("Welcome to the Retro Music Library Management System!\n");

  // Main menu loop
  while (1) {
    printf("\n");
    printf("1. Add Book\n");
    printf("2. Edit Book\n");
    printf("3. Remove Book\n");
    printf("4. List Books\n");
    printf("5. Exit\n");
    printf("Select an option: ");

    // Get user input
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      // Add a book
      case 1: {
        // Check if maximum books reached
        if (bookCount == MAX_BOOKS) {
          printf("Error: Maximum books reached.\n");
          break;
        }

        // Create a new book
        Book book = createBook();

        // Get book details from user
        printf("Enter Book ID: ");
        scanf("%d", &book.ID);
        printf("Enter Book Title: ");
        scanf(" %[^\n]", book.title);
        printf("Enter Book Author: ");
        scanf(" %[^\n]", book.author);
        printf("Enter Book Pages: ");
        scanf("%d", &book.pages);

        // Add book to library
        library[bookCount] = book;
        bookCount++;

        printf("Book added successfully.\n");
        break;
      }

      // Edit a book
      case 2: {
        // Check if library is empty
        if (bookCount == 0) {
          printf("Error: Library is empty.\n");
          break;
        }

        // Get book ID to edit
        int id;
        printf("Enter Book ID to edit: ");
        scanf("%d", &id);

        // Find book in library
        int index = -1;
        for (int i = 0; i < bookCount; i++) {
          if (library[i].ID == id) {
            index = i;
            break;
          }
        }

        // Check if book was found
        if (index == -1) {
          printf("Error: Book not found.\n");
          break;
        }

        // Get updated book details from user
        printf("Enter Book Title (Leave blank to keep as \"%s\"): ", library[index].title);
        scanf(" %[^\n]", library[index].title);
        printf("Enter Book Author (Leave blank to keep as \"%s\"): ", library[index].author);
        scanf(" %[^\n]", library[index].author);
        printf("Enter Book Pages (Enter 0 to keep as %d): ", library[index].pages);
        scanf("%d", &library[index].pages);

        printf("Book edited successfully.\n");
        break;
      }

      // Remove a book
      case 3: {
        // Check if library is empty
        if (bookCount == 0) {
          printf("Error: Library is empty.\n");
          break;
        }

        // Get book ID to remove
        int id;
        printf("Enter Book ID to remove: ");
        scanf("%d", &id);

        // Find book in library
        int index = -1;
        for (int i = 0; i < bookCount; i++) {
          if (library[i].ID == id) {
            index = i;
            break;
          }
        }

        // Check if book was found
        if (index == -1) {
          printf("Error: Book not found.\n");
          break;
        }

        // Remove book from library
        for (int i = index; i < bookCount - 1; i++) {
          library[i] = library[i + 1];
        }
        bookCount--;

        printf("Book removed successfully.\n");
        break;
      }

      // List all books
      case 4: {
        // Check if library is empty
        if (bookCount == 0) {
          printf("Library is empty.\n");
          break;
        }

        // Print library header
        printf("%3s %-30s %-20s %4s\n", "ID", "Title", "Author", "Pages");

        // Print each book in library
        for (int i = 0; i < bookCount; i++) {
          printf("%3d %-30s %-20s %4d\n", library[i].ID, library[i].title, library[i].author, library[i].pages);
        }
        break;
      }

      // Exit program
      case 5: {
        printf("Thank you for using the Retro Music Library Management System!\n");
        exit(0);
      }

      // Invalid option
      default: {
        printf("Error: Invalid option.\n");
        break;
      }
    }
  }

  return 0;
}