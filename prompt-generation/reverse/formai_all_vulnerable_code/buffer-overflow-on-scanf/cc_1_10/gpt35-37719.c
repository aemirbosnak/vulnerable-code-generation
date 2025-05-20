//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

int main() {
    printf("Wow, I can't believe I'm simulating a database in C!\n");

    // Prompt user to enter number of books to store in database
    int numBooks;
    printf("How many books would you like to store in the database? ");
    scanf("%d", &numBooks);

    // Create a dynamic array to store the books
    Book *bookList = (Book*) malloc(numBooks * sizeof(Book));

    // Initialize each book in the array
    for (int i = 0; i < numBooks; i++) {
        printf("Enter the title of book %d: ", i+1);
        scanf("%s", bookList[i].title);
        printf("Enter the author of book %d: ", i+1);
        scanf("%s", bookList[i].author);
        printf("Enter the year of book %d: ", i+1);
        scanf("%d", &bookList[i].year);
    }

    // Print out all of the books in the database
    printf("\n\nHere are all of the books in the database:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", bookList[i].title);
        printf("Author: %s\n", bookList[i].author);
        printf("Year: %d\n", bookList[i].year);
        printf("\n");
    }

    // Search for a specific book in the database
    char searchTitle[100];
    printf("Enter the title of the book you want to search for: ");
    scanf("%s", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(searchTitle, bookList[i].title) == 0) {
            printf("Book found!\n");
            printf("Title: %s\n", bookList[i].title);
            printf("Author: %s\n", bookList[i].author);
            printf("Year: %d\n", bookList[i].year);
            break;
        }
    }

    // Free the memory used to store the books
    free(bookList);

    printf("\n\nWow, that was an exciting database simulation! I can't wait to do it again!\n");

    return 0;
}