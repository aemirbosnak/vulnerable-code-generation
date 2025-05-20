//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char publisher[100];
    int year;
} Book;

void print_book_info(Book book) {
    printf("\nTitle: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("Year: %d\n", book.year);
}

int main() {
    Book library[10];
    int num_books = 0;

    // Read books from a file and add them to the library array
    FILE *fp = fopen("library.txt", "r");
    if (fp != NULL) {
        char line[300];
        while (fgets(line, sizeof(line), fp) != NULL) {
            // Split the line into title, author, publisher, and year
            char *token;
            token = strtok(line, ",");
            strcpy(library[num_books].title, token);
            token = strtok(NULL, ",");
            strcpy(library[num_books].author, token);
            token = strtok(NULL, ",");
            strcpy(library[num_books].publisher, token);
            token = strtok(NULL, ",");
            library[num_books].year = atoi(token);
            num_books++;
        }
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
    }

    // Print all the books in the library
    printf("Library contents:\n");
    for (int i = 0; i < num_books; i++) {
        print_book_info(library[i]);
    }

    // Prompt the user to select a book to read
    int selection = -1;
    while (selection < 0 || selection >= num_books) {
        printf("\nEnter the number of the book you want to read (0-%d): ", num_books - 1);
        scanf("%d", &selection);
    }

    // Open the book file and print its contents
    char book_filename[200];
    sprintf(book_filename, "%s.txt", library[selection].title);
    fp = fopen(book_filename, "r");
    if (fp != NULL) {
        printf("\n%s by %s\n\n", library[selection].title, library[selection].author);
        char line[300];
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
    }

    return 0;
}