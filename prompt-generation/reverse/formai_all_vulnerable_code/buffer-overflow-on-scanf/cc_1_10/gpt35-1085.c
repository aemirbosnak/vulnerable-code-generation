//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    char title[MAX_TITLE_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter book title: ");
    scanf("%s", title);
    strcpy(library[num_books].title, title);
    printf("Enter file name: ");
    scanf("%s", file_name);
    strcpy(library[num_books].file_name, file_name);
    num_books++;
}

void list_books() {
    if (num_books == 0) {
        printf("Library is empty.\n");
        return;
    }
    printf("Books in library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s\n", i+1, library[i].title);
    }
}

void read_book(char* title) {
    char file_name[MAX_FILE_NAME_LENGTH];
    for (int i = 0; i < num_books; i++) {
        if (strcmp(title, library[i].title) == 0) {
            strcpy(file_name, library[i].file_name);
            FILE* fp = fopen(file_name, "r");
            if (fp == NULL) {
                printf("Error opening file.\n");
                return;
            }
            printf("%s:\n", title);
            char line[100];
            while (fgets(line, 100, fp) != NULL) {
                printf("%s", line);
            }
            fclose(fp);
            return;
        }
    }
    printf("Book not found in library.\n");
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    do {
        printf("Choose an option: \n");
        printf("1. Add a book\n");
        printf("2. List all books\n");
        printf("3. Read a book\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                printf("Enter book title: ");
                scanf("%s", title);
                read_book(title);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}