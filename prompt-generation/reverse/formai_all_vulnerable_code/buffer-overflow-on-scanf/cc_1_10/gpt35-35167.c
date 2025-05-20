//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int pages;
};

// function to display book details
void displayBook(struct Book book) {
    printf("\nTitle: %s", book.title);
    printf("\nAuthor: %s", book.author);
    printf("\nNumber of Pages: %d\n", book.pages);
}

// function to read books from file and return as array of structs
struct Book* readBooksFromFile(char* filename, int* size) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nError: Failed to open file %s\n", filename);
        *size = 0;
        return NULL;
    }
    char line[300];
    int count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        count++;
    }
    *size = count / 3;
    rewind(fp);
    struct Book* books = (struct Book*) malloc((*size) * sizeof(struct Book));
    int i;
    for (i = 0; i < (*size); i++) {
        fgets(line, sizeof(line), fp);
        strcpy(books[i].title, line);
        strtok(books[i].title, "\n");
        fgets(line, sizeof(line), fp);
        strcpy(books[i].author, line);
        strtok(books[i].author, "\n");
        fgets(line, sizeof(line), fp);
        books[i].pages = atoi(line);
    }
    fclose(fp);
    return books;
}

int main() {
    printf("Welcome to the Ebook Reader!\n");
    printf("Please enter the name of the file containing the list of books: ");

    char filename[100];
    scanf("%s", filename);

    int size;
    struct Book* books = readBooksFromFile(filename, &size);

    printf("\nTotal number of books: %d\n", size);

    int i;
    for (i = 0; i < size; i++) {
        displayBook(books[i]);
    }

    free(books);

    return 0;
}