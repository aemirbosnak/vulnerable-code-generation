//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} Book;

Book books[MAX_BOOKS];

int num_books = 0;

void add_book(char* title, char* author, char* file_name) {
    if (num_books == MAX_BOOKS) {
        printf("Library is full, cannot add more books\n");
        return;
    }
    else {
        strcpy(books[num_books].title, title);
        strcpy(books[num_books].author, author);
        strcpy(books[num_books].file_name, file_name);
        num_books++;
        printf("Book added successfully\n");
    }
}

void remove_book(char* title) {
    int i, j, found = 0;
    for (i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            found = 1;
            for (j = i; j < num_books-1; j++) {
                books[j] = books[j+1];
            }
            num_books--;
            printf("Book removed successfully\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found in library\n");
    }
}

void display_books() {
    int i;
    if (num_books == 0) {
        printf("Library is empty\n");
        return;
    }
    printf("\nTitle\t\tAuthor\t\tFile Name\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < num_books; i++) {
        printf("%s\t\t%s\t\t%s\n", books[i].title, books[i].author, books[i].file_name);
    }
}

void read_book(char* file_name) {
    FILE* fp;
    char ch;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error reading file: %s\n", file_name);
        return;
    }
    printf("\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

void search_book(char* title) {
    int i, found = 0;
    for (i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            found = 1;
            printf("\nTitle: %s\nAuthor: %s\n", books[i].title, books[i].author);
            read_book(books[i].file_name);
            break;
        }
    }
    if (!found) {
        printf("Book not found in library\n");
    }
}

void menu() {
    char choice, title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH], file_name[MAX_FILE_NAME_LENGTH];
    printf("\n\nE-Book Library\n");
    printf("---------------------------------------\n");
    printf("1. Add book\n");
    printf("2. Remove book\n");
    printf("3. Display books\n");
    printf("4. Search book\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    switch (choice) {
        case '1': // Add book
            printf("\nEnter book title: ");
            fflush(stdin);
            fgets(title, MAX_TITLE_LENGTH, stdin);
            title[strlen(title)-1] = '\0'; // remove trailing newline character
            printf("Enter author name: ");
            fflush(stdin);
            fgets(author, MAX_AUTHOR_LENGTH, stdin);
            author[strlen(author)-1] = '\0'; // remove trailing newline character
            printf("Enter file name: ");
            fflush(stdin);
            fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
            file_name[strlen(file_name)-1] = '\0'; // remove trailing newline character
            add_book(title, author, file_name);
            break;
        case '2': // Remove book
            printf("\nEnter book title: ");
            fflush(stdin);
            fgets(title, MAX_TITLE_LENGTH, stdin);
            title[strlen(title)-1] = '\0'; // remove trailing newline character
            remove_book(title);
            break;
        case '3': // Display books
            display_books();
            break;
        case '4': // Search book
            printf("\nEnter book title: ");
            fflush(stdin);
            fgets(title, MAX_TITLE_LENGTH, stdin);
            title[strlen(title)-1] = '\0'; // remove trailing newline character
            search_book(title);
            break;
        case '5': // Exit
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}

int main() {
    while (1) {
        menu();
    }
    return 0;
}