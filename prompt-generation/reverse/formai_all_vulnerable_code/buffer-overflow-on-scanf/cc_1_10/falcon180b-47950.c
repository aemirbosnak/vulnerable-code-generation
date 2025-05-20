//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MUSIC_ITEMS 100

typedef struct {
    char title[100];
    char author[100];
    int publication_year;
} Book;

typedef struct {
    char title[100];
    char artist[100];
    int release_year;
} MusicItem;

void add_book(Book* library, int num_books) {
    printf("Enter book title: ");
    scanf("%s", library[num_books].title);
    printf("Enter author name: ");
    scanf("%s", library[num_books].author);
    printf("Enter publication year: ");
    scanf("%d", &library[num_books].publication_year);
}

void display_book(const Book* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Publication Year: %d\n", book->publication_year);
}

void add_music_item(MusicItem* library, int num_items) {
    printf("Enter music item title: ");
    scanf("%s", library[num_items].title);
    printf("Enter artist name: ");
    scanf("%s", library[num_items].artist);
    printf("Enter release year: ");
    scanf("%d", &library[num_items].release_year);
}

void display_music_item(const MusicItem* item) {
    printf("Title: %s\n", item->title);
    printf("Artist: %s\n", item->artist);
    printf("Release Year: %d\n", item->release_year);
}

int main() {
    Book library[MAX_BOOKS];
    MusicItem music_library[MAX_MUSIC_ITEMS];

    int num_books = 0, num_music_items = 0;

    while (num_books < MAX_BOOKS && num_music_items < MAX_MUSIC_ITEMS) {
        printf("Press 1 to add a book or 2 to add a music item: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_book(library, num_books);
            num_books++;
        } else if (choice == 2) {
            add_music_item(music_library, num_music_items);
            num_music_items++;
        }
    }

    printf("Number of books: %d\n", num_books);
    printf("Number of music items: %d\n", num_music_items);

    return 0;
}