//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_WORDS 1000
#define MAX_CHAPTERS 50

typedef struct {
    char title[50];
    char author[50];
    char genre[50];
    int num_chapters;
    char chapters[MAX_CHAPTERS][MAX_WORDS];
} Book;

void add_book(Book* library, int num_books) {
    printf("Enter book title: ");
    scanf("%s", library[num_books].title);

    printf("Enter book author: ");
    scanf("%s", library[num_books].author);

    printf("Enter book genre: ");
    scanf("%s", library[num_books].genre);

    printf("Enter number of chapters: ");
    scanf("%d", &library[num_books].num_chapters);

    for (int i = 0; i < library[num_books].num_chapters; i++) {
        printf("Enter chapter %d: ", i + 1);
        scanf("%s", library[num_books].chapters[i]);
    }
}

void display_book(Book* library, int num_books) {
    printf("Title: %s\n", library[num_books].title);
    printf("Author: %s\n", library[num_books].author);
    printf("Genre: %s\n", library[num_books].genre);
    printf("Number of chapters: %d\n", library[num_books].num_chapters);

    for (int i = 0; i < library[num_books].num_chapters; i++) {
        printf("Chapter %d: %s\n", i + 1, library[num_books].chapters[i]);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int num_books = 0;

    while (num_books < MAX_BOOKS) {
        printf("Do you want to add a book? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            add_book(library, num_books);
            num_books++;
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    int choice;
    printf("Which book do you want to read? (0-9): ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < num_books) {
        display_book(library, choice);
    } else {
        printf("Invalid book choice.\n");
    }

    return 0;
}