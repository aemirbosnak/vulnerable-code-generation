//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MUSIC_ITEMS 100

struct book {
    char title[50];
    char author[50];
    int isbn;
    int quantity;
};

struct music_item {
    char title[50];
    char artist[50];
    char genre[20];
    int isrc;
    int quantity;
};

void add_book(struct book* books, int n) {
    printf("Enter book title: ");
    scanf("%s", books[n].title);
    printf("Enter book author: ");
    scanf("%s", books[n].author);
    printf("Enter book ISBN: ");
    scanf("%d", &books[n].isbn);
    printf("Enter book quantity: ");
    scanf("%d", &books[n].quantity);
}

void display_books(struct book* books, int n) {
    printf("\nBook details:\n");
    printf("ISBN\tTitle\tAuthor\tQuantity\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%d\n", books[i].isbn, books[i].title, books[i].author, books[i].quantity);
    }
}

void add_music_item(struct music_item* items, int n) {
    printf("Enter music item title: ");
    scanf("%s", items[n].title);
    printf("Enter music item artist: ");
    scanf("%s", items[n].artist);
    printf("Enter music item genre: ");
    scanf("%s", items[n].genre);
    printf("Enter music item ISRC: ");
    scanf("%d", &items[n].isrc);
    printf("Enter music item quantity: ");
    scanf("%d", &items[n].quantity);
}

void display_music_items(struct music_item* items, int n) {
    printf("\nMusic item details:\n");
    printf("ISRC\tTitle\tArtist\tGenre\tQuantity\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%s\t%d\n", items[i].isrc, items[i].title, items[i].artist, items[i].genre, items[i].quantity);
    }
}

int main() {
    struct book books[MAX_BOOKS];
    int n_books = 0;
    struct music_item items[MAX_MUSIC_ITEMS];
    int n_items = 0;

    while (1) {
        printf("\n1. Add book\n2. Display books\n3. Add music item\n4. Display music items\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (n_books == MAX_BOOKS) {
                printf("Cannot add more books.\n");
            } else {
                add_book(books, n_books);
                n_books++;
            }
            break;

        case 2:
            display_books(books, n_books);
            break;

        case 3:
            if (n_items == MAX_MUSIC_ITEMS) {
                printf("Cannot add more music items.\n");
            } else {
                add_music_item(items, n_items);
                n_items++;
            }
            break;

        case 4:
            display_music_items(items, n_items);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}