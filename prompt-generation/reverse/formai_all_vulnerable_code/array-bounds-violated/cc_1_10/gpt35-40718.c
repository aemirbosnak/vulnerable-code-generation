//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

// Define struct for a book
struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* ebook; // pointer to ebook file path
};

int main() {
    struct Book library[MAX_BOOKS];
    int num_books = 0;

    // make a sample book object
    struct Book my_book = {"My Book Title", "My Author Name", 350, "my_book.ebook"};

    // add the sample book to the library
    library[num_books] = my_book;
    num_books++;

    // Welcome message
    printf("Welcome to the Ebook Reader Program.\n\n");

    // Menu options
    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1: View Library\n");
        printf("2: Add Book\n");
        printf("3: Read Book\n");
        printf("4: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // View Library
                printf("\nLibrary:\n");
                for (int i = 0; i < num_books; i++) {
                    printf("%d. %s by %s, %d pages\n", i+1, library[i].title, library[i].author, library[i].pages);
                }
                printf("\n");
                break;

            case 2:
                // Add Book
                printf("\nAdd Book:\n");

                // create a new book object
                struct Book new_book;

                printf("Enter the book title: ");
                scanf("%s", new_book.title);

                printf("Enter the author name: ");
                scanf("%s", new_book.author);

                printf("Enter the number of pages: ");
                scanf("%d", &new_book.pages);

                printf("Enter the ebook file path: ");
                char ebook_path[100];
                scanf("%s", ebook_path);
                new_book.ebook = malloc(strlen(ebook_path) + 1);
                strcpy(new_book.ebook, ebook_path);

                // add the new book to the library
                library[num_books] = new_book;
                num_books++;
                printf("\n");
                break;

            case 3:
                // Read Book
                printf("\nEnter the number of the book you want to read: ");
                int book_choice;
                scanf("%d", &book_choice);
                book_choice--;

                // open the ebook file
                FILE* ebook = fopen(library[book_choice].ebook, "r");

                if (ebook == NULL) {
                    printf("Error: Could not open ebook file.\n\n");
                } else {
                    // print out the ebook contents
                    printf("\n%s by %s\n\n", library[book_choice].title, library[book_choice].author);
                    char c = fgetc(ebook);
                    while (c != EOF) {
                        printf("%c", c);
                        c = fgetc(ebook);
                    }
                    printf("\n");

                    // close the ebook file
                    fclose(ebook);
                }
                break;

            case 4:
                // Exit
                printf("\nGoodbye.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    // free the ebook memory pointers
    for (int i = 0; i < num_books; i++) {
        free(library[i].ebook);
    }

    return 0;
}