//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100 // Maximum number of books that can be stored

// A structure to represent a book
struct book {
    char title[50];
    char author[50];
    int year_published;
    char publisher[50];
    float price;
};

// A function to display the details of a book
void display_book(struct book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year Published: %d\n", b.year_published);
    printf("Publisher: %s\n", b.publisher);
    printf("Price: $%.2f\n", b.price);
}

// A function to check if a book exists in the library
int is_book_present(struct book library[], int num_books, char title[50]) {
    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0)
            return i;
    }
    return -1;
}

int main() {
    int num_books = 0; // Number of books currently in library
    struct book library[MAX_BOOKS]; // Array to store all the books in the library
    int choice; // User's choice
    char title[50]; // Title of the book

    do {
        printf("\n1. Add a book to the library\n");
        printf("2. Display details of a book\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_books == MAX_BOOKS) {
                    printf("Sorry, the library is full!\n");
                }
                else {
                    printf("\nEnter the details of the book:\n");
                    printf("Title: ");
                    scanf("%s", library[num_books].title);
                    printf("Author: ");
                    scanf("%s", library[num_books].author);
                    printf("Year Published: ");
                    scanf("%d", &library[num_books].year_published);
                    printf("Publisher: ");
                    scanf("%s", library[num_books].publisher);
                    printf("Price: ");
                    scanf("%f", &library[num_books].price);
                    printf("\nBook added to the library!\n");
                    num_books++;
                }
                break;
          
            case 2:
                printf("\nEnter the title of the book: ");
                scanf("%s", title);
                int index = is_book_present(library, num_books, title);
                if (index == -1) {
                    printf("\nSorry, book not found in the library!\n");
                }
                else {
                    printf("\nDetails of the book:\n");
                    display_book(library[index]);
                }
                break;

            case 3:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
        
    } while (choice != 3);

    return 0;
}