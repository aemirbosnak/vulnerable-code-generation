//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each book in the library
struct book {
    char title[100];
    int author;
    int year;
    char genre[50];
};

// Define a function to read in a book from a file
void read_book(FILE *file, struct book *book) {
    // Read the title
    fscanf(file, "%s", book->title);

    // Read the author
    fscanf(file, "%d", &book->author);

    // Read the year
    fscanf(file, "%d", &book->year);

    // Read the genre
    fscanf(file, "%s", book->genre);
}

// Define a function to print out a book
void print_book(struct book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %d\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Genre: %s\n", book.genre);
}

// Define a function to search for a book by title
struct book *search_book(struct book books[], int num_books, char *title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

// Define a function to add a book to the library
void add_book(struct book *books, int num_books, struct book new_book) {
    if (num_books == 0) {
        books[0] = new_book;
    } else {
        for (int i = 0; i < num_books; i++) {
            if (strcmp(new_book.title, books[i].title) > 0) {
                memmove(books + i + 1, books + i, (num_books - i) * sizeof(struct book));
                books[i] = new_book;
                return;
            }
        }
        books[num_books] = new_book;
    }
}

// Define a function to remove a book from the library
void remove_book(struct book *books, int num_books, char *title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            memmove(books + i, books + i + 1, (num_books - i - 1) * sizeof(struct book));
            num_books--;
            return;
        }
    }
}

// Define a function to search for a book by author
struct book *search_author(struct book books[], int num_books, int author) {
    for (int i = 0; i < num_books; i++) {
        if (books[i].author == author) {
            return &books[i];
        }
    }
    return NULL;
}

// Define a function to print out all books in the library
void print_all_books(struct book books[], int num_books) {
    for (int i = 0; i < num_books; i++) {
        print_book(books[i]);
    }
}

// Define a main function
int main() {
    // Create an array to hold the books in the library
    struct book books[100];
    int num_books = 0;

    // Open a file to read in the books
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read in each book from the file and add it to the library
    while (fscanf(file, "%s %d %d %s", books[num_books].title, &books[num_books].author, &books[num_books].year, books[num_books].genre) == 4) {
        num_books++;
    }

    // Close the file
    fclose(file);

    // Print out all the books in the library
    printf("Library Contents:\n");
    print_all_books(books, num_books);

    // Search for a book by title
    char title[100];
    printf("Enter a book title to search for: ");
    fgets(title, 100, stdin);
    struct book *found_book = search_book(books, num_books, title);
    if (found_book!= NULL) {
        printf("Found book: %s\n", found_book->title);
    } else {
        printf("Book not found.\n");
    }

    // Add a new book to the library
    struct book new_book;
    printf("Enter the title of the new book: ");
    fgets(new_book.title, 100, stdin);
    printf("Enter the author of the new book: ");
    scanf("%d", &new_book.author);
    printf("Enter the year of the new book: ");
    scanf("%d", &new_book.year);
    printf("Enter the genre of the new book: ");
    fgets(new_book.genre, 50, stdin);
    add_book(books, num_books, new_book);
    printf("Book added successfully.\n");

    // Remove a book from the library
    printf("Enter the title of the book to remove: ");
    fgets(title, 100, stdin);
    remove_book(books, num_books, title);
    printf("Book removed successfully.\n");

    // Search for a book by author
    int author;
    printf("Enter the author of the book to search for: ");
    scanf("%d", &author);
    found_book = search_author(books, num_books, author);
    if (found_book!= NULL) {
        printf("Found book: %s\n", found_book->title);
    } else {
        printf("Book not found.\n");
    }

    // Free the memory used by the books array
    for (int i = 0; i < num_books; i++) {
        free(books[i].title);
        free(books[i].author);
        free(books[i].year);
        free(books[i].genre);
    }
    free(books);

    return 0;
}