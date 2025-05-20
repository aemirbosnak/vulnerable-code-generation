//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct {
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

// Function prototypes
void displayBooks(Book *books, int count);
void sortBooks(Book *books, int count, int option);
void swap(Book *a, Book *b);
int compareByTitle(const void *a, const void *b);
int compareByAuthor(const void *a, const void *b);
int compareByYear(const void *a, const void *b);
int compareByPrice(const void *a, const void *b);

// Main function
int main() {
    int n, option;

    // Ask the user for number of books
    printf("Enter the number of books: ");
    scanf("%d", &n);
    getchar(); // clear the newline character from input buffer

    // Dynamically allocate memory for books
    Book *books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read book details from user
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for book %d:\n", i+1);
        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0; // Remove newline

        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0; // Remove newline

        printf("Year of publication: ");
        scanf("%d", &books[i].year);
        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar(); // clear the newline character from input buffer
    }

    // Display the books
    printf("\nBooks before sorting:\n");
    displayBooks(books, n);

    // Ask the user for sorting option
    printf("\nChoose sorting option:\n");
    printf("1. Sort by Title\n");
    printf("2. Sort by Author\n");
    printf("3. Sort by Year of Publication\n");
    printf("4. Sort by Price\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &option);

    // Sort the books based on user's choice
    sortBooks(books, n, option);

    // Display the sorted books
    printf("\nBooks after sorting:\n");
    displayBooks(books, n);

    // Free the allocated memory
    free(books);
    return 0;
}

// Function to display the books
void displayBooks(Book *books, int count) {
    printf("%-30s %-30s %-20s %-10s\n", "Title", "Author", "Year", "Price");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-30s %-20d %-10.2f\n", books[i].title, books[i].author, books[i].year, books[i].price);
    }
}

// Function to sort books based on the selected option
void sortBooks(Book *books, int count, int option) {
    switch (option) {
        case 1:
            qsort(books, count, sizeof(Book), compareByTitle);
            break;
        case 2:
            qsort(books, count, sizeof(Book), compareByAuthor);
            break;
        case 3:
            qsort(books, count, sizeof(Book), compareByYear);
            break;
        case 4:
            qsort(books, count, sizeof(Book), compareByPrice);
            break;
        default:
            printf("Invalid option chosen!\n");
            break;
    }
}

// Comparison function for sorting by title
int compareByTitle(const void *a, const void *b) {
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

// Comparison function for sorting by author
int compareByAuthor(const void *a, const void *b) {
    return strcmp(((Book *)a)->author, ((Book *)b)->author);
}

// Comparison function for sorting by year
int compareByYear(const void *a, const void *b) {
    return ((Book *)a)->year - ((Book *)b)->year;
}

// Comparison function for sorting by price
int compareByPrice(const void *a, const void *b) {
    if (((Book *)a)->price < ((Book *)b)->price) return -1;
    if (((Book *)a)->price > ((Book *)b)->price) return 1;
    return 0;
}