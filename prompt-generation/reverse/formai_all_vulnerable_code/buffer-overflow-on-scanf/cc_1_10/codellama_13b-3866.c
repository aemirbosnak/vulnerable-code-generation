//Code Llama-13B DATASET v1.0 Category: Ebook reader ; Style: realistic
/*
 * ebook_reader.c
 * A simple ebook reader program in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the ebook information
typedef struct {
    char title[100];
    char author[100];
    char genre[100];
    char content[10000];
} Ebook;

// Function to display the ebook information
void display_ebook(Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Genre: %s\n", ebook.genre);
    printf("Content: %s\n", ebook.content);
}

// Function to search for an ebook by title
Ebook* search_ebook_by_title(Ebook* ebooks, int num_ebooks, char* title) {
    for (int i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            return &ebooks[i];
        }
    }
    return NULL;
}

// Function to search for an ebook by author
Ebook* search_ebook_by_author(Ebook* ebooks, int num_ebooks, char* author) {
    for (int i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].author, author) == 0) {
            return &ebooks[i];
        }
    }
    return NULL;
}

// Function to search for an ebook by genre
Ebook* search_ebook_by_genre(Ebook* ebooks, int num_ebooks, char* genre) {
    for (int i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].genre, genre) == 0) {
            return &ebooks[i];
        }
    }
    return NULL;
}

int main() {
    // Array of ebooks
    Ebook ebooks[5] = {
        {"The C Programming Language", "Dennis Ritchie", "Computer Science", "A classic book on programming."},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Fiction", "A classic novel."},
        {"To Kill a Mockingbird", "Harper Lee", "Fiction", "A classic novel."},
        {"The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", "A classic fantasy novel."},
        {"The Handmaid's Tale", "Margaret Atwood", "Fiction", "A dystopian novel."}
    };

    // Number of ebooks
    int num_ebooks = 5;

    // User input
    char user_input[100];
    printf("Enter a title, author, or genre to search for an ebook: ");
    scanf("%s", user_input);

    // Search for ebook by title
    Ebook* ebook = search_ebook_by_title(ebooks, num_ebooks, user_input);
    if (ebook != NULL) {
        display_ebook(*ebook);
        return 0;
    }

    // Search for ebook by author
    ebook = search_ebook_by_author(ebooks, num_ebooks, user_input);
    if (ebook != NULL) {
        display_ebook(*ebook);
        return 0;
    }

    // Search for ebook by genre
    ebook = search_ebook_by_genre(ebooks, num_ebooks, user_input);
    if (ebook != NULL) {
        display_ebook(*ebook);
        return 0;
    }

    // Ebook not found
    printf("Ebook not found.\n");
    return 1;
}