//FormAI DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of books and chapters per book
#define MAX_BOOKS 10
#define MAX_CHAPTERS 20

// Define struct for each chapter
typedef struct {
    char title[50];
    char text[1000];
} chapter_t;

// Define struct for each book
typedef struct {
    char title[50];
    int num_chapters;
    chapter_t chapters[MAX_CHAPTERS];
} book_t;

int main() {
    // Declare variables
    int num_books, book_choice, chapter_choice;
    book_t books[MAX_BOOKS];

    // Prompt user for number of books
    printf("How many books do you want to add? (Max: %d)\n", MAX_BOOKS);
    scanf("%d", &num_books);

    // Initialize each book
    for (int i = 0; i < num_books; i++) {
        // Prompt user for title of book
        printf("Enter title of book %d: ", i+1);
        scanf("%s", books[i].title);
        
        // Prompt user for number of chapters in book
        printf("How many chapters does %s have? (Max: %d)\n", books[i].title, MAX_CHAPTERS);
        scanf("%d", &books[i].num_chapters);

        // Initialize each chapter
        for (int j = 0; j < books[i].num_chapters; j++) {
            // Prompt user for title of chapter
            printf("Enter title of Chapter %d in %s: ", j+1, books[i].title);
            scanf("%s", books[i].chapters[j].title);

            // Prompt user for text of chapter
            printf("Enter text for %s in %s: ", books[i].chapters[j].title, books[i].title);
            scanf(" %[^\n]s", books[i].chapters[j].text);
        }
    }

    // Display list of books
    printf("\n=== List of Books ===\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s\n", i+1, books[i].title);
    }

    // Prompt user for choice of book
    printf("\nEnter the book number to read: ");
    scanf("%d", &book_choice);

    // Display list of chapters for chosen book
    printf("\n=== List of Chapters for %s ===\n", books[book_choice-1].title);
    for (int i = 0; i < books[book_choice-1].num_chapters; i++) {
        printf("%d. %s\n", i+1, books[book_choice-1].chapters[i].title);
    }

    // Prompt user for choice of chapter
    printf("\nEnter the chapter number to read: ");
    scanf("%d", &chapter_choice);

    // Display title and text of chosen chapter
    printf("\n=== %s ===\n", books[book_choice-1].chapters[chapter_choice-1].title);
    printf("%s\n", books[book_choice-1].chapters[chapter_choice-1].text);

    return 0;
}