//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prepare your virtual bookshelf!
typedef struct book {
    char title[100];
    char author[100];
    int pages;
    int read;
} book;

// Let's build our library
book library[] = {
    {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 184, 0},
    {"1984", "George Orwell", 328, 0},
    {"Brave New World", "Aldous Huxley", 268, 0},
    {"To Kill a Mockingbird", "Harper Lee", 324, 0},
    {"The Great Gatsby", "F. Scott Fitzgerald", 180, 0}
};

// How many books are we rocking?
int num_books = sizeof(library) / sizeof(book);

// Get ready to dive into a new world!
void read_book(book *b) {
    printf("Get ready for an adventure! You're now reading \"%s\" by %s!\n", b->title, b->author);
    b->read = 1;
}

// Show off your literary prowess!
void show_library() {
    printf("Behold, your illustrious library:\n\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. \"%s\" by %s (%d pages, ", i + 1, library[i].title, library[i].author, library[i].pages);
        library[i].read ? printf("read)\n") : printf("unread)\n");
    }
}

// Let's get this party started!
int main() {
    int choice;

    // Welcome to the literary extravaganza!
    printf("Welcome to your very own digital bookshelf! Get ready to embark on a literary adventure!\n\n");

    while (1) {
        // Show off your literary collection
        show_library();

        // What literary delights do you have in mind?
        printf("\nWhich book would you like to read (1-%d, or 0 to quit): ", num_books);
        scanf("%d", &choice);

        // Time to flip those pages!
        if (choice >= 1 && choice <= num_books) {
            read_book(&library[choice - 1]);
        }
        // Farewell, bookworm!
        else if (choice == 0) {
            printf("May your literary adventures continue! Goodbye!\n");
            return 0;
        }
        // Oops, invalid input!
        else {
            printf("Invalid choice. Please choose a book between 1 and %d, or 0 to quit.\n", num_books);
        }
    }

    return 0;
}