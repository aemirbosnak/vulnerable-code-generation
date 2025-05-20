//FormAI DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Book {
  char title[50];
  char author[50];
  char genre[20];
  int year;
  float price;
};

void printBook(struct Book *book) {
  printf("Title: %s\n", book->title);
  printf("Author: %s\n", book->author);
  printf("Genre: %s\n", book->genre);
  printf("Year: %d\n", book->year);
  printf("Price: %.2f\n", book->price);
}

int main(void) {
  struct Book myLibrary[3] = {
      {"The Catcher in the Rye", "J.D. Salinger", "Fiction", 1951, 9.99f},
      {"To Kill a Mockingbird", "Harper Lee", "Fiction", 1960, 11.49f},
      {"The War of the Worlds", "H.G. Wells", "Science Fiction", 1898, 7.99f}
  };
  int librarySize = sizeof(myLibrary) / sizeof(struct Book);

  int option = 0;
  while (option != 4) {
    printf("********** Ebook Reader **********\n");
    printf("1) View library\n");
    printf("2) Add book to library\n");
    printf("3) Remove book from library\n");
    printf("4) Exit\n");
    printf("Enter an option (1-4): ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("********** Library **********\n");
        for (int i = 0; i < librarySize; i++) {
          printf("Book %d:\n", i + 1);
          printBook(&myLibrary[i]);
          printf("\n");
        }
        break;
      case 2:
        if (librarySize < 50) {
          printf("********** Add Book **********\n");
          printf("Enter the title: ");
          scanf("%s", &myLibrary[librarySize].title);
          printf("Enter the author: ");
          scanf("%s", &myLibrary[librarySize].author);
          printf("Enter the genre: ");
          scanf("%s", &myLibrary[librarySize].genre);
          printf("Enter the year: ");
          scanf("%d", &myLibrary[librarySize].year);
          printf("Enter the price: ");
          scanf("%f", &myLibrary[librarySize].price);
          librarySize++;
          printf("Book added to library!\n");
        } else {
          printf("Library is full. Cannot add more books.\n");
        }
        break;
      case 3:
        printf("********** Remove Book **********\n");
        printf("Enter the book number to remove (1-%d): ", librarySize);
        int bookToRemove = 0;
        scanf("%d", &bookToRemove);
        if (bookToRemove >= 1 && bookToRemove <= librarySize) {
          bookToRemove--;
          for (int i = bookToRemove; i < librarySize - 1; i++) {
            myLibrary[i] = myLibrary[i+1];
          }
          printf("Book removed from library!\n");
          librarySize--;
        } else {
          printf("Invalid book number.\n");
        }
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid option. Please enter a number from 1-4.\n");
        break;
    }
  }

  return 0;
}