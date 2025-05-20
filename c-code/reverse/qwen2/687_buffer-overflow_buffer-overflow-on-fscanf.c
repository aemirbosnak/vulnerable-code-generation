#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 256

typedef struct {
    char title[MAX_TITLE_LENGTH];
} Book;

int main() {
    FILE *file;
    char filename[100];
    int numBooks = 0;
    Book *books = NULL;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count number of books
    while (!feof(file)) {
        if (fgets(books[numBooks].title, MAX_TITLE_LENGTH, file) != NULL) {
            numBooks++;
        }
    }

    // Allocate memory for all books
    books = realloc(books, numBooks * sizeof(Book));
    if (books == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read all books into array
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < numBooks; i++) {
        fgets(books[i].title, MAX_TITLE_LENGTH, file);
        // Remove newline character if present
        size_t len = strlen(books[i].title);
        if (len > 0 && books[i].title[len - 1] == '\n') {
            books[i].title[len - 1] = '\0';
        }
    }

    fclose(file);

    // Search by title
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title to search: ");
    scanf("%s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            printf("Book found: %s\n", books[i].title);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    free(books);

    return EXIT_SUCCESS;
}
