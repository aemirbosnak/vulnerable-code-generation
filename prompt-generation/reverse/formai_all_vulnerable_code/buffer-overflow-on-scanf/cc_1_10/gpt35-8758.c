//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    char title[MAX_STRING_LENGTH];
    char author[MAX_STRING_LENGTH];
    char filename[MAX_STRING_LENGTH];
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

// Function to load books from file
void load_books(char* filename) {
    FILE *fp = fopen(filename, "r");

    if (fp != NULL) {
        char line[MAX_STRING_LENGTH];
        while (fgets(line, sizeof(line), fp) != NULL) {
            char *token;
            char *title;
            char *author;
            char *file;

            token = strtok(line, ",");
            title = token;

            token = strtok(NULL, ",");
            author = token;

            token = strtok(NULL, ",");
            file = token;

            strcpy(books[num_books].title, title);
            strcpy(books[num_books].author, author);
            strcpy(books[num_books].filename, file);

            num_books++;
        }
        fclose(fp);
    } else {
        printf("Error opening file %s\n", filename);
    }
}

// Function to display list of books
void display_books() {
    int i;
    printf("\nList of Books:\n");
    for (i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }
}

// Function to read book from file
void read_book(char* filename) {
    FILE *fp = fopen(filename, "r");

    if (fp != NULL) {
        char line[MAX_STRING_LENGTH];
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }
        fclose(fp);
    } else {
        printf("Error opening file %s\n", filename);
    }
}

int main() {
    char selected_book[MAX_STRING_LENGTH];
    int choice;

    load_books("books.txt");

    do {
        display_books();

        printf("Please select a book to read (q to exit): ");
        scanf("%s", selected_book);

        if (selected_book[0] == 'q' && strlen(selected_book) == 1) {
            break;
        }

        choice = atoi(selected_book);
        if (choice <= num_books && choice > 0) {
            read_book(books[choice-1].filename);
        } else {
            printf("Invalid selection\n");
        }
    } while (1);

    return 0;
}