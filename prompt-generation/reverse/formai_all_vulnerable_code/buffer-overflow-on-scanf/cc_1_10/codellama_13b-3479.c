//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
// Ebook reader program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct {
  char title[100];
  char author[50];
  char genre[50];
  int pages;
  float price;
} Book;

// Function to display a book
void display_book(Book book) {
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Genre: %s\n", book.genre);
  printf("Pages: %d\n", book.pages);
  printf("Price: $%.2f\n", book.price);
}

// Function to add a book to the library
void add_book(Book *library, int *size, int *capacity) {
  // Check if the library is full
  if (*size == *capacity) {
    printf("Library is full, please remove a book before adding a new one.\n");
    return;
  }

  // Prompt for book details
  printf("Enter book details:\n");
  printf("Title: ");
  scanf("%s", library[*size].title);
  printf("Author: ");
  scanf("%s", library[*size].author);
  printf("Genre: ");
  scanf("%s", library[*size].genre);
  printf("Pages: ");
  scanf("%d", &library[*size].pages);
  printf("Price: ");
  scanf("%f", &library[*size].price);

  // Increment size
  (*size)++;
}

// Function to remove a book from the library
void remove_book(Book *library, int *size, int *capacity) {
  // Check if the library is empty
  if (*size == 0) {
    printf("Library is empty, please add a book before removing one.\n");
    return;
  }

  // Prompt for book index
  printf("Enter book index: ");
  int index;
  scanf("%d", &index);

  // Check if the index is valid
  if (index < 0 || index >= *size) {
    printf("Invalid index, please try again.\n");
    return;
  }

  // Remove the book
  for (int i = index; i < *size - 1; i++) {
    library[i] = library[i + 1];
  }

  // Decrement size
  (*size)--;
}

// Function to search for a book in the library
void search_book(Book *library, int size) {
  // Prompt for book title
  printf("Enter book title: ");
  char title[100];
  scanf("%s", title);

  // Search for the book
  int found = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(library[i].title, title) == 0) {
      found = 1;
      display_book(library[i]);
      break;
    }
  }

  // Print message if the book is not found
  if (!found) {
    printf("Book not found in the library.\n");
  }
}

int main() {
  // Initialize library
  int size = 0;
  int capacity = 10;
  Book library[capacity];

  // Loop until the user quits
  char choice;
  do {
    // Display menu
    printf("Ebook reader\n");
    printf("1. Add book\n");
    printf("2. Remove book\n");
    printf("3. Search book\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    // Execute the selected option
    switch (choice) {
    case '1':
      add_book(library, &size, &capacity);
      break;
    case '2':
      remove_book(library, &size, &capacity);
      break;
    case '3':
      search_book(library, size);
      break;
    case '4':
      break;
    default:
      printf("Invalid choice, please try again.\n");
    }
  } while (choice != '4');

  return 0;
}