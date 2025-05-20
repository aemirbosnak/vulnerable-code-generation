//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 100

struct Book {
    char title[MAX_TITLE_LEN];
    int pages;
    double price;
    char* content;
};

struct EbookReader {
    struct Book library[MAX_BOOKS];
    int num_books;
    struct Book* current_book;
};

void load_books(struct EbookReader* reader) {
    struct Book book1 = {"The Great Gatsby", 180, 10.99, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut in lobortis elit, ac pellentesque nisi. Ut in vestibulum justo. Vestibulum semper sodales quam in tempus. Nam molestie lacus vitae nisl consequat tempor. Sed velit tortor, sodales sed efficitur id, lobortis a lorem. Nullam dapibus massa sed cursus auctor. Vestibulum vitae turpis non mi auctor bibendum sed a augue. Curabitur malesuada interdum magna vitae bibendum. Donec euismod, nisl volutpat eleifend congue, neque sapien aliquet turpis, vitae commodo eros urna eget nulla. Nulla nec sapien bibendum, porttitor arcu vel, consequat nulla. Fusce tristique, sapien non porttitor bibendum, quam quam accumsan turpis, vel lobortis ligula quam sit amet est."};
    struct Book book2 = {"To Kill a Mockingbird", 240, 13.49, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris bibendum sapien eget lorem cursus elementum. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Phasellus tincidunt arcu eget neque egestas tristique. Fusce congue convallis ipsum quis laoreet. Pellentesque bibendum neque elit, et hendrerit purus feugiat a. Aliquam euismod sapien eros, quis maximus tortor vehicula sit amet. Donec lacinia luctus semper. Quisque tincidunt interdum enim, eu fermentum justo efficitur ut. Sed eget quam augue. Pellentesque in ipsum nulla."};
    reader->library[0] = book1;
    reader->library[1] = book2;
    reader->num_books = 2;
    reader->current_book = &reader->library[0];
}

void display_menu() {
    printf("1. View current book\n");
    printf("2. Next page\n");
    printf("3. Previous page\n");
    printf("4. Change book\n");
    printf("5. Exit\n");
}

void view_book(struct EbookReader* reader) {
    printf("Title: %s\n", reader->current_book->title);
    printf("Pages: %d\n", reader->current_book->pages);
    printf("Price: $%.2f\n\n", reader->current_book->price);
    printf("--------------------\n");
    printf("%s\n", reader->current_book->content);
    printf("--------------------\n");
}

void next_page(struct EbookReader* reader) {
    if (strlen(reader->current_book->content) > reader->current_book->pages) {
        reader->current_book->content += reader->current_book->pages;
    }
}

void prev_page(struct EbookReader* reader) {
    if (reader->current_book->content > reader->current_book->content - reader->current_book->pages) {
        reader->current_book->content -= reader->current_book->pages;
    }
}

void change_book(struct EbookReader* reader) {
    printf("Which book would you like to switch to?\n");
    for (int i = 0; i < reader->num_books; i++) {
        printf("%d. %s\n", i + 1, reader->library[i].title);
    }
    int choice;
    scanf("%d", &choice);
    reader->current_book = &reader->library[choice - 1];
}

int main() {
    struct EbookReader reader;
    load_books(&reader);

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_book(&reader);
                break;
            case 2:
                next_page(&reader);
                break;
            case 3:
                prev_page(&reader);
                break;
            case 4:
                change_book(&reader);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
    return 0;
}