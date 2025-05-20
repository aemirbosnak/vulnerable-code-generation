//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[100];
    char author[100];
    int pages;
    float price;
};

int main() {
    struct book library[100];
    FILE *fp;
    char filename[100], booktitle[100], choice;
    int i, num_books = 0, book_found = 0;

    printf("Welcome to Ebook Reader!\n");

    // Load books from file
    printf("Please enter the name of the file you'd like to load from: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while (fscanf(fp, "%99s %99s %d %f", library[num_books].title, library[num_books].author, &library[num_books].pages, &library[num_books].price) == 4) {
        num_books++;
    }
    fclose(fp);
    printf("%d books loaded from file.\n", num_books);

    // Book search loop
    do {
        book_found = 0;
        printf("Please enter a book title: ");
        scanf("%99s", booktitle);
        for (i = 0; i < num_books; i++) {
            if (strcmp(booktitle, library[i].title) == 0) {
                printf("Title: %s\nAuthor: %s\nPages: %d\nPrice: %.2f\n", library[i].title, library[i].author, library[i].pages, library[i].price);
                book_found = 1;
                break;
            }
        }
        if (!book_found) {
            printf("Book not found\n");
        }
        printf("Would you like to search for another book? (y/n)");
        scanf(" %c", &choice);
    } while (choice == 'y');

    return 0;
}