//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 500

// Structure to hold book information
struct Book {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
};

// List of books
struct Book library[MAX_BOOKS] = {
    {"The Adventures of C", "Once upon a time in a land of bytes and bits..."},
    {"C Programming for Cat Lovers", "A meowsterpiece of if statements and purrloops..."},
    {"The Great Catsby", "In my younger and more vulnerable years, my father gave me some advice..."},
    {"The Hitchhiker's Guide to Compiler Errors", "Don't panic! It’s just a missing semicolon!"},
    {"Gone with the Wind() {return NULL;}", "A drama filled with infinite loops and recursion..."}
};

// Function prototypes
void displayMenu();
void readBook(int choice);
void makeComment(const char *bookTitle);

int main() {
    int choice;

    printf("Welcome to the C E-book Reader!\n");
    printf("Where every book is just a click away... unless the books are hiding!\n");

    while (1) {
        displayMenu();
        printf("Choose a book to read (1-%d) or 0 to EXIT: ", MAX_BOOKS);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thanks for using our reader. Don’t forget to turn off the light!\n");
            break;
        } else if (choice < 1 || choice > MAX_BOOKS) {
            printf("Invalid choice! Choose wisely, young Padawan.\n");
        } else {
            readBook(choice - 1);
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== E-book Library ===\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
    printf("======================\n");
}

// Function to read a selected book
void readBook(int choice) {
    printf("\nReading: \"%s\"\n", library[choice].title);
    printf("%s\n\n", library[choice].content);
    makeComment(library[choice].title);
}

// Function to make random comments about the book (because why not?)
void makeComment(const char *bookTitle) {
    const char *comments[] = {
        "What a page-turner! If only my pages didn’t have such sticky fingers...",
        "This book really sucks, just like my vacuum cleaner on a Tuesday.",
        "Fantastic content! I would read this while stuck in traffic!",
        "Is it just me, or did this story require a compiler?",
        "I felt a great sense of existential crisis after reading this. Or was that the coffee?",
        "Who knew I’d be learning so much about pointers?!",
        "This is better than reality TV... but with fewer dramatic pauses.",
        "If I had a dollar for every time I laughed, I could afford to buy this book!",
        "Caution: May cause sudden urges to start coding!"
    };

    // Randomly select a comment
    int randomIndex = rand() % (sizeof(comments) / sizeof(comments[0]));
    printf("Comment: %s\n", comments[randomIndex]);
}