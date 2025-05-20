//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: imaginative
// Imaginary C Ebook Reader Example Program

#include <stdio.h>
#include <string.h>

// Structure to hold book information
struct Book {
  char title[50];
  char author[50];
  char publisher[50];
  char genre[50];
  int pages;
  int year;
};

// Structure to hold bookshelf information
struct Bookshelf {
  int capacity;
  struct Book* books;
};

// Function to create a new bookshelf
struct Bookshelf* createBookshelf(int capacity) {
  struct Bookshelf* bookshelf = malloc(sizeof(struct Bookshelf));
  bookshelf->capacity = capacity;
  bookshelf->books = malloc(sizeof(struct Book) * capacity);
  return bookshelf;
}

// Function to add a book to a bookshelf
void addBook(struct Bookshelf* bookshelf, struct Book book) {
  if (bookshelf->capacity == 0) {
    printf("Bookshelf is full. Cannot add more books.\n");
    return;
  }

  bookshelf->books[bookshelf->capacity - 1] = book;
  bookshelf->capacity--;
}

// Function to remove a book from a bookshelf
void removeBook(struct Bookshelf* bookshelf, int index) {
  if (index >= bookshelf->capacity) {
    printf("Index is out of bounds. Cannot remove book.\n");
    return;
  }

  bookshelf->books[index] = bookshelf->books[bookshelf->capacity - 1];
  bookshelf->capacity++;
}

// Function to display the books on a bookshelf
void displayBooks(struct Bookshelf* bookshelf) {
  for (int i = 0; i < bookshelf->capacity; i++) {
    printf("Book %d: %s by %s (%s, %d pages, %d)\n", i + 1, bookshelf->books[i].title, bookshelf->books[i].author, bookshelf->books[i].publisher, bookshelf->books[i].pages, bookshelf->books[i].year);
  }
}

int main() {
  struct Bookshelf* bookshelf = createBookshelf(10);
  struct Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Fiction", 248, 1925};
  struct Book book2 = {"To Kill a Mockingbird", "Harper Lee", "Random House", "Fiction", 304, 1960};
  struct Book book3 = {"The Catcher in the Rye", "J.D. Salinger", "Viking Press", "Fiction", 234, 1951};

  addBook(bookshelf, book1);
  addBook(bookshelf, book2);
  addBook(bookshelf, book3);

  displayBooks(bookshelf);

  removeBook(bookshelf, 1);

  displayBooks(bookshelf);

  return 0;
}