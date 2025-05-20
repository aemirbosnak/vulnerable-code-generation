//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define GENRE_LENGTH 50

// Structure to represent a book
typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char genre[GENRE_LENGTH];
    int year;
} Book;

// Function to add a book
void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book newBook;
    printf("Enter book title: ");
    getchar();  // To consume newline from previous input
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // Remove newline

    printf("Enter book genre: ");
    fgets(newBook.genre, GENRE_LENGTH, stdin);
    newBook.genre[strcspn(newBook.genre, "\n")] = 0;  // Remove newline

    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);

    library[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

// Function to search for a book by title
void searchByTitle(Book library[], int count, const char *title) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            printf("Book found: %s by %s (%d), Genre: %s\n", library[i].title, library[i].author, library[i].year, library[i].genre);
        }
    }
    if (!found) {
        printf("No book found with title: %s\n", title);
    }
}

// Function to search for a book by author
void searchByAuthor(Book library[], int count, const char *author) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].author, author) == 0) {
            found = 1;
            printf("Book found: %s by %s (%d), Genre: %s\n", library[i].title, library[i].author, library[i].year, library[i].genre);
        }
    }
    if (!found) {
        printf("No book found by author: %s\n", author);
    }
}

// Function to search for a book by genre
void searchByGenre(Book library[], int count, const char *genre) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].genre, genre) == 0) {
            found = 1;
            printf("Book found: %s by %s (%d), Genre: %s\n", library[i].title, library[i].author, library[i].year, library[i].genre);
        }
    }
    if (!found) {
        printf("No book found in genre: %s\n", genre);
    }
}

// Main function
int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;
    
    while (1) {
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search Book by Title\n");
        printf("3. Search Book by Author\n");
        printf("4. Search Book by Genre\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2: {
                char title[TITLE_LENGTH];
                printf("Enter book title to search: ");
                getchar();  // To consume newline
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline
                searchByTitle(library, count, title);
                break;
            }
            case 3: {
                char author[AUTHOR_LENGTH];
                printf("Enter author to search: ");
                getchar();  // To consume newline
                fgets(author, AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = 0;  // Remove newline
                searchByAuthor(library, count, author);
                break;
            }
            case 4: {
                char genre[GENRE_LENGTH];
                printf("Enter genre to search: ");
                getchar();  // To consume newline
                fgets(genre, GENRE_LENGTH, stdin);
                genre[strcspn(genre, "\n")] = 0;  // Remove newline
                searchByGenre(library, count, genre);
                break;
            }
            case 5:
                printf("Exiting the Library System.\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}