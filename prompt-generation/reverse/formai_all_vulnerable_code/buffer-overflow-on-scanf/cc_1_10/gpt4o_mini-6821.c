//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_CONTENT 1000
#define BUFFER_SIZE 256

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char content[MAX_CONTENT];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Sorry, no room left in the virtual bookshelf! It's stuffed like a Thanksgiving turkey!\n");
        return;
    }
    printf("Enter the title of the book (max %d characters): ", MAX_TITLE - 1);
    fgets(library[book_count].title, MAX_TITLE, stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = 0; // Remove newline

    printf("Enter the author of the book (max %d characters): ", MAX_AUTHOR - 1);
    fgets(library[book_count].author, MAX_AUTHOR, stdin);
    library[book_count].author[strcspn(library[book_count].author, "\n")] = 0; // Remove newline

    printf("Enter the content of the book (max %d characters): ", MAX_CONTENT - 1);
    fgets(library[book_count].content, MAX_CONTENT, stdin);
    library[book_count].content[strcspn(library[book_count].content, "\n")] = 0; // Remove newline

    book_count++;
    printf("Congratulations! You've added '%s' by %s to the virtual bookshelf!\n", library[book_count - 1].title, library[book_count - 1].author);
}

void view_books() {
    if (book_count == 0) {
        printf("Your virtual bookshelf is emptier than my bank account. Please add some books!\n");
        return;
    }

    printf("\n--- Your Virtual Bookshelf ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book %d: '%s' by %s\n", i + 1, library[i].title, library[i].author);
    }
}

void read_book() {
    int choice;
    if (book_count == 0) {
        printf("You can't read anything because your bookshelf is empty! Go add a book!\n");
        return;
    }

    printf("Which book would you like to read? (1-%d): ", book_count);
    scanf("%d", &choice);
    getchar(); // Clear newline
    if (choice < 1 || choice > book_count) {
        printf("Er... That's not a valid book number. Try again, there's no magic wand here!\n");
        return;
    }
    
    printf("\nReading '%s' by %s:\n\n", library[choice - 1].title, library[choice - 1].author);
    printf("%s\n", library[choice - 1].content);
}

void display_menu() {
    printf("\n--- Welcome to the Funny C Ebook Reader ---\n");
    printf("1. Add a new book\n");
    printf("2. View all books\n");
    printf("3. Read a book\n");
    printf("4. Exit the ebook reader\n");
    printf("Please choose an option: ");
}

int main() {
    int option;
    do {
        display_menu();
        scanf("%d", &option);
        getchar(); // Clear newline
        switch (option) {
            case 1: 
                add_book();
                break;
            case 2: 
                view_books();
                break;
            case 3: 
                read_book();
                break;
            case 4:
                printf("Thanks for using the Funny C Ebook Reader! Stay silly!\n");
                break;
            default:
                printf("Oops! That's not a choice, but ah-ha! Gotta laugh!\n");
        }
    } while (option != 4);

    return 0;
}