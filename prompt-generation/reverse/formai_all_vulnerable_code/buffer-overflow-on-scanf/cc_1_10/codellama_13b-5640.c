//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char genre[50];
    int year;
    char filename[50];
} Book;

void display_menu();
void add_book(Book *books, int *count);
void delete_book(Book *books, int *count);
void search_book(Book *books, int count);
void sort_books(Book *books, int count);
void save_books(Book *books, int count);
void load_books(Book *books, int *count);

int main() {
    Book books[100];
    int count = 0;

    load_books(books, &count);

    display_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &count);
                break;
            case 2:
                delete_book(books, &count);
                break;
            case 3:
                search_book(books, count);
                break;
            case 4:
                sort_books(books, count);
                break;
            case 5:
                save_books(books, count);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("1. Add a book\n");
    printf("2. Delete a book\n");
    printf("3. Search for a book\n");
    printf("4. Sort books\n");
    printf("5. Save books to file\n");
    printf("6. Exit\n");
}

void add_book(Book *books, int *count) {
    if (*count >= 100) {
        printf("The book list is full.\n");
        return;
    }

    printf("Enter the title of the book: ");
    scanf("%s", books[*count].title);

    printf("Enter the author of the book: ");
    scanf("%s", books[*count].author);

    printf("Enter the genre of the book: ");
    scanf("%s", books[*count].genre);

    printf("Enter the year of publication: ");
    scanf("%d", &books[*count].year);

    printf("Enter the file name of the book: ");
    scanf("%s", books[*count].filename);

    (*count)++;
}

void delete_book(Book *books, int *count) {
    int index;

    printf("Enter the index of the book to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        books[i] = books[i + 1];
    }

    (*count)--;
}

void search_book(Book *books, int count) {
    char search_title[50];
    int found = 0;

    printf("Enter the title of the book to search: ");
    scanf("%s", search_title);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, search_title) == 0) {
            printf("Book found: %s by %s\n", books[i].title, books[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void sort_books(Book *books, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(books[i].title, books[j].title) > 0) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void save_books(Book *books, int count) {
    FILE *fp = fopen("books.dat", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %s %d %s\n", books[i].title, books[i].author, books[i].genre, books[i].year, books[i].filename);
    }

    fclose(fp);
}

void load_books(Book *books, int *count) {
    FILE *fp = fopen("books.dat", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    *count = 0;

    while (fscanf(fp, "%s %s %s %d %s", books[*count].title, books[*count].author, books[*count].genre, &books[*count].year, books[*count].filename) == 5) {
        (*count)++;
    }

    fclose(fp);
}