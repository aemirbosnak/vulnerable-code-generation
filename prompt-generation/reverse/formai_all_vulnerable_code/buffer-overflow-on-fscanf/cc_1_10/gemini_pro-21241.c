//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
// Amidst the ruins of a forgotten world, a solitary wanderer stumbles upon a cache of forgotten knowledge.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the dust-covered metadata structures.
typedef struct {
    char name[256];
    char author[256];
    int year;
    int pages;
} BookData;

typedef struct {
    char title[512];
    int release_year;
    char director[256];
    int runtime;
} MovieData;

// Declare the ancient knowledge keeper.
void ExtractMetadata(FILE *fp, bool is_book) {
    if (fp == NULL) {
        printf("The ancient scrolls have crumbled to dust.\n");
        return;
    }

    // Unravel the fragmented book's lore.
    if (is_book) {
        BookData book;
        fscanf(fp, "%s %s %d %d", book.name, book.author, &book.year, &book.pages);

        printf("\nUnveiling the secrets of a forgotten tome:\n");
        printf("Title: %s\n", book.name);
        printf("Author: %s\n", book.author);
        printf("Year of Publication: %d\n", book.year);
        printf("Pages: %d\n", book.pages);
    }
    // Decipher the cryptic film's legacy.
    else {
        MovieData movie;
        fscanf(fp, "%s %d %s %d", movie.title, &movie.release_year, movie.director, &movie.runtime);

        printf("\nExcavating the remnants of a cinematic relic:\n");
        printf("Title: %s\n", movie.title);
        printf("Release Year: %d\n", movie.release_year);
        printf("Director: %s\n", movie.director);
        printf("Runtime: %d minutes\n", movie.runtime);
    }
}

int main() {
    // Seek out the forgotten scrolls.
    FILE *book_fp = fopen("apocalyptic_tome.txt", "r");
    FILE *movie_fp = fopen("wasteland_flick.txt", "r");

    // Embark on the journey of knowledge extraction.
    ExtractMetadata(book_fp, true);
    ExtractMetadata(movie_fp, false);

    // Close the gateways to the ancient knowledge.
    fclose(book_fp);
    fclose(movie_fp);

    return 0;
}